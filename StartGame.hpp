#include "GameEngine.hpp"

void setFieldingOf(Block &b)
{
    b.Drawable = false;
    b.ClearOnce();
    b.TextPosition[0] = 1;
    b.TextPosition[1] = 1;
    b.x_pos = 1;
    b.y_pos = 1;
    b.Width = 0;
    b.Height = 0;
}

int astd_speed = 2;
int gametime = 0;
void Start()
{
    system("CLS");
    system("start Controls.exe /k");
    StartEngine();
    
    Block Ship({10, 5}, {10, 5});
    std::vector<std::string> SpaceShip = {
        "               ",
        "               ",
        "   ___         ",
        "  |   \\        ",
        "  \\    \\>      ",
        "   \\    \\     ",
        "  ])||||||||||>",
        "   /    /      ",
        "  /    />      ",
        "  |___/        ",
        "               ",
        "               "};
    Ship.Text(SpaceShip);
    Ship.drawtext(0);

    Block Bullets[1000];
    Block GunFire1({1, 1}, {20, 9});
    GunFire1.Text({">"});
    GunFire1.drawtext(0);
    for (int i = 0; i < 1000; i++)
        {Bullets[i] = GunFire1;}

    Block Asteroids[1000];
    Block Asteroid({10, 5}, {90, 10});
    for (int i = 0; i < 1000; i++)
    {
        Asteroids[i] = Asteroid;
        if (i % 3 == 0)
            Asteroids[i].y_pos = 12;
        else if (i % 3 == 1)
            Asteroids[i].y_pos = 5;
        else
            Asteroids[i].y_pos = 20;
    }

    Block ScorePanel({90, 3}, {3, 27});
    ScorePanel.Draw();

    Block MessageBack({40, 20}, {30, 5});
    Block Message({40, 20}, {30, 5});
    std::vector<std::string> SpaceBack;
    for(int i = 0; i < 19; i++)
        {SpaceBack.push_back(Lpx(" ", 38));};
    MessageBack.Text(SpaceBack, {"top"});
    MessageBack.TextPosition[1]--;

    int i = 0, score = 0, n = 0;
    bool breaker = false;
    while (breaker == false)
    {
        // bool fire = false;
        std::fstream fs;
        fs.open("ControlMaster.txt", std::ios::in | std::ios::out);
        std::string input;
        while (fs >> input)
        {}

        if (input == "up")
        {
            if (Ship.TextPosition[1] > 0)
                Ship.TextPosition[1] -= 2;
            Ship.drawtext(0);
        }
        else if (input == "down")
        {
            if (Ship.TextPosition[1] < 14)
                Ship.TextPosition[1] += 2;
            Ship.drawtext(0);
        }
        if (input == "up" || input == "down")
        {
            fs.clear();
            fs << "p";
        }

        if (gametime % 100 == 0 && gametime > 0)
        {
            Bullets[i].TextPosition[1] = Ship.TextPosition[1] + 6;
            Bullets[i].TextPosition[0] += 4;
            for (int m = 0; m < i; m++)
            {
                if (Bullets[m].TextPosition[0] > 75 && Bullets[m].TextPosition[0] < 80)
                {
                    setFieldingOf(Bullets[m]);
                }
                if (Asteroids[m].x_pos > 20 && Asteroids[m].x_pos < 24)
                {
                    setFieldingOf(Asteroids[m]);
                    Message.Clear();
                    Message.Text(
                        {"      YOU LOST :(      ",
                         "  BETTER LUCK NEXT TIME  ",
                         "( ASTEROID CROSSED THE SHIP )",
                         " ",
                         " [press <SPACE> to main menu] "});
                    breaker = true;
                }
                // if (delay == 1)
                {
                    if (Bullets[m].TextPosition[0] < 80 && Bullets[m].Drawable == true)
                    {
                        Bullets[m].Clear();
                        Bullets[m].TIN[0] = {">"};
                        Bullets[m].TextPosition[0] += 1;
                        Bullets[m].drawtext(0);
                    }
                }

                if (m % 8 == 0)
                {
                    if (Asteroids[m].x_pos > 20 && Asteroids[m].Drawable == true)
                    {
                        Asteroids[m].Clear();
                        Asteroids[m].x_pos -= astd_speed;
                        Asteroids[m].Draw();
                    }
                    for (auto b : Bullets)
                    {
                        if (b.TextPosition[0] == Asteroids[m].x_pos && b.Drawable != false)
                        {
                            if (b.TextPosition[1] > Asteroids[m].y_pos - 2 && b.TextPosition[1] < Asteroids[m].y_pos + Asteroids[m].Height)
                            {
                                setFieldingOf(Bullets[m]);
                                setFieldingOf(Asteroids[m]);
                                score++;
                            }
                        }
                    }
                }
            }

            i++;
            // delay++;
            gametime = 0; 
        }
        gametime++;
        gotoxy(8, 28);
        std::cout << "Score: " << score;
        if (score == 20)
        {
            Message.Clear();
            Message.Text({
                "HURRAY!! A PERFECT 20 SCORE",
                "          YOU WON          ",
                "   ",
                " [press <SPACE> to main menu] "
            });
            break;
        }
    }
    Message.TextPosition[1]-=3;
    MessageBack.Draw();
    Message.Draw();

    char c = 'm';
    while(c != ' ')
    {
        c = getch();
    }
}