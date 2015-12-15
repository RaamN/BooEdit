#ifndef MOVECURSORLEFT_CPP
#define MOVECURSORLEFT_CPP

#include "Command.hpp"

class MoveCursorLeft: public Command
{
	public:

		virtual void execute(EditorModel &e);

		virtual void undo(EditorModel &e);
	
	private:
		int line;
		int col;
};

#endif //MOVECURSORLEFT_CPP