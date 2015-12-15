#ifndef MOVEHOME_HPP
#define MOVEHOME_HPP
#include "Command.hpp"

class MoveHome: public Command
{
	virtual void execute(EditorModel &e);

	virtual void undo(EditorModel &e);

private:
	
	int line;
	int col;
};

#endif // MOVEHOME_HPP