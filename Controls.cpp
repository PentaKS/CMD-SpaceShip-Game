#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>

int main()
{
    char input = 'd';
    while (1)
    {
        input = getche();
        std::fstream fs;
        fs.open("ControlMaster.txt", std::ios::out | std::ios::trunc);
        std::string token;
        switch (input)
        {
            case 'w': token = "up";  break;
            case 's': token = "down";break;
        }

        fs.clear();
        if (!(fs << token))
            std::cout << "error";
        std::cout << "\n";
    }
}