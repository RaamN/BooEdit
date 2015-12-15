#include "NewLine.hpp"

void NewLine::execute(EditorModel &e)
{
	e.addNewLine();
}

void NewLine::undo(EditorModel &e)
{
	e.deleteLine();
}
