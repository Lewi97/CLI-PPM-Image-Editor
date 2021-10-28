#include "Parser.h"

// pixel x y r g b
CommandData Parser::getPixelData(const std::string& command)
{
	int* elements = getData(command, 5);

	CommandData data;
	data.ID = CommandID::Pixel;
	data.x = elements[0];
	data.y = elements[1];
	data.rgb = { elements[2], elements[3],elements[4] };

	delete[] elements;

	return data;
}

// save filename
CommandData Parser::getSaveData(const std::string& command)
{
	int counter = 0;
	while (command[counter] != ' ')counter++;
	std::string filename = command.substr(++counter);

	CommandData data;
	data.ID = CommandID::Save;
	data.filename = filename;

	return data;
}

// circle x y radius r g b
CommandData Parser::getCircleData(const std::string& command)
{
	int* elements = getData(command, 6);

	CommandData data;
	data.ID = CommandID::Circle;
	data.x = elements[0];
	data.y = elements[1];
	data.radius = elements[2];
	data.rgb = { elements[3],elements[4],elements[5] };

	return data;
}

// rectangle x y w h r g b
CommandData Parser::getRectangleData(const std::string& command)
{
	int* elements = getData(command, 7);

	CommandData data;
	data.ID = CommandID::Rectangle;
	data.x = elements[0];
	data.y = elements[1];
	data.width = elements[2];
	data.height = elements[3];
	data.rgb = { elements[4] ,elements[5] ,elements[6] };

	delete[] elements;

	return data;
}

// new w h
CommandData Parser::getNewImageData(const std::string& command)
{
	int* elements = getData(command, 2);

	CommandData data;
	data.ID = CommandID::New;
	data.width = elements[0];
	data.height = elements[1];

	delete[] elements;

	return data;
}

int* Parser::getData(const std::string& command, int elements)
{
	int* e = new int[elements];
	std::stringstream stream;
	int counter = 0, reserve;

	while (command[counter] != ' ') counter++;

	for (int i = 0; i < elements - 1; i++)
	{
		reserve = ++counter;
		while (command[counter] != ' ') counter++;
		stream.str(command.substr(reserve, counter - reserve));
		stream >> e[i];
		stream.clear();
	}

	reserve = ++counter;
	stream.str(command.substr(reserve));
	stream >> e[elements - 1];

	return e;
}

CommandData Parser::Parse(std::string command)
{
	CommandData data;

	int firstLetter = command[0];

	switch (firstLetter)
	{
	case 's':
		data = getSaveData(command);
		break;
	case 'n':
		data = getNewImageData(command);
		break;
	case 'c':
		data = getCircleData(command);
		break;
	case 'r':
		data = getRectangleData(command);
		break;
	case 'p':
		data = getPixelData(command);
		break;
	default:
		data.ID = CommandID::Error;
		break;
	}

	return data;
}

bool Parser::execute(const std::string& command, PPM*& image)
{
	CommandData data = Parse(command);

	switch (data.ID)
	{
	case CommandID::Pixel:      image->drawPixel(data.x, data.y, data.rgb); break;
	case CommandID::Rectangle:  image->drawRectangle(data.x, data.y, data.width, data.height, data.rgb); break;
	case CommandID::Circle:     image->drawCircle(data.x, data.y, data.radius, data.rgb); break;
	case CommandID::Save:       image->finalize(data.filename.c_str()); break;
	case CommandID::Error:		return false;
	case CommandID::New:
		delete image;
		image = new PPM(data.width, data.height);
		break;
	}

	return true;
}