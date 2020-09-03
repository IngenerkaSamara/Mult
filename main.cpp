#include "TXLib.h"

void drawBackground()
{
    txSetColor(RGB(185, 255, 255));
    txSetFillColor(RGB(185, 255, 255));
    txRectangle(0, 0, 1200, 700);
    txSetColor(TX_GRAY);
    txSetFillColor(TX_GRAY);
    txRectangle(0, 480, 1200, 700);
}

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

void drawPlane(int x)
{
    txSetColor(TX_BLACK, 4);
    txSetFillColor(TX_GRAY);
    txEllipse(x - 85, 50, 220 + x,  80);

    txSetFillColor(TX_BLUE);
    txPie    (x - 85, 52,  10 + x, 80, 45, 135);

    txSetFillColor(TX_GRAY);
    POINT wing1[4] = {
        {35 + x,  70},
        {60 + x,  70},
        {90 + x, 150},
        {65 + x, 150}
    };
    txPolygon (wing1, 4);

    //Верхнее крыло
    txLine   ( 40 + x,  50,  80 + x,  10);
    txLine   ( 80 + x,  10, 105 + x,  10);
    txLine   (105 + x,  10,  65 + x,  50);

    //Заднее крыло
    txLine   (220 + x,  65, 240 + x,  20);
    txLine   (190 + x,  20, 240 + x,  20);
    txLine   (190 + x,  20, 165 + x,  50);
}

void drawHuman(int x, int y, int xLeftLeg, int xRightLeg)
{
    txSetColor(TX_BLACK, 5);
    txSetFillColor(TX_WHITE);
    txCircle(x      , y -  20, 20);
    txLine  (x      , y,       x,         y + 65);
    txLine  (x      , y +  10, x - 35,    y + 30);
    txLine  (x      , y +  10, x + 35,    y + 30);

    txLine  (x      , y +  65, x - 10,    y + 100);
    txLine  (x -  10, y + 100, xLeftLeg,  y + 130);
    txLine  (x      , y +  65, xRightLeg, y + 130);
}

void drawHouse()
{
    txSetFillColor(TX_RED);
    txSetColor(TX_BLACK, 5);
    POINT roof[3] = {
        { 60, 320},
        {220, 230},
        {340, 320}
    };
    txPolygon (roof, 3);

    txSetFillColor(TX_YELLOW);
    txRectangle( 60, 320, 340, 520);
    //Door
    txSetFillColor(RGB(90, 56, 37));
    txRectangle(230, 400, 300, 520);
    //Window
    txSetFillColor(RGB(185, 255, 255));
    txRectangle( 80, 360, 200, 450);
    txLine     (140, 360, 140, 450);
    txLine     (140, 400, 200, 400);

    txDrawText (230, 400, 300, 520, "Лох");
}

void drawTree(int x, int y, COLORREF color)
{
    txSetColor(TX_BLACK, 3);
    txSetFillColor(RGB(90, 56, 37));
    txRectangle(x     , y      , x +  40, y + 250);
    txSetFillColor(color);
    txEllipse  (x - 70, y - 160, x + 115, y +  90);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_RED);
    txCircle   (x - 40, y -  90, 10);
    txSetColor(TX_BLACK, 3);
    txLine     (x - 40, y -  95, x -  40, y - 105);
}

int main()
{
    txCreateWindow (1200, 700);

    drawBackground();
    drawCloud(200, 150, 1.2);
    drawCloud(500, 100, 0.8);
    drawCloud(900, 140, 1);

    drawPlane(500);
    drawHouse();
    drawHuman(800, 400, 793, 808);
    drawHuman(900, 400, 886, 920);

    drawTree(600, 300, RGB(80, 255, 64));
    drawTree(760, 320, RGB(120, 255, 34));
    drawTree(700, 320, RGB(120, 255, 34));

    return 0;
}

