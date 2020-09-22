#pragma once
#include <iostream>

class FileParser
{
public:
	FileParser(std::string path, std::string file);
	std::string parseChunk();
	void writeFile();

private:
	
};

