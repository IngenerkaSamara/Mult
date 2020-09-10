#include "TXLib.h"

//Рисование персонажей
void drawCloud(int x, int y, double _size)
{
    txSetColor(TX_GRAY);
    txSetFillColor(TX_GRAY);
    txCircle (              x, y,              45 * _size);
    txCircle ( 65 * _size + x, y,              75 * _size);
    txCircle (150 * _size + x, y,              60 * _size);
    txEllipse(-90 * _size + x, y - 10 * _size,
               60 * _size + x, y + 65 * _size);
}

void drawPlane(int x, int y)
{
    txSetColor(TX_BLACK, 4);
    txSetFillColor(TX_GRAY);
    txEllipse(x - 85, y,     220 + x, y + 30);

    txSetFillColor(TX_BLUE);
    txPie    (x - 85, y + 2,  10 + x, y + 30, 45, 135);

    txSetFillColor(TX_GRAY);
    POINT wing1[4] = {
        {35 + x, y +  20},
        {60 + x, y +  20},
        {90 + x, y + 100},
        {65 + x, y + 100}
    };
    txPolygon (wing1, 4);

    //Верхнее крыло
    POINT wing2[4] = {
        { 40 + x, y},
        { 80 + x, y - 40},
        {105 + x, y - 40},
        { 65 + x, y}
    };
    txPolygon (wing2, 4);

    //Заднее крыло
    POINT rearWing[4] = {
        {220 + x, y + 15},
        {240 + x, y - 30},
        {190 + x, y - 30},
        {165 + x, y}
    };
    txPolygon (rearWing, 4);
}

void drawHuman(int x, int y, double razm, int xKolena, int xLeftLeg, int xRightLeg)
{
    txSetColor(TX_BLACK, 5);
    txSetFillColor(TX_WHITE);
    txCircle(x      , y -  20 * razm, 20 * razm);
    txLine  (x      , y,              x,                y + 65 * razm);
    txLine  (x      , y +  10 * razm, x - 15 * razm,    y + 40 * razm);
    txLine  (x      , y +  10 * razm, x + 15 * razm,    y + 40 * razm);

    txLine  (x      , y +  65 * razm, xKolena,   y + 100 * razm);
    txLine  (xKolena, y + 100 * razm, xLeftLeg,  y + 130 * razm);
    txLine  (x      , y +  65 * razm, xRightLeg, y + 130 * razm);
}

void drawHouse(int x, int y, int doorLeft, int doorTop)
{
    txSetFillColor(TX_RED);
    txSetColor(TX_BLACK, 3);
    POINT roof[3] = {
        {x - 140, y -  80},
        {x +  20, y - 170},
        {x + 160, y -  80}
    };
    txPolygon (roof, 3);

    txSetFillColor(TX_YELLOW);
    txRectangle(x - 140, y - 80, x + 160, y + 120);

    int brickY = y + 120;
    int brickX = x - 140;

    while (brickY > y - 80)
    {
        brickX = x - 140;
        while (brickX < x + 140)
        {
            txRectangle(brickX,      brickY - 20, brickX + 40, brickY);
            txRectangle(brickX + 20, brickY - 40, brickX + 60, brickY - 20);
            brickX += 40;
        }

        brickY -= 40;
    }

    //Door
    txSetFillColor(TX_BLACK);
    txRectangle(x + 30, y - 30, x + 100, y + 120);
    txSetFillColor(RGB(90, 56, 37));
    POINT door[4] = {
        {doorLeft, doorTop},
        {doorLeft, doorTop + 150},
        {x + 100, y + 120},
        {x + 100, y -  30}
    };
    txPolygon (door, 4);

    txCircle   (doorLeft  +10, doorTop + 60, 8);

    //Window
    txSetFillColor(RGB(185, 255, 255));
    txRectangle(x - 120, y - 40, x,      y + 50);
    txLine     (x -  60, y - 40, x - 60, y + 50);
    txLine     (x -  60, y,      x,      y);
}

void drawTree(int x, int y, COLORREF color)
{
    int delta = random(-4, 4);
    txSetColor(TX_BLACK, 3);
    txSetFillColor(RGB(90, 56, 37));
    txRectangle(x     , y      , x +  20, y + 125);
    txSetFillColor(color);
    txEllipse  (x - 35 + delta, y - 80,
                x + 57 + delta, y +  23);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_RED);
    txCircle   (x - 20, y -  45, 8);
    txSetColor(TX_BLACK, 3);
    txLine     (x - 20, y -  48, x -  20, y -  52);
}
