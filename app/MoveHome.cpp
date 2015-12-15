#include "MoveHome.hpp"

void MoveHome::execute(EditorModel &e)
{
	e.cursorHome();
	line = e.retPrevLine();
	col = e.retPrevCol();
}

void MoveHome::undo(EditorModel &e)
{
	e.setCursorPrev(line, col);
}