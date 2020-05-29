#include <iostream>
#include "Band.h"
#include "CheckInput.h"
using namespace std;

void Band::ReadBandFromConsole()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите название группы: ";
	getline(cin, this->Name);
	cout << "Введите краткое описание, историю группы:" << endl;
	getline(cin, this->History);

	bool CheckCountMembers = false;
	while (CheckCountMembers == false)
	{
		try
		{
			cout << "Введите количество участников группы: ";
			int count;
			CheckInput::CheckInputInt(&count);
			if (count <= 0)
			{
				throw exception("Участников не может быть меньше одного! Повторите ввод.");
			}
			this->countMembers = count;
			CheckCountMembers = true;
		}
		catch (const std::exception&)
		{
			cout << "Участников не может быть меньше одного! Повторите ввод." << endl;
		}
	}
	cin.ignore(32767, '\n');

	this->Members = new string[this->countMembers];
	for (int i = 0; i < this->countMembers; i++)
	{
		cout << "Введите имя " << i + 1 << "-го участника: ";
		getline(cin, this->Members[i]);
	}

	bool CheckCountAlbums = false;
	while (CheckCountAlbums == false)
	{
		try
		{
			cout << "Введите количество альбомов группы: ";
			int count;
			CheckInput::CheckInputInt(&count);
			if (count < 0)
			{
				throw exception("Количество не может быть меньше 0! Повторите ввод.");
			}
			this->countAlbums = count;
			CheckCountAlbums = true;
		}
		catch (const std::exception&)
		{
			cout << "Количество не может быть меньше 0! Повторите ввод." << endl;
		}
	}
	cin.ignore(32767, '\n');

	this->Albums = new Album[this->countAlbums];
	for (int i = 0; i < this->countAlbums; i++)
	{
		cout << "Введите данные " << i + 1 << "-го альбома:" << endl;
		this->Albums[i].ReadAlbumFromConsole();
	}
}

void Band::WriteBandFromConsole()
{
	cout << "Название группы: " << this->Name << endl;
	cout << "Краткая история группы:\n" << this->History << endl;
	cout << "Группа состоит из ";
	if (this->countMembers == 1)
	{
		cout << "одного человека: " << this->Members[0] << endl;
	}
	else
	{
		cout << this->countMembers << " человек:" << endl;
		for (int i = 0; i < this->countMembers; i++)
		{
			cout << i + 1 << " - " << this->Members[i] << endl;
		}
	}

	cout << "Группа имеет ";
	if (this->countAlbums == 1)
	{
		cout << "один альбом: " << endl;
		this->Albums[0].WriteAlbumFromConsole();
	}
	else
	{
		cout << this->countAlbums << " альбомов:" << endl;
		for (int i = 0; i < this->countAlbums; i++)
		{
			this->Albums[i].WriteAlbumFromConsole();
		}
	}

	for (int i = 0; i < this->countAlbums; i++)
	{
		this->AllRockCount = this->AllRockCount + this->Albums[i].RockCount;
		this->AllMetallCount = this->AllMetallCount + this->Albums[i].MetallCount;
		this->AllHipHopCount = this->AllHipHopCount + this->Albums[i].HipHopCount;
		this->AllRapCount = this->AllRapCount + this->Albums[i].RapCount;
		this->AllJazzCount = this->AllJazzCount + this->Albums[i].JazzCount;
		this->AllClassicCount = this->AllClassicCount + this->Albums[i].ClassicCount;
	}
}

Song* Band::FindSong(string songTitle)
{
	for (int i = 0; i < this->countAlbums; i++)
	{
		for (int j = 0; j < this->Albums[i].countSong; j++)
		{
			if (songTitle == this->Albums[i].Songs[j].Nаme)
			{
				this->searchSongResult = this->Albums[i].Songs[j];
				return &this->searchSongResult;
			}
		}
	}
	return nullptr;
}

Album* Band::FindAlbum(Song* song)
{
	for (int i = 0; i < this->countAlbums; i++)
	{
		for (int j = 0; j < this->Albums[i].countSong; j++)
		{
			if (song->Nаme == this->Albums[i].Songs[j].Nаme)
			{
				this->searchAlbumResult = this->Albums[i];
				return &this->searchAlbumResult;
			}
		}
	}
	return nullptr;
}

void Band::GetAllSongs()
{
	int g = 0;
	for (int i = 0; i < this->countAlbums; i++)
	{
		for (int j = 0; j < this->Albums[i].countSong; j++)
		{
			this->AllSongsStorage[g] = this->Albums[i].Songs[j];
			g++;
		}
	}
}

void Band::GetAllGenreSongs(Genre findingGenre)
{
	int rockCount = 0;
	int metallCount = 0;
	int hiphopCount = 0;
	int rapCount = 0;
	int jazzCount = 0;
	int classicCount = 0;
	for (int i = 0; i < this->allSongsCount; i++)
	{
		if (this->AllSongsStorage[i].Genre == Rock)
		{
			this->RockStorage[rockCount] = this->AllSongsStorage[i];
			rockCount++;
		}

		if (this->AllSongsStorage[i].Genre == Metall)
		{
			this->MetallStorage[metallCount] = this->AllSongsStorage[i];
			metallCount++;
		}

		if (this->AllSongsStorage[i].Genre == HipHop)
		{
			this->HipHopStorage[hiphopCount] = this->AllSongsStorage[i];
			hiphopCount++;
		}

		if (this->AllSongsStorage[i].Genre == Rap)
		{
			this->RapStorage[rapCount] = this->AllSongsStorage[i];
			rapCount++;
		}

		if (this->AllSongsStorage[i].Genre == Jazz)
		{
			this->JazzStorage[jazzCount] = this->AllSongsStorage[i];
			jazzCount++;
		}

		if (this->AllSongsStorage[i].Genre == Classic)
		{
			this->ClassicStorage[classicCount] = this->AllSongsStorage[i];
			classicCount++;
		}
	}
	//поиск рока
	if (findingGenre == Rock && this->AllRockCount != 0)
	{
		for (int i = 0; i < this->AllRockCount; i++)
		{
			this->RockStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Rock && this->AllRockCount == 0)
	{
		cout << "Песни в жанре Рок не найдены" << endl;
	}
	//поиск металла
	if (findingGenre == Metall && this->AllMetallCount != 0)
	{
		for (int i = 0; i < this->AllMetallCount; i++)
		{
			this->MetallStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Metall && this->AllMetallCount == 0)
	{
		cout << "Песни в жанре Металл не найдены" << endl;
	}
	//поиск хип-хопа
	if (findingGenre == HipHop && this->AllHipHopCount != 0)
	{
		for (int i = 0; i < this->AllHipHopCount; i++)
		{
			this->HipHopStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == HipHop && this->AllHipHopCount == 0)
	{
		cout << "Песни в жанре Хип-хоп не найдены" << endl;
	}
	//поиск рэпа
	if (findingGenre == Rap && this->AllRapCount != 0)
	{
		for (int i = 0; i < this->AllRapCount; i++)
		{
			this->RapStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Rap && this->AllRapCount == 0)
	{
		cout << "Песни в жанре Рэп не найдены" << endl;
	}
	//поиск джаза
	if (findingGenre == Jazz && this->AllJazzCount != 0)
	{
		for (int i = 0; i < this->AllJazzCount; i++)
		{
			this->JazzStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Jazz && this->AllJazzCount == 0)
	{
		cout << "Песни в жанре Джаз не найдены" << endl;
	}
	//поиск классики
	if (findingGenre == Classic && this->AllClassicCount != 0)
	{
		for (int i = 0; i < this->AllClassicCount; i++)
		{
			this->ClassicStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Classic && this->AllClassicCount == 0)
	{
		cout << "Песни в жанре Классика не найдены" << endl;
	}
}
