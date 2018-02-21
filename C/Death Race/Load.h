#ifndef STH_H
#define STH_H
#endif

#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <alloc.h>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <process.h>
#include <string.h>


void loading(void);

void loading(void)
{
    int i,a, per = 0;
    setbkcolor(9);// backGROUND  color

    //CIRCLE OF UPPER CORNER
    for(i=0; i<35; i++)

    {
        setcolor(i);
        circle(50,20,i);
    }
    for(i=0; i<45; i++)
    {
        setcolor(i);
        circle(30,70,i);
    }
    for(i=0; i<50; i++)
    {
        setcolor(i);
        circle(70,60,i);

    }
    //CIRCLE OF LOWER CORNER
    for(i=0; i<35; i++)
    {
        setcolor(i);
        circle(580,390,i);

    }
    for(i=0; i<45; i++)
    {
        setcolor(i);
        circle(550,430,i);

    }
    for(i=0; i<50; i++)
    {
        setcolor(i);
        circle(600,435,i);
    }

    // for draw line in UPPER x&y axis
    for(i=639; i>=400; i--)
        putpixel(i,30,RED);
    //delay(30);
    for(i=0; i<=200; i++)
        putpixel(590,i,RED);
    //delay(300);

    for(i=639; i>=410; i--)
        putpixel(i,40,GREEN);
    //delay(30);
    for(i=0; i<=210; i++)
        putpixel(600,i,GREEN);
    //delay(300);
    for(i=639; i>=420; i--)
        putpixel(i,50,BLUE);
    //delay(30);
    for(i=0; i<=220; i++)
        putpixel(610,i,BLUE);

    //delay(800);


    // for draw line lower   x & y  axis
    for(i=0; i<=220; i++)
        putpixel(i,450,RED);
    //delay(30);
    for(i=479; i>=280; i--)
        putpixel(50,i,RED);
    //delay(300);

    for(i=0; i<=210; i++)
        putpixel(i,440,GREEN);
    //delay(30);
    for(i=479; i>=270; i--)
        putpixel(40,i,GREEN);
    //delay(300);
    for(i=0; i<=200; i++)
        putpixel(i,430,BLUE);
    //delay(30);

    for(i=479; i>=260; i--)
        putpixel(30,i,BLUE);
    //delay(30);

    //Loading
    for(i=0; i<=200; i++)
    {
        setcolor(4);
        settextstyle(1, 0, 6);
        outtextxy(170,120,"DEATH  RACE");
        setcolor(7);
        settextstyle(0,DEFAULT_FONT, 1);
        outtextxy(300,244,"LOADING...");
        setcolor(8);
        line(224+i,238,224+i,256);
        setcolor(8);
        rectangle(224,238,425,256);
        delay(15);
        gotoxy(55,16);
        setcolor(RED);
        if(i % 2 == 0)
        {
            printf("%d%",per);
            per++;
        }

    }
    settextstyle(4, 0, 3);
    setcolor(4);    // LIGHT RED
    outtextxy(getmaxx()/2 - 140, getmaxy()/2 + 30, "Press any key to start the game...");
    getch();

}
