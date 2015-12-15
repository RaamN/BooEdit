// EditorModel.cpp
//
// ICS 45C Fall 2015
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class
//
//Author: Raam Nachiappan
//Student ID: 45618246
//

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <sstream>
#include <string>


EditorModel::EditorModel()
:cursorLineNumber{1}, cursorColumnNumber{1}, lineNumber{1}, backUp{' '}, backUpText(" "), error{" "}, prevLine{1}, prevColumn{1}
{
	defaultLine.push_back("");
}

int EditorModel::cursorLine() const
{
    return cursorLineNumber;
}

int EditorModel::cursorColumn() const
{
    return cursorColumnNumber;
}

int EditorModel::lineCount() const
{
    return lineNumber;
}

char EditorModel::backUpChar()
{
	return backUp;
}

std::string EditorModel::backUpLine()
{
	return backUpText;
}

int EditorModel::lineLength(std::string line) 
{
	return line.length();
}

std::string EditorModel::currentLine()
{
	return defaultLine.at(cursorLine() - 1);
}

int EditorModel::retPrevLine()
{
	return prevLine;
}

int EditorModel::retPrevCol()
{
	return prevColumn;
}

void EditorModel::CursorRight()
{
	if(cursorLine() < lineCount() && (lineLength(currentLine()) < cursorColumn()))
	{
		prevColumn = cursorColumn();
		prevLine = cursorLine();
		cursorColumnNumber = 1;
		cursorLineNumber++;
	}
	else if(cursorColumn() < lineLength(currentLine()) + 1)
	{
		prevColumn = cursorColumn();
		prevLine = cursorLine();
		cursorColumnNumber++;
	}
	else
	{
		throw EditorException("Line is already at the end");
	}
}

void EditorModel::CursorLeft()
{
	if(cursorColumn() == 1 && cursorLine() > 1)
	{
		prevColumn = cursorColumn();
		prevLine = cursorLine();
		cursorLineNumber--;
		cursorColumnNumber = lineLength(currentLine()) + 1;
	}
	else if(cursorColumn() > 1)
	{
		prevColumn = cursorColumn();
		prevLine = cursorLine();
		cursorColumnNumber--;
	}
	else
	{
		throw EditorException("Line is already at the beginning");
	}
}

void EditorModel::CursorUp()
{
	if(cursorLine() > 1 && cursorColumn() > lineLength(currentLine()))
	{
		prevColumn = cursorColumn();
		prevLine = cursorLine();
		cursorLineNumber--;
		cursorColumnNumber = lineLength(currentLine()) + 1;
	}
	else if(cursorLine() > 1)
	{
		prevColumn = cursorColumn();
		prevLine = cursorLine();
		cursorLineNumber--;
	}
	else
	{
		throw EditorException("Line is already at the top");
	}
}

void EditorModel::CursorDown()
{
	if(cursorLine() < lineCount() && cursorColumn() > lineLength(currentLine()))
	{
		prevColumn = cursorColumn();
		prevLine = cursorLine();
		cursorLineNumber++;
		cursorColumnNumber = lineLength(currentLine()) + 1;
	}
	else if(cursorLine() < lineCount())
	{
		prevColumn = cursorColumn();
		prevLine = cursorLine();
		cursorLineNumber++;
	}
	else
	{
		throw EditorException("Line is already at the bottom");
	}
}

void EditorModel::cursorHome()
{
	prevColumn = cursorColumn();
	prevLine = cursorLine();
	cursorColumnNumber = 1;
}

void EditorModel::cursorEnd()
{
	prevColumn = cursorColumn();
	prevLine = cursorLine();
	std::string line;
	line = currentLine();
	cursorColumnNumber = lineLength(line) + 1;
}

void EditorModel::setCursorPrev(int line, int col)
{
	cursorLineNumber = line;
	cursorColumnNumber = col;
}

void EditorModel::printChar(char c)
{
	std::stringstream ss;
	std::string s;
	if (c != ' ')
	{
		ss << c;
		ss >> s;
	}
	else
	{
		s = c;
	}
	defaultLine.at(cursorLine() - 1) = currentLine().insert(cursorColumn() - 1, s);
	cursorColumnNumber += 1;
}

void EditorModel::deleteChar()
{
	std::string text;
	if(cursorColumn() == 1 && cursorLine() != 1)
	{
		text = defaultLine.at(cursorLine() - 2);
		cursorColumnNumber = lineLength(text) + 1;
		defaultLine.at(cursorLine() - 2) += currentLine();
		lineNumber--;
		cursorLineNumber--;
	}
	else if(cursorColumn() != 1)
	{
		std::string text = currentLine();
		backUp = text.at(cursorColumn() - 2);
		defaultLine.at(cursorLine() - 1) = currentLine().erase(cursorColumn() - 2, 1);

		cursorColumnNumber--;
	}
	else if(cursorColumn() == 1 && cursorLine() == 1)
	{
		throw EditorException("Line is already at the beginning");
	}
	else
	{
		throw EditorException("");
	}
}

void EditorModel::addNewLine()
{
	std::string line;
	std::string text1;
	
	defaultLine.push_back("");
	line = currentLine();
	text1 = line.substr(cursorColumn() - 1);
	defaultLine.at(cursorLine() - 1) = line.substr(0, cursorColumn() - 1);
	defaultLine.insert(defaultLine.begin() + cursorLine(), text1);
	
	lineNumber++;
	cursorLineNumber++;
	cursorColumnNumber = 1;
}

void EditorModel::deleteLine()
{
	if(cursorColumn() < lineLength(currentLine()) + 2 && cursorLine() == 1 && lineLength(currentLine()) > 0)
	{
		defaultLine.push_back("");
		backUpText = currentLine();
		defaultLine.erase(defaultLine.begin() + cursorLine() - 1);
		
		cursorLineNumber = 1;
		cursorColumnNumber = 1;
	}
	else if(cursorColumn() < lineLength(currentLine()) + 2 && cursorLine() > 1)
	{
		backUpText = currentLine();
		defaultLine.erase(defaultLine.begin() + cursorLine() - 1);
		
		lineNumber--;
		cursorLineNumber--;
		cursorColumnNumber = lineLength(currentLine()) + 1;
	}
	else
	{
		throw EditorException("");
	}
}

void EditorModel::undoDeleteLine(std::string text)
{
	prevLine = cursorLine();
	prevColumn = cursorColumn();
	defaultLine.insert(defaultLine.begin() + cursorLine() - 1, text);
	lineNumber++;
}

const std::string& EditorModel::line(int lineNumber) const
{
	return defaultLine.at(lineNumber - 1);
}

const std::string& EditorModel::currentErrorMessage() const
{
    return error;
}

void EditorModel::setErrorMessage(const std::string& errorMessage)
{
	error = errorMessage;
}

void EditorModel::clearErrorMessage()
{
	error.clear();
}

