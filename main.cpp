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

void drawBackgroundScene1(int backX, int cloud1X, int cloud2X, int cloud3X)
{
    drawBackground();
    drawCloud(cloud1X - backX, 150, 1.2);
    drawCloud(cloud2X - backX, 100, 0.8);
    drawCloud(cloud3X - backX, 140, 1);

    drawHouse(200 - backX, 400, 230 - backX, 370);

    int treeX = 500;
    while(treeX < 1200)
    {
        drawTree(treeX - backX, 400, RGB(120, 255, 34));
        treeX += 70;
    }
}


int main()
{
    txCreateWindow (1200, 700);

    //Переменные
    int backX = 1200;

    int planeX = 700, planeY = 50;
    int cloud1X = 600, cloud2X = 1200, cloud3X = 1800;

    int humanX = 300;
    double humanSize = 1;

    int doorLeft = 230, doorTop = 370;



    //Самолет летит
    while (backX > 0)
    {
        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        txSleep(10);
        planeX = planeX - 5;
        backX = backX - 10;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();
    }


    //Самолет снижается
    while (planeX > -400)
    {
        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
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
    while (humanX > 230)
    {
        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanSize, humanX - 3, humanX - 5, humanX + 5);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();



        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanSize, humanX - 15, humanX - 10, humanX + 5);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();


        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanSize, humanX - 10, humanX - 10, humanX + 10);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();


        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanSize, humanX - 3, humanX - 3, humanX + 12);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();


        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanSize, humanX - 15, humanX - 10, humanX + 5);
        txSleep(10);
        humanX = humanX - 5;
        cloud1X = cloud1X - 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();
    }

    //Дверь открывается
    while (doorLeft < 300)
    {
        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawHouse(200, 400, doorLeft, doorTop);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanSize, humanX - 3, humanX - 5, humanX + 5);
        txSleep(10);
        doorLeft += 2;
        doorTop += 1;
        cloud1X -= 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();
    }

    //Человек заходит
    while (humanX < 250)
    {
        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawHouse(200, 400, doorLeft, doorTop);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanSize, humanX - 3, humanX - 5, humanX + 5);
        txSleep(10);

        humanX = humanX + 2;
        humanSize = humanSize * 0.985;
        cloud1X -= 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();
    }

    //Дверь закрывается
    while (doorLeft > 230)
    {
        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawHuman(humanX,       400, humanSize, humanX - 3, humanX - 5, humanX + 5);
        drawHouse(200, 400, doorLeft, doorTop);
        drawPlane(planeX, planeY);
        txSleep(10);
        doorLeft -= 2;
        doorTop -= 1;
        cloud1X -= 2;
        cloud2X -= 3;
        cloud3X -= 2;
        txEnd();
    }


    return 0;
}

