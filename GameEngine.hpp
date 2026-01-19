// UI : rounded corners ╭ ╮ ╰ ╯,
//      long minus ─,
//      minus-rod connectors ├ ┤ ┬ ┴ ┼
//      long rod  │


#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <cmath>

void gotoxy(int x, int y)
{
    // if(x>0 && y>0)
    {
        COORD coords;
        coords.X = x;
        coords.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
    }
}
std::string Lpx(std::string s, int times)
{
    std::string t;
    for (int i = 0; i < times; i++)
    {
        t = t + s;
    }
    return t;
}
void SlowPrint(std::string s, int miliseconds)
{
    for (auto c : s)
    {
        std::cout << c;
        Sleep(miliseconds);
    }
}

class Block
{
public:
    float Width = 0, Height = 0;
    int x_pos = 0, y_pos = 0;
    std::string Title;
    bool isTitle = false;
    bool Drawable = true;
    int TitleGap = 0;
    int TextPosition[2] = {x_pos, y_pos};
    std::vector<std::string> TIN;

    Block() {};
    Block(std::vector<float> Dimensions, std::vector<int> Position)
        : Width(Dimensions[0]),
          Height((Dimensions[1])),
          x_pos(Position[0]),
          y_pos((Position[1]))
    {
        isTitle = false;
    };
    Block(std::vector<float> Dimensions, std::vector<int> Position, std::string title, int titleGap = 3)
        : Width(Dimensions[0]),
          Height((Dimensions[1])),
          x_pos(Position[0]),
          y_pos((Position[1])),
          Title(title),
          TitleGap(titleGap)
    {
        isTitle = true;
    };
    int PrintTime = 0;
    void drawtext(int miliseconds = 100)
    {
        PrintTime = miliseconds;
        for (int m = 0; m < TIN.size(); m++)
        {
            if (isTitle == true)
            {
                // gotoxy(TextPosition[0]+1, TextPosition[1] + TitleGap + 1 + line);
                gotoxy(TextPosition[0] + (Width / 2) - TIN[m].size() / 2, TextPosition[1] + TitleGap + 1 + m);
                SlowPrint(TIN[m], miliseconds);
            }
            else
            {
                // gotoxy(TextPosition[0]+1, TextPosition[1] + 1 + line);
                gotoxy(TextPosition[0] + (Width / 2) - TIN[m].size() / 2, TextPosition[1] + 1 + m);
                SlowPrint(TIN[m], miliseconds);
            }
        }
    }
    void Draw()
    {
        std::string corner[4] = {"╭", "╮", "╰", "╯"},
                    line = "─",
                    rod = "│",
                    junction[5] = {"├", "┤", "┬", "┴", "┼"};
        if (Drawable == true)
        {
            gotoxy(x_pos, y_pos);
            std::cout << corner[0] << Lpx(line, Width - 2) << corner[1];
            for (int i = 1; i < Height; i++)
            {
                gotoxy(x_pos, y_pos + i);
                if (i == TitleGap && isTitle == true)
                {
                    std::cout << junction[0] << Lpx(line, Width - 2) << junction[1];
                    gotoxy(x_pos + (Width / 2) - (Title.size() / 2), y_pos + i - TitleGap / 2);
                    std::cout << Title;
                    gotoxy(x_pos, y_pos + i);
                }
                else
                {
                    std::cout << rod;
                    gotoxy(x_pos + Width - 1, y_pos + i);
                    std::cout << rod;
                }
            }
            gotoxy(x_pos, y_pos + Height);
            std::cout << corner[2] << Lpx(line, Width - 2) << corner[3];
        }
        drawtext(PrintTime);
    }

    void Clear()
    {
        std::string corner[4] = {" ", " ", " ", " "},
                    line = " ",
                    rod = " ",
                    junction[5] = {" ", " ", " ", " ", " "};
        if (Drawable == true)
        {
            gotoxy(x_pos, y_pos);
            std::cout << corner[0] << Lpx(line, Width - 2) << corner[1];
            for (int i = 1; i < Height; i++)
            {
                gotoxy(x_pos, y_pos + i);
                if (i == TitleGap && isTitle == true)
                {
                    std::cout << junction[0] << Lpx(line, Width - 2) << junction[1];
                    gotoxy(x_pos + (Width / 2) - (Title.size() / 2), y_pos + i - TitleGap / 2);
                    std::cout << Lpx(" ", Title.size());
                    gotoxy(x_pos, y_pos + i);
                }
                else
                {
                    std::cout << rod;
                    gotoxy(x_pos + Width - 1, y_pos + i);
                    std::cout << rod;
                }
            }
            gotoxy(x_pos, y_pos + Height);
            std::cout << corner[2] << Lpx(line, Width - 2) << corner[3];
            for (auto &c : TIN)
            {
                c = Lpx(" ", c.size());
            }
        }
        drawtext(0);
    }

    int cycle = 0;
    void ClearOnce()
    {
        std::string corner[4] = {" ", " ", " ", " "},
                    line = " ",
                    rod = " ",
                    junction[5] = {" ", " ", " ", " ", " "};
        if (cycle == 0)
        {
            gotoxy(x_pos, y_pos);
            std::cout << corner[0] << Lpx(line, Width - 2) << corner[1];
            for (int i = 1; i < Height; i++)
            {
                gotoxy(x_pos, y_pos + i);
                if (i == TitleGap && isTitle == true)
                {
                    std::cout << junction[0] << Lpx(line, Width - 2) << junction[1];
                    gotoxy(x_pos + (Width / 2) - (Title.size() / 2), y_pos + i - TitleGap / 2);
                    std::cout << Lpx(" ", Title.size());
                    gotoxy(x_pos, y_pos + i);
                }
                else
                {
                    std::cout << rod;
                    gotoxy(x_pos + Width - 1, y_pos + i);
                    std::cout << rod;
                }
            }
            gotoxy(x_pos, y_pos + Height);
            std::cout << corner[2] << Lpx(line, Width - 2) << corner[3];
            for (auto &c : TIN)
            {
                c = Lpx(" ", c.size());
            }
        }
        drawtext(0);
        cycle = 1;
    }

    void Text(std::vector<std::string> TextIN, std::vector<std::string> Alignment = {"centerX", "centerY"})
    {
        for (auto c : TextIN)
        {
            TIN.push_back(c);
        }
        for (int m = 0; m < TextIN.size(); m++)
        {
            for (auto c : Alignment)
            {
                int tempx = x_pos, tempy = y_pos;
                if (c == "top")
                {
                    tempy += 1;
                }
                else if (c == "bottom")
                {
                    tempy += (Height - 2);
                }
                else if (c == "left")
                {
                    tempx -= ((Width - 2) / 2 - (TextIN[m].size() / 2));
                }
                else if (c == "right")
                {
                    tempx += (Width - 2) - TextIN[m].size();
                }
                else if (c == "centerX")
                {
                    tempx += (Width - 2) / 2 - (TextIN[m].size() / 2);
                }
                else if (c == "centerY")
                {
                    tempy += (Height - 2) / 2 - TextIN.size()/2;
                }

                TextPosition[0] = tempx;
                TextPosition[1] = tempy;
            }

            // for (int line = 0; line < TextIN.size(); line++)
        }
    }
};
void StartEngine()
{
    SetConsoleOutputCP(CP_UTF8);
    system("CLS");
}