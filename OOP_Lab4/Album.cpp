#include <iostream>
#include "Album.h"
#include "Genre.h"
#include "CheckInput.h"
using namespace std;

void Album::ReadAlbumFromConsole()
{
	setlocale(LC_ALL, "ru");
	cout << "������� �������� �������: ";
	getline(cin, this->Name);

	bool CheckYear = false;
	while (CheckYear == false)
	{
		try
		{
			cout << "������� ��� �������: ";
			int year;
			CheckInput::CheckInputInt(&year);
			if (year < 0 || year > 2020)
			{
				throw exception("������������ ��� �������! ��������� ����.");
			}
			this->Year = year;
			CheckYear = true;
		}
		catch (const std::exception&)
		{
			cout << "������������ ��� �������! ��������� ����." << endl;
		}
	}

	bool CheckCountSongs = false;
	while (CheckCountSongs == false)
	{
		try
		{
			cout << "������� ���������� ����� � �������: ";
			int count;
			CheckInput::CheckInputInt(&count);
			if (count < 0)
			{
				throw exception("���������� �� ����� ���� ������ 0! ��������� ����.");
			}
			this->countSong = count;
			CheckCountSongs = true;
		}
		catch (const std::exception&)
		{
			cout << "���������� �� ����� ���� ������ 0! ��������� ����." << endl;
		}
	}
	cin.ignore(32767, '\n');

	this->Songs = new Song[this->countSong];
	for (int i = 0; i < this->countSong; i++)
	{
		cout << "������� �������� ����� �" << i + 1 << ":" << endl;
		this->Songs[i].ReadSongFromConsole();
	}

	for (int i = 0; i < this->countSong; i++)
	{
		if (this->Songs[i].Genre == Rock)
		{
			this->RockCount++;
		}
		if (this->Songs[i].Genre == Metall)
		{
			this->MetallCount++;
		}
		if (this->Songs[i].Genre == HipHop)
		{
			this->HipHopCount++;
		}
		if (this->Songs[i].Genre == Rap)
		{
			this->RapCount++;
		}
		if (this->Songs[i].Genre == Jazz)
		{
			this->JazzCount++;
		}
		if (this->Songs[i].Genre == Classic)
		{
			this->ClassicCount++;
		}
	}
}

void Album::WriteAlbumFromConsole()
{
	cout << "������: " << this->Name << endl;
	cout << "��� �������: " << this->Year << endl;
	cout << "� ������ ������� ������ " << this->countSong << " ������:" << endl;

	for (int i = 0; i < this->countSong; i++)
	{
		cout << i + 1 << "-";
		this->Songs[i].WriteSongFromConsole();
	}
}
