#include "DeleteChars.hpp"

void DeleteChars::execute(EditorModel &e)
{
	col = e.cursorColumn();
	if(col == 1)
		e.deleteChar();	
	else
	{
		e.deleteChar();
		backUp = e.backUpChar();
	}
}

void DeleteChars::undo(EditorModel &e)
{
	if(col != 1)
		e.printChar(backUp);
	else
		e.addNewLine();
}