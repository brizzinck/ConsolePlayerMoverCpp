#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class Map
{
public:
    static int MAX_X;
    static int MAX_Y;

    static std::string** SpawnMap()
    {
        srand(time(NULL));
        std::string** array = new std::string * [MAX_X];
        for (int i = 0; i < MAX_X; i++) {
            array[i] = new std::string[MAX_Y];
            for (int j = 0; j < MAX_Y; j++) {
                if (CheckBorders(i, j)) {
                    array[i][j] = "#";
                }
                else {
                    int chance = 1 + rand() % 100;
                    if (90 < chance)
                        array[i][j] = "#";
                    else if (85 < chance) {
                        array[i][j] = "*";
                    }
                    else
                        array[i][j] = " ";
                }
            }
        }
        array[1][1] = " ";
        return array;
    }

    static void DisplayMap(std::string** array)
    {
        int score = 0;
        for (int i = 0; i < MAX_X; i++) {
            for (int j = 0; j < MAX_Y; j++) {
                std::cout << array[i][j];
                if (array[i][j] == "*")
                    score++;
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "      *: " << score;
    }

private:
    static bool CheckBorders(int i, int j)
    {
        return (i == 0 || i == MAX_X - 1 || j == 0 || j == MAX_Y - 1);
    }
};