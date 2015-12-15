#ifndef MOVEEND_HPP
#define MOVEEND_HPP
#include "Command.hpp"

class MoveEnd: public Command
{
	virtual void execute(EditorModel &e);

	virtual void undo(EditorModel &e);
private:
	int line;
	int col;
};

#endif // MOVEEND_HPP