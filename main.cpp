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

void drawHuman(int x, int y, int xKolena, int xLeftLeg, int xRightLeg)
{
    txSetColor(TX_BLACK, 5);
    txSetFillColor(TX_WHITE);
    txCircle(x      , y -  20, 20);
    txLine  (x      , y,       x,         y + 65);
    txLine  (x      , y +  10, x - 15,    y + 40);
    txLine  (x      , y +  10, x + 15,    y + 40);

    txLine  (x      , y +  65, xKolena,   y + 100);
    txLine  (xKolena, y + 100, xLeftLeg,  y + 130);
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


//Рисование фона сцен
void drawBackground()
{
    txSetColor(RGB(185, 255, 255));
    txSetFillColor(RGB(185, 255, 255));
    txRectangle(0, 0, 1200, 700);
    txSetColor(TX_GRAY);
    txSetFillColor(TX_GRAY);
    txRectangle(0, 480, 1200, 700);
}

void drawBackgroundScene1(int cloud1X, int cloud2X, int cloud3X)
{
    drawBackground();
    drawCloud(cloud1X, 150, 1.2);
    drawCloud(cloud2X, 100, 0.8);
    drawCloud(cloud3X, 140, 1);

    drawHouse();
    drawTree(600, 300, RGB(80, 255, 64));
    drawTree(790, 320, RGB(120, 255, 34));
    drawTree(700, 320, RGB(120, 255, 34));
}


int main()
{
    txCreateWindow (1200, 700);

    int planeX = 700;
    int planeY = 50;
    int cloud1X = 600;
    int cloud2X = 1200;
    int cloud3X = 1800;
    int humanX = 1200;

    //Самолет летит
    //while (planeX > 500)
    {
        txBegin();
        drawBackgroundScene1(cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        txSleep(10);
        planeX = planeX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();
    }


    //Самолет снижается
    //while (planeX > -400)
    {
        txBegin();
        drawBackgroundScene1(cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        txSleep(10);
        planeX = planeX - 5;
        planeY = planeY + 2;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();
    }

    //Человек идет
    while (humanX > 300)
    {
        txBegin();
        drawBackgroundScene1(cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanX - 3, humanX - 5, humanX + 5);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();



        txBegin();
        drawBackgroundScene1(cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanX - 15, humanX - 10, humanX + 5);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();


        txBegin();
        drawBackgroundScene1(cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanX - 10, humanX - 10, humanX + 10);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();


        txBegin();
        drawBackgroundScene1(cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanX - 3, humanX - 3, humanX + 12);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();


        txBegin();
        drawBackgroundScene1(cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanX - 15, humanX - 10, humanX + 5);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();
    }


    return 0;
}

