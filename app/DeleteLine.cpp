#include "DeleteLine.hpp"

void DeleteLine::execute(EditorModel &e)
{
	e.deleteLine();
	text1 = e.backUpLine();
}

void DeleteLine::undo(EditorModel &e)
{
	e.undoDeleteLine(text1);
}