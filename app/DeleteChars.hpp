#ifndef DELETECHARS_HPP
#define DELETECHARS_HPP
#include "Command.hpp"

class DeleteChars: public Command
{
	virtual void execute(EditorModel &e);

	virtual void undo(EditorModel &e);

private:
	char backUp;
	int col;
};
#endif //DELETECHARS_HPP