// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "MoveCursorRight.hpp"
#include "MoveCursorLeft.hpp"
#include "MoveCursorUp.hpp"
#include "MoveCursorDown.hpp"
#include "PrintChars.hpp"
#include "DeleteChars.hpp"
#include "NewLine.hpp"
#include "DeleteLine.hpp"
#include "MoveHome.hpp"
#include "MoveEnd.hpp"

// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
                case 'A':
                {
                    return Interaction::redo();
                }
                case 'D':
                {
                    Command *deleteLine = new DeleteLine;
                    return Interaction::command(deleteLine);
                }
                case 'H':
                {
                    Command *backspace = new DeleteChars;
                    return Interaction::command(backspace);
                }
                case 'I':
                {
                    Command *moveUp = new MoveCursorUp;
                    return Interaction::command(moveUp);
                }
                case 'J':
                {
                    Command *addLine = new NewLine;
                    return Interaction::command(addLine);
                }
                case 'K':
                {
                    Command *moveDown = new MoveCursorDown;
                    return Interaction::command(moveDown);
                }
                case 'M':
                {
                    Command *addLine = new NewLine;
                    return Interaction::command(addLine);
                }
                case 'O':
                {
                    Command *moveRight = new MoveCursorRight;
                    return Interaction::command(moveRight);
                }
                case 'P':
                {
                    Command *moveEnd = new MoveEnd;
                    return Interaction::command(moveEnd);
                }
                case 'U':
                {
                    Command *moveLeft = new MoveCursorLeft;
                    return Interaction::command(moveLeft);
                }
                case 'X':
                {
                    return Interaction::quit();
                }
                case 'Y':
                {
                    Command *moveHome = new MoveHome;
                    return Interaction::command(moveHome);
                }
                case 'Z':
                {
                    return Interaction::undo();
                }
            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly

            Command *printChar = new PrintChars(keypress.code());
            return Interaction::command(printChar);
        }
    }
}

