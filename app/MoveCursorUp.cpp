#include "MoveCursorUp.hpp"

void MoveCursorUp::execute(EditorModel &e)
{
	e.CursorUp();
	line = e.retPrevLine();
	col = e.retPrevCol();
}

void MoveCursorUp::undo(EditorModel &e)
{
	e.setCursorPrev(line, col);
}