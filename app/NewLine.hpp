#ifndef NEWLINE_HPP
#define NEWLINE_HPP
#include "Command.hpp"

class NewLine: public Command
{
	virtual void execute(EditorModel &e);

	virtual void undo(EditorModel &e);
};

#endif //NEWLINE_HPP