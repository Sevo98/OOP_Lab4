#pragma once
#include <string>
#include "Song.h"
#include "Album.h"


class Band
{
	string Name;
	string History;
	int countMembers;
	string* Members;
	int countAlbums;
	Album* Albums;
	Song searchSongResult;
	Album searchAlbumResult;
	int allSongsCount = 0;
	Song* AllSongsStorage;
	int AllRockCount = 0, AllMetallCount = 0, AllHipHopCount = 0, AllRapCount = 0, AllJazzCount = 0, AllClassicCount = 0;
	Song* RockStorage;
	Song* MetallStorage;
	Song* HipHopStorage;
	Song* RapStorage;
	Song* JazzStorage;
	Song* ClassicStorage;

public:
	void ReadBandFromConsole();
	void WriteBandFromConsole();
	Song* FindSong(string songTitle);
	Album* FindAlbum(Song* song);
	void GetAllSongs();
	void GetAllGenreSongs(Genre findingGenre);

	void DemoBand();
};

