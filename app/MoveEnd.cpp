#include "MoveEnd.hpp"

void MoveEnd::execute(EditorModel &e)
{
	e.cursorEnd();
	line = e.retPrevLine();
	col = e.retPrevCol();
}

void MoveEnd::undo(EditorModel &e)
{
	e.setCursorPrev(line, col);
}