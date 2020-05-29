#pragma once
#include "Song.h"
#include <string>
using namespace std;

class Album
{
public:
	string Name;
	int Year;
	Song* Songs;
	int countSong = 0;
	int RockCount = 0, MetallCount = 0, HipHopCount = 0, RapCount = 0, JazzCount = 0, ClassicCount = 0;
	void ReadAlbumFromConsole();
	void WriteAlbumFromConsole();
};

