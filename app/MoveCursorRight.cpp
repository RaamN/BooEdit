#include "MoveCursorRight.hpp"

void MoveCursorRight::execute(EditorModel &e)
{
	e.CursorRight();
	line = e.retPrevLine();
	col = e.retPrevCol();
}

void MoveCursorRight::undo(EditorModel &e)
{
	e.setCursorPrev(line, col);
}