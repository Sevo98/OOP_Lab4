#pragma once
#include <string>
#include "Genre.h"

using namespace std;

class Song
{
public:
	string Nàme;
	int Minute, Second;
	Genre Genre;
	void ReadSongFromConsole();
	void WriteSongFromConsole();
};

