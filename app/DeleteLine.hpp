#ifndef DELETELINE_HPP
#define DELETELINE_HPP
#include "Command.hpp"
#include <string>

class DeleteLine: public Command
{
	virtual void execute(EditorModel &e);

	virtual void undo(EditorModel &e);
private:
	std::string text1;
};

#endif // DELETELINE_HPP