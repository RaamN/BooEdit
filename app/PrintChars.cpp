#include "PrintChars.hpp"

PrintChars::PrintChars(char c)
:character{c}
{
}
void PrintChars::execute(EditorModel &e)
{
	e.printChar(character);
}

void PrintChars::undo(EditorModel &e)
{
	e.deleteChar();
}