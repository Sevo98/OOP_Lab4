#include <iostream>
#include "Song.h"
#include "Genre.h"
#include "CheckInput.h"
using namespace std;

void Song::ReadSongFromConsole()
{
	setlocale(LC_ALL, "ru");
	cout << "������� �������� �����: ";
	getline(cin, this->N�me);

	bool CheckMinute = false;
	while (CheckMinute == false)
	{
		try
		{
			cout << "\n������� ������� ����� ������ �����: ";
			int minutes;
			CheckInput::CheckInputInt(&minutes);
			if (minutes < 0)
			{
				throw exception("���������� ����� �� ������ ���� �������������! ��������� ����.");
			}
			this->Minute = minutes;
			CheckMinute = true;
		}
		catch (const std::exception&)
		{
			cout << "���������� ����� �� ������ ���� �������������! ��������� ����." << endl;
		}
	}

	bool CheckSecond = false;
	while (CheckSecond == false)
	{
		try
		{
			cout << "\n������� ������� ������ ������ �����: ";
			int seconds;
			CheckInput::CheckInputInt(&seconds);
			if (seconds < 0 || seconds > 2020)
			{
				throw exception("���������� ������ � ����� ������ ���� �� 0 �� 60! ��������� ����.");
			}
			this->Second = seconds;
			CheckSecond = true;
		}
		catch (const std::exception&)
		{
			cout << "���������� ������ � ����� ������ ���� �� 0 �� 60! ��������� ����." << endl;
		}
	}
	cin.ignore(32767, '\n');

	cout << "�������� ���� �����:" << endl;
	cout << "1. ���" << endl;
	cout << "2. �����" << endl;
	cout << "3. ���-���" << endl;
	cout << "4. ���" << endl;
	cout << "5. ����" << endl;
	cout << "6. ��������" << endl;
	string genre;

	bool CheckGenre = false;
	while (CheckGenre == false)
	{
		try
		{
			getline(cin, genre);
			if (genre == "1" || genre == "���" || genre == "���")
			{
				this->Genre = Rock;
			}
			else if (genre == "2" || genre == "�����" || genre == "�����" || genre == "������" || genre == "������")
			{
				this->Genre = Metall;
			}

			else if (genre == "3" || genre == "���-���" || genre == "���-���" || genre == "��� ���" || genre == "��� ���")
			{
				this->Genre = HipHop;
			}

			else if (genre == "4" || genre == "���" || genre == "���" || genre == "���" || genre == "���")
			{
				this->Genre = Rap;
			}

			else if (genre == "5" || genre == "����" || genre == "����")
			{
				this->Genre = Jazz;
			}

			else if (genre == "6" || genre == "��������" || genre == "��������")
			{
				this->Genre = Classic;
			}
			else
			{
				throw exception("������ ���� �� ������! ��������� ����.");
			}
			CheckGenre = true;
		}
		catch (const std::exception&)
		{
			cout << "������ ���� �� ������! ��������� ����." << endl;
		}
	}
}

void Song::WriteSongFromConsole()
{
	setlocale(LC_ALL, "ru");

	cout << " ����: " << this->N�me << " ����: ";
	if (this->Genre == Genre::Rock)
	{
		cout << "��� ";
	}
	else if (this->Genre == Genre::Metall)
	{
		cout << "������ ";
	}
	else if (this->Genre == Genre::HipHop)
	{
		cout << "���-��� ";
	}
	else if (this->Genre == Genre::Rap)
	{
		cout << "��� ";
	}
	else if (this->Genre == Genre::Jazz)
	{
		cout << "���� ";
	}
	else if (this->Genre == Genre::Classic)
	{
		cout << "�������� ";
	}

	cout << "�����������������: " << this->Minute << ":" << this->Second << endl;
}
