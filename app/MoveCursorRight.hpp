#ifndef MOVECURSORRIGHT_CPP
#define MOVECURSORRIGHT_CPP

#include "Command.hpp"

class MoveCursorRight: public Command
{
	public:
		
		virtual void execute(EditorModel &e);

		virtual void undo(EditorModel &e);

	private:
		int line;
		int col;
};

#endif //MOVECURSORRIGHT_CPP