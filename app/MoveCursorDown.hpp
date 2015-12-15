#ifndef MOVECURSORDOWN_HPP
#define MOVECURSORDOWN_HPP
#include "Command.hpp"

class MoveCursorDown: public Command
{
	virtual void execute(EditorModel &e);

	virtual void undo(EditorModel &e);
private:
	int line;
	int col;
};

#endif // MOVECURSORDOWN_HPP