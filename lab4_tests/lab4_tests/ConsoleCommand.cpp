#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "ConsoleCommand.h"
#include "Circle.h"
#include "LineSegment.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "SolidShape.h"
#include "Triangle.h"

using namespace std;

string const Error_Incorrect_Argument = "Incorrect argument";
string const Error_Incorrect_Number_Of_Arguments = "Incorrect number of arguments";
string const Error_Incorrect_Shape = "Incorrect shape";

unique_ptr<CShape> CreateLineSegment(vector<string> command)
{
	if (command.size() == 6)
	{
		try
		{
			return make_unique<CLineSegment>(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), command[5]);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument(Error_Incorrect_Argument);
		}
	}
	else
	{
		throw invalid_argument(Error_Incorrect_Number_Of_Arguments);
	}
}

unique_ptr<CShape> CreateTriangle(vector<string> command)
{
	if (command.size() == 9)
	{
		try
		{
			return make_unique<CTriangle>(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), CPoint(stod(command[5]), stod(command[6])), command[7], command[8]);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument(Error_Incorrect_Argument);
		}
	}
	else
	{
		throw invalid_argument(Error_Incorrect_Number_Of_Arguments);
	}
}

unique_ptr<CShape> CreateRectangle(vector<string> command)
{
	if (command.size() == 7)
	{
		try
		{
			return make_unique<CRectangle>(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), stod(command[4]), command[5], command[6]);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument(Error_Incorrect_Argument);
		}
	}
	else
	{
		throw invalid_argument(Error_Incorrect_Number_Of_Arguments);
	}
}

unique_ptr<CShape> CreateCircle(vector<string> command)
{
	if (command.size() == 6)
	{
		try
		{
			return make_unique<CCircle>(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), command[4], command[5]);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument(Error_Incorrect_Argument);
		}
	}
	else
	{
		throw invalid_argument(Error_Incorrect_Number_Of_Arguments);
	}
}

bool AreaCompare(unique_ptr<IShape> const& firstShape, unique_ptr<IShape> const& secondShape)
{
	return firstShape->GetArea() < secondShape->GetArea();
}

bool PerimeterCompare(unique_ptr<IShape> const& firstShape, unique_ptr<IShape> const& secondShape)
{
	return firstShape->GetPerimeter() < secondShape->GetPerimeter();
}


vector<string> parsing(string commandLine)
{
	vector<string> arr;
	if (commandLine.empty())
	{
		return arr;
	}
	string delimiter(" ");
	size_t prev = 0;
	size_t next;
	size_t delta = delimiter.length();

	while ((next = commandLine.find(delimiter, prev)) != string::npos) {
		string tmp = commandLine.substr(prev, next - prev);
		cout << tmp << endl;
		arr.push_back(commandLine.substr(prev, next - prev));
		prev = next + delta;
	}
	string tmp = commandLine.substr(prev);
	cout << tmp << endl;
	arr.push_back(commandLine.substr(prev));
	return arr;
}

void CConsoleCommand::DoCommand(istream& commands)
{
	string commandLine;
	vector<string> command;
	while (getline(commands, commandLine))
	{
		try
		{
			command = parsing(commandLine);

			if (command.empty())
			{
				break;
			}

			if (command[0] == "LineSegment")
			{
				m_shapes.push_back(CreateLineSegment(command));
			}
			else if (command[0] == "Triangle")
			{
				m_shapes.push_back(CreateTriangle(command));
			}
			else if (command[0] == "Rectangle")
			{
				m_shapes.push_back(CreateRectangle(command));
			}
			else if (command[0] == "Circle")
			{
				m_shapes.push_back(CreateCircle(command));
			}
			else
			{
				throw invalid_argument(Error_Incorrect_Shape);
			}
		}
		catch (invalid_argument const& e)
		{
			cout << e.what() << endl;
		}
	}
}

vector<unique_ptr<IShape>>::const_iterator CConsoleCommand::GetShapeWithMaxArea() const
{
	if (!m_shapes.empty())
	{
		return max_element(m_shapes.begin(), m_shapes.end(), AreaCompare);
	}
	return m_shapes.end();
}

vector<unique_ptr<IShape>>::const_iterator CConsoleCommand::GetShapeWithMinPerimeter() const
{
	if (!m_shapes.empty())
	{
		return min_element(m_shapes.begin(), m_shapes.end(), PerimeterCompare);
	}
	return m_shapes.end();
}

string CConsoleCommand::GetShapeInfo(vector<unique_ptr<IShape>>::const_iterator shape) const
{
	if (shape == m_shapes.end())
	{
		return "";
	}
	string result;
	result = (*shape)->ToString();
	return result;
}