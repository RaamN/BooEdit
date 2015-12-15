// InteractionProcessor.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include <vector>
#include <iostream>

// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

std::vector<Command*> commandStack; //all commands and redos
std::vector<Command*> undoStack; //all undos

void InteractionProcessor::run()
{
    view.refresh();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            for(Command* commands: commandStack) delete commands;
            for(Command* undos: undoStack) delete undos;
            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if(commandStack.size() != 0)
            {
                try
                {
                    Command* command = commandStack.back();
                    command->undo(model);
                    model.clearErrorMessage();
                    undoStack.push_back(command);
                    commandStack.pop_back();

                }

                catch (EditorException& e)
                {
                    model.setErrorMessage(e.getReason());
                }

                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if(undoStack.size() != 0)
            {
                try
                {
                    Command* command = undoStack.back();
                    command->execute(model);
                    model.clearErrorMessage();
                    commandStack.push_back(command);
                    undoStack.pop_back();
                }

                catch (EditorException& e)
                {
                    model.setErrorMessage(e.getReason());
                }

                view.refresh();
            }
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                model.clearErrorMessage();
                commandStack.push_back(command);
            }

            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.
        }
    }
}

