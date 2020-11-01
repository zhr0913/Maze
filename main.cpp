#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
#include"Map.h"
#include<string>

using namespace std;

struct MazeMap Map;
int level = 0;

void Draw_Map();
void KeyboardEvent();
void SelectPosition();
void JudgeMap();

int main()
{
	JudgeMap();
	SelectPosition();
	while (1)
	{
		Draw_Map();
		KeyboardEvent();
	}
	//system("pause");
	return 0;
}

void Draw_Map()
{
	for (int i = 0; i < Map_H; i++)
	{
		for (int j = 0; j < Map_W; j++)
		{
			if (Map.Map[i][j] == 0)
				cout << "  ";
			if (Map.Map[i][j] == 1)
				cout << "¨€";
			if (Map.Map[i][j] == 2)
				cout << "P ";
			if (Map.Map[i][j] == 3)
				cout << "$ ";
		}
		cout << endl;
	}
	Map.Map[Map.y][Map.x] = 2;
	Sleep(30);
	system("cls");
}

void KeyboardEvent()
{
	char key;
	while (_kbhit())
	{
		key = _getch();
		/*if (ch == 'w' || ch == 's' || ch == 'a' || ch == 'd')
			ch = key;*/
		if (key == 'w')
		{
			Map.Map[Map.y][Map.x] = 0;
			Map.y = Map.y - 1;
			if (Map.Map[Map.y][Map.x] == 1)
				Map.y = Map.y + 1;
			if (Map.Map[Map.y][Map.x] == 3)
			{
				system("cls");
				cout << "Congratulations!You're going to enter the next level" << endl;
				Sleep(2000);
				system("cls");
				level++;
				JudgeMap();
				SelectPosition();
			}
		}
		if (key == 's')
		{
			Map.Map[Map.y][Map.x] = 0;
			Map.y = Map.y + 1;
			if (Map.Map[Map.y][Map.x] == 1)
				Map.y = Map.y - 1;
			if (Map.Map[Map.y][Map.x] == 3)
			{
				system("cls");
				cout << "Congratulations!You're going to enter the next level" << endl;
				Sleep(2000);
				system("cls");
				level++;
				JudgeMap();
				SelectPosition();
			}
		}
		if (key == 'a')
		{
			Map.Map[Map.y][Map.x] = 0;
			Map.x = Map.x - 1;
			if (Map.Map[Map.y][Map.x] == 1)
				Map.x = Map.x + 1;
			if (Map.Map[Map.y][Map.x] == 3)
			{
				system("cls");
				cout << "Congratulations!You're going to enter the next level" << endl;
				Sleep(2000);
				system("cls");
				level++;
				JudgeMap();
				SelectPosition();
			}
		}
		if (key == 'd')
		{
			Map.Map[Map.y][Map.x] = 0;
			Map.x = Map.x + 1;
			if (Map.Map[Map.y][Map.x] == 1)
				Map.x = Map.x - 1;
			if (Map.Map[Map.y][Map.x] == 3)
			{
				system("cls");
				cout << "Congratulations!You're going to enter the next level" << endl;
				Sleep(2000);
				system("cls");
				level++;
				JudgeMap();
				SelectPosition();
			}
		}
	}
}

void SelectPosition()
{
	for (int i = 0; i < Map_H; i++)
	{
		for (int j = 0; j < Map_W; j++)
		{
			if (Map.Map[i][j] == 2)
			{
				Map.x = j;
				Map.y = i;
			}
		}
	}
}

void JudgeMap()
{
	if (level == 0)
	{
		for (int i = 0; i < Map_H; i++)
		{
			for (int j = 0; j < Map_W; j++)
			{
				Map.Map[i][j] = Map.Map1[i][j];
			}
		}
	}
	if (level == 1)
	{
		for (int i = 0; i < Map_H; i++)
		{
			for (int j = 0; j < Map_W; j++)
			{
				Map.Map[i][j] = Map.Map2[i][j];
			}
		}
	}
}