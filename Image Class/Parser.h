#pragma once

#include "PPM.h"
#include <string>
#include <sstream>

enum class CommandID
{
	Save = 0,
	New,
	Circle,
	Rectangle,
	Pixel,
	Color,
	Error
};

struct CommandData
{
	CommandID ID;
	int x{}, y{}, width{}, height{}, radius{};
	RGB rgb;
	std::string filename = "";
};

class Parser
{
private:
	RGB color = { 0,0,0 };

	// getters
	CommandData getSaveData(const std::string& command);
	CommandData getRectangleData(const std::string& command);
	CommandData getCircleData(const std::string& command);
	CommandData getPixelData(const std::string& command);
	CommandData getNewImageData(const std::string& command);
	CommandData getColorData(const std::string& command);
	int* getData(const std::string& command, int elements);

	// setters
	void setColorData(const RGB& rgb);
public:
	Parser() {}
	bool execute(const std::string& command, PPM*& image);
	CommandData Parse(std::string command);
};

