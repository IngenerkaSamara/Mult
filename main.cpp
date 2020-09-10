#include "TXLib.h"
#include "persons.cpp"

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

    drawHouse(200 - backX, 400, 230 - backX, 370, true);
    drawHouse(200 - backX, 200, 230 - backX, 170, false);
    drawHouse(-100 - backX, 400, -70 - backX, 370, true);
    drawHouse(-100 - backX, 200, -70 - backX, 170, false);

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

    //Титры
    txSelectFont("Arial", 80);
    int titresY = 800;
    while (titresY > -1200)
    {
        txBegin();
        txSetFillColor(TX_BLACK);
        txClear();
        txDrawText(0, titresY, txGetExtentX(), titresY + 2000,
            "Мультик о вечном\n"
            "\n"
            "Мультик о вечном\n"
            "\n"
            "Мультик о вечном\n"
            "\n"
            "Мультик о вечном\n"
            "\n"
            "Мультик о вечном\n"
            "\n"
            "Мультик о вечном\n"
            "\n"
            "Автор: Миша\n");

        txSleep(20);
        txEnd();
        titresY -= 10;
    }

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
    int kadr = 1;
    while (humanX > 230)
    {
        txBegin();
        drawBackgroundScene1(backX, cloud1X, cloud2X, cloud3X);
        drawPlane(planeX, planeY);
        if (kadr == 1)
            drawHuman(humanX,       400, humanSize, humanX - 3, humanX - 5, humanX + 5);
        else if (kadr == 2)
            drawHuman(humanX,       400, humanSize, humanX - 15, humanX - 10, humanX + 5);
        else if (kadr == 3)
            drawHuman(humanX,       400, humanSize, humanX - 10, humanX - 10, humanX + 10);
        else if (kadr == 4)
            drawHuman(humanX,       400, humanSize, humanX - 3, humanX - 3, humanX + 12);
        else
            drawHuman(humanX,       400, humanSize, humanX - 15, humanX - 10, humanX + 5);

        txSleep(10);
        kadr += 1;
        if (kadr > 5)
            kadr = 1;

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
        drawHouse(200, 400, doorLeft, doorTop, true);
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
        drawHouse(200, 400, doorLeft, doorTop, true);
        drawPlane(planeX, planeY);
        drawHuman(humanX,       400, humanSize, humanX - 3, humanX - 5, humanX + 5);

        /*char str[100];
        sprintf(str, "Координата = %d", humanX);
        txTextOut(100, 100, str);
        sprintf(str, "Размер = %f", humanSize);
        txTextOut(500, 100, str);   */

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
        drawHouse(200, 400, doorLeft, doorTop, true);
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

