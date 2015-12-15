#include "MoveCursorDown.hpp"

void MoveCursorDown::execute(EditorModel &e)
{
	e.CursorDown();
	line = e.retPrevLine();
	col = e.retPrevCol();
}

void MoveCursorDown::undo(EditorModel &e)
{
	e.setCursorPrev(line, col);
}