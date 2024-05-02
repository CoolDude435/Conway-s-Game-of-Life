#pragma once

#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

int mapWidth(std::string& mapFile);
int mapHeight(std::string& mapFile);
int indexOf(std::string& s,char c);
unsigned int randomNum(unsigned int ceiling);
bool fileExist(std::string& file);
