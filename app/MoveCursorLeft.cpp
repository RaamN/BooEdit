#include "MoveCursorLeft.hpp"

void MoveCursorLeft::execute(EditorModel &e)
{
	e.CursorLeft();
	line = e.retPrevLine();
	col = e.retPrevCol();
}

void MoveCursorLeft::undo(EditorModel &e)
{
	e.setCursorPrev(line, col);
}