#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "SpawnMap.cpp"
#include "PlayerMover.cpp"
int Mover::x = 1;
int Mover::y = 1;
int Map::MAX_X = 10;
int Map::MAX_Y = 20;
int main()
{
    std::string** map = Map::SpawnMap();
    system("cls");
    Map::DisplayMap(map);
    Mover::SetPlayerPos(map);
    while (true)
    {
        if (_kbhit()) {         
            system("cls");
            Mover::SetPlayerPos(map);
            Map::DisplayMap(map);
            Mover::Move(map);
        }
    }
	return 0;
}
