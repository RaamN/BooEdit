#ifndef MOVECURSORUP_HPP
#define MOVECURSORUP_HPP
#include "Command.hpp"

class MoveCursorUp: public Command
{
	virtual void execute(EditorModel &e);

	virtual void undo(EditorModel &e);
private:
	int line;
	int col;
};

#endif // MOVECURSORUP_HPP