#ifndef PRINTCHARS_HPP
#define PRINTCHARS_HPP
#include "Command.hpp"

class PrintChars: public Command
{
public:

	PrintChars(char c);

	virtual void execute(EditorModel &e);

	virtual void undo(EditorModel &e);
	
private:
	char character;
};
#endif //PRINTCHARS_HPP