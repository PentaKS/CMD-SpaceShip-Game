#include "GameEngine.hpp"
#include "StartGame.hpp"

int main()
{
    system("CLS");
    StartEngine();
    Block Initiation({80, 7}, {10, 1});
    Initiation.Text(
        {"====  WELCOME TO MY GAME ====",
         "    IT IS A SPACESHIP SHOOTING GAME (CURRENTLY ASTEROIDS)    ",
         "    THERE ARE THREE DIFFICULTIES OF THIS GAME DEPENDING ON ASTERIOD SPEED    ",
         "  == YOU NEED 20 SCORE TO WIN ==  "},
        {"top"});

    Block Difficulty({40, 17}, {10, 10});

    Block Easy  ({30, 3}, {15, 13});
    Block Medium({30, 3}, {15, 17});
    Block Hard  ({30, 3}, {15, 21});

    Easy.Text  ({"-1. EASY -"  });
    Medium.Text({"-2. MEDIUM -"});
    Hard.Text  ({"-3. HARD -"  });

    while (1)
    {
        system("CLS");

        Initiation.Draw();
        Difficulty.Draw();
        Easy.Draw();
        Medium.Draw();
        Hard.Draw();

        int preff_difficulty = 0;
        gotoxy(55, 15);
        std::cout << "ENTER YOUR PERFFERED DIFFICULTY(1, 2, 3)";
        gotoxy(55, 16);
        std::cout << ">>> ";
        std::cin >> preff_difficulty;

        if (preff_difficulty == 1)
            astd_speed = 1;
        else if (preff_difficulty == 2)
            astd_speed = 2;
        else if (preff_difficulty == 3)
            astd_speed = 3;

        Start();
    }
}