#include <iostream>
#include <Windows.h>
#include <conio.h>
class Mover
{
private:
    static int x;
    static int y;
public:
    static void SetPlayerPos(std::string** map)
    {
        map[y][x] = "@";
    }
    static void Move(std::string** map)
    {
        if (_kbhit())
        {
            int lastX = x;
            int lastY = y;
            map[y][x] = " ";
            switch (_getch())
            {
            case 'w':
                y--;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
            default:
                break;
            }
            if (map[y][x] == "#") {
                x = lastX;
                y = lastY;
            }
            else
                SetPlayerPos(map);
        }
    }
};

