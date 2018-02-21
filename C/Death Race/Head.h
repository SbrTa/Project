/*#ifndef STH_H
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
*/
#include "Load.h"

#define maxx 640
#define maxy 480

void animation(void);
void startpage1();
void startpage2();
void startpage3();
void startpage4();
void record(int);
void Drecord();
void soundd (void);
void display (void);
void game();

int car[]= {165,375,238,375,238,450,165,450,165,375};
int wheel[]= {155,385,165,385,165,400,155,400,155,385};
int rect[]= { 0,0,maxx,0,maxx,maxy,0,maxy,0,0};  //whole screen
int rect2[]= {150,0,maxx-150,0,maxx-150,maxy,150,maxy,150,0}; //for road
int rect3[]= {150+103,1,150+103+15,1,150+103+15,50,150+103,50,150+103,1}; //for strip on road
int rect4[]= {maxx-150-119,1,maxx-150-119+15,1,maxx-150-119+15,50,maxx-150-119,50,maxx-150-119,1}; //for strip on road


void startpage1(void)
{
    char a, ch1;
    int b;
    setcolor(7);
    line(215,300,300,300);
    line(215,200,333,200);

    setcolor(11);
    rectangle(50,50,600,400);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(40,40,610,410);
    floodfill(45,45,11);
    setfillstyle(SOLID_FILL,7);
    floodfill(55,55,11);
    setcolor(BLUE);
    //settextstyle(6,DEFAULT_FONT, 5);
    settextstyle(1,0,5);
    outtextxy(215,100,"PLAY");
    line(215,150,310,150);
    setcolor(RED);
    outtextxy(215,150,"SCORE");
    outtextxy(215,200,"HELP");
    outtextxy(215,250,"EXIT");
    while(1)
    {
        a = getch();
        if(a == 13)
            game();
        else if(a == 0)
        {
            ch1 = getch();
            if (ch1 == 80)
                startpage2();
            else if (ch1 == 72)
                startpage4();
            else if(ch1 == 27) exit(1);
        }
        else
            continue;
        //startpage1();
    }
}

void startpage2()
{
    char a, ch1;
    setcolor(7);
    line(215,150,310,150);
    line(215,250,310,250);
    setcolor(11);
    rectangle(50,50,600,400);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(40,40,610,410);
    floodfill(45,45,11);
    setfillstyle(SOLID_FILL,7);
    floodfill(55,55,11);
    setcolor(RED);
    //settextstyle(6,DEFAULT_FONT, 5);
    settextstyle(1,0,5);
    outtextxy(215,100,"PLAY");
    setcolor(BLUE);
    line(215,200,333,200);
    outtextxy(215,150,"SCORE");
    setcolor(RED);
    outtextxy(215,200,"HELP");
    outtextxy(215,250,"EXIT");
    while(1)
    {
        a = getch();
        if( a == 13)
        {
            cleardevice();
            setcolor(11);
            rectangle(50,50,600,400);
            setfillstyle(SOLID_FILL,GREEN);
            rectangle(40,40,610,410);
            floodfill(45,45,11);
            Drecord();
            getch();
            cleardevice();
            startpage2();
        }
        else if(a == 0)
        {
            ch1 = getch();
            if (ch1 == 80)
                startpage3();
            else if (ch1 == 72)
                startpage1();
        }
        else
            continue;
        //startpage2();
    }
}

void startpage3()
{
    char a, ch1;
    setcolor(7);
    line(215,200,333,200);
    line(215,300,300,300);
    setcolor(11);
    rectangle(50,50,600,400);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(40,40,610,410);
    floodfill(45,45,11);
    setfillstyle(SOLID_FILL,7);
    floodfill(55,55,11);
    setcolor(RED);
    //settextstyle(6,DEFAULT_FONT, 5);
    settextstyle(1,0,5);
    outtextxy(215,100,"PLAY");
    outtextxy(215,150,"SCORE");
    setcolor(BLUE);
    line(215,250,310,250);
    outtextxy(215,200,"HELP");
    setcolor(RED);
    outtextxy(215,250,"EXIT");
    while(1)
    {
        a = getch();
        if(a == 13)
        {
            cleardevice();
            setcolor(11);
            rectangle(50,50,600,400);
            setfillstyle(SOLID_FILL,GREEN);
            rectangle(40,40,610,410);
            floodfill(45,45,11);
            setfillstyle(SOLID_FILL,7);
            floodfill(55,55,11);
            //settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
            settextstyle(10,0,4);
            setcolor(RED);
            outtextxy(200,45,"GAME TIPS");
            settextstyle(6,HORIZ_DIR,1);
            setcolor(BLUE);
            gotoxy(5,13);
            outtextxy(55,120,"Press SPACE Key to pause at any time and press any key to resume.");
            outtextxy(55,145,"For Emergency Exit from the Game while playing press  ESC  key.");
            gotoxy(5,15);
            outtextxy(55,170,"The speed of your car is increased as you proceed. So greater");
            outtextxy(55,195,"difficulty is on the way as you proceed. Your game will be Over");
            outtextxy(55,220,"if your car crash with another car...");
            setcolor(BLUE);
            outtextxy(55,265,"Press the RIGHT_ARROW to move the Car Right & LEFT_ARROW to");
            outtextxy(55,285,"move the Car Left..");
            settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
            setcolor(4);
            outtextxy(80,350,"Press enter key to return to the main menu");
            getch();
            cleardevice();
            startpage3();
        }
        else if(a == 0)
        {
            ch1 = getch();
            if (ch1 == 80)
                startpage4();
            else if (ch1 == 72)
                startpage2();
        }
        else
            continue;
        //startpage3();
    }
}

void startpage4()
{
    char a, ch1;
    setcolor(7);
    line(215,250,310,250);
    line(215,150,310,150);
    setcolor(11);
    rectangle(50,50,600,400);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(40,40,610,410);
    floodfill(45,45,11);
    setfillstyle(SOLID_FILL,7);
    floodfill(55,55,11);
    setcolor(RED);
    //settextstyle(6,DEFAULT_FONT, 5);
    settextstyle(1,0,5);
    outtextxy(215,100,"PLAY");
    outtextxy(215,150,"SCORE");
    outtextxy(215,200,"HELP");
    setcolor(BLUE);
    line(215,300,300,300);
    outtextxy(215,250,"EXIT");
    while(1)
    {
        a = getch();
        if( a == 13)
        {
            cleardevice();
            setcolor(11);
            rectangle(50,50,600,400);
            setfillstyle(SOLID_FILL,GREEN);
            rectangle(40,40,610,410);
            floodfill(45,45,11);
            setcolor(11);
            setfillstyle(SOLID_FILL,15);
            floodfill(55,55,11);
            setcolor(BLUE);
            settextstyle(3,0,4);
            outtextxy(155,50,"THANKS FOR PLAYING");

            setcolor(3);
            outtextxy(58,100,"A Simple Presentation by ");
            setcolor(5);
            settextstyle(7,0,4);
            outtextxy(450,100,"SAF_404");
            setcolor(9);
            settextstyle(4,0,5);
            outtextxy(180,150,">Fahad Ahmed");
            setcolor(12);
            settextstyle(4,0,5);
            outtextxy(180,195,">Autish Moulik");
            setcolor(2);
            settextstyle(4,0,5);
            outtextxy(180,240,">Subrata Roy");
            settextstyle(3,0,3);
            setcolor(6);
            outtextxy(170,350,"PRESS ANY KEY TO EXIT.....");
            getch();
            exit(0);
        }
        if(a == 0)
        {
            ch1 = getch();
            if (ch1 == 80)
                startpage1();
            else if (ch1 == 72)
                startpage3();
        }
        else
            continue;
        //startpage4();
    }
}


void game(void)
{
    int driver=DETECT,mode;
    initgraph(&driver,&mode,"C:\\tc\\bgi");
    loading();
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);
back:
    animation();
    getch();
    nosound();
}

void animation(void)
{

    unsigned char ch,ch1;
    int carspeed=5;   //speed of car coming from the top of the screen
    int posn= 1;   //player's car stored in first lane
    int coord=1;
    int x,i;
    int val1,val2;
    int score=0;      //for programming
    int displayscore=0;
    void *buff,*buff2,*buff3;
    void *buff4,*buff5,*buff6,*buff7;   //for storing image to memory

    setfillstyle(SOLID_FILL,BLUE);
    fillpoly(5,car);         //draw a sample of other car on road which is blue
    setfillstyle(CLOSE_DOT_FILL,BROWN);
    fillpoly(5,wheel);   //draw wheell for sample of other car on road
    buff4=malloc(imagesize(155,385,165,400));  //for storing the wheel car on road to the memory
    getimage(155,385,165,400,buff4);       //wheel of car stored in memory
    putimage(238,385,buff4,COPY_PUT);   //wheel of car printed in remaining three sides of blue car
    putimage(155,425,buff4,COPY_PUT);         //as above
    putimage(238,425,buff4,COPY_PUT);//as above
    buff5=malloc(imagesize(155,375,248,450));  //to store image of the blue car on memory
    getimage(155,375,248,450,buff5);//image of blue car stored in  memory
    putimage(155,375,buff5,XOR_PUT);  //the blue car deleted from screen

    setfillstyle(SOLID_FILL,RED);
    fillpoly(5,car);          //players car
    setfillstyle(CLOSE_DOT_FILL,BROWN);
    fillpoly(5,wheel);
    putimage(238,385,buff4,COPY_PUT);
    putimage(155,425,buff4,COPY_PUT);
    putimage(238,425,buff4,COPY_PUT);
    buff3=malloc(imagesize(155,375,248,450));     //image of red car stored on memory
    getimage(155,375,248,450,buff3);
    putimage(155,375,buff3,XOR_PUT); //delete red car on screen
    srand(time(NULL));
    x=1;

    setfillstyle(SOLID_FILL,WHITE);
    fillpoly(5,rect3);//draw strips on road
    fillpoly(5,rect4);//as above
    buff=malloc(imagesize(150+103,1,150+103+15,50)); //to store left strip on  memory
    getimage(150+103,1,150+103+15,50,buff);//stored left strip on memory
    putimage(150+103,1,buff,XOR_PUT);//strips on road deleted from the memory

start:
    setfillstyle(SOLID_FILL,GREEN);
    fillpoly( 5,rect); //draw green background
    setfillstyle(SOLID_FILL,BLACK);
    fillpoly(5,rect2);//draw black roads

    setcolor(RED);
    settextstyle(4,0,9);
    outtextxy(300,40,"3");
    delay(500);

    setcolor(RED);
    settextstyle(4,0,9);
    outtextxy(300,130,"2");
    delay(500);

    setcolor(RED);
    settextstyle(4,0,9);
    outtextxy(300,220,"1");
    delay(500);

    sound (300);
    sound (300);
    setcolor(RED);
    settextstyle(4,0,10);
    outtextxy(230,320,"GO..");
    delay(800);


    carspeed=5;   //speed of car coming from the top of the screen
    posn= 2;   //player's car stored in first lane
    coord=1;

    score=0;      //for programming

    displayscore=0;                 //score that is displayed for user
again:
    val1=rand()%3+1; //get random value  among 1,2,and 3
    val2=rand()%3+1;//  another random value among 1,2,3
    if (val1==val2)  goto again; //values of val1 and val2 must be different, va11 and val2 are for positions of other car on road
    while(1)
    {
        {
            settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
            outtextxy(25,25,"SCORE");      //SCORE on left side of screen
        }
        gotoxy(6,5);
        printf("%d",displayscore); //score continously displayed

        if (score<50) carspeed=20;
        if (score>=50 && score<100) carspeed=30;
        if (score>=100 && score<150) carspeed=35;
        if (score>=150 && score<250)  carspeed=40;    //score and speedin the program code
        if (score>=250 && score<400) carspeed=45;
        if (score>=400) carspeed=48;


        sound(100);
//below for printing moving strips on road
        putimage(150+103,(x-1)*25,buff,COPY_PUT);
        putimage(150+103+15+103,(x-1)*25,buff,COPY_PUT);
        putimage(150+103,100+(x-1)*25,buff,COPY_PUT);
        putimage(150+103+15+103,100+(x-1)*25,buff,COPY_PUT);
        putimage(150+103,200+(x-1)*25,buff,COPY_PUT);
        putimage(150+103+15+103,200+(x-1)*25,buff,COPY_PUT);
        putimage(150+103,300+(x-1)*25,buff,COPY_PUT);
        putimage(150+103+15+103,300+(x-1)*25,buff,COPY_PUT);
        if (x!=5)
        {
            putimage(150+103,400+(x-1)*25,buff,COPY_PUT);
            putimage(150+103+15+103,400+(x-1)*25,buff,COPY_PUT);
        }
        if (x==5)
        {
            delay(50);
            putimage(150+103,1,buff,COPY_PUT);
            putimage(150+103+15+103,1,buff,COPY_PUT);
        }

        delay(50);   //for speed   of moving road
        //above for strips on road

        setfillstyle(SOLID_FILL,BLACK);
        fillpoly(5,rect2);    //for removing strips and printing completely black



        if (val1!=1 && val2!=1)         //if random values are 2 and 3 that means other car in lane 2 and 3
        {
            coord=coord+carspeed;
            if (coord>=300 && (posn==2 || posn==3))        //if players car coincides with other car
            {
                nosound();
                sound(40);
                delay(100);
                nosound();
                record(displayscore);
                cleardevice();
                setcolor(11);
                rectangle(50,50,600,400);
                setfillstyle(SOLID_FILL,GREEN);
                rectangle(40,40,610,410);
                floodfill(45,45,11);
                setfillstyle(SOLID_FILL,15);
                floodfill(55,55,11);
                setcolor(9);
                outtextxy(100,200,"Do you wish to play again: [Y/N]");
                rectangle(400,200,440,225);

                setfillstyle(SOLID_FILL,BLACK);
                floodfill(405,205,9);
                while(1)
                {
                    ch = getch();
                    if ((ch=='y') || (ch=='Y'))
                        goto start;
                    else if((ch =='n') || (ch == 'N'))
                    {
                        cleardevice();
                        startpage1();
                    }
                    else
                        continue;
                }
            }

            putimage(273,coord,buff5,COPY_PUT);    //display  others car on second and third lane
            putimage(391,coord,buff5,COPY_PUT);

            if (coord>=450 )
            {
                score=score+5;
                coord=1;
                srand(time(NULL));
go1:
                val1=rand()%3+1;
                val2=rand()%3+1;
                if (val1==val2) goto go1;
            }
        }
        if (val1!=2 && val2!=2)  //same as above, now for random value 1 and 3
        {
            coord=coord+carspeed;
            if (coord>=300 && (posn==1 || posn==3))
            {
                nosound();
                sound(40);
                delay(100);
                nosound();
                record(displayscore);
                cleardevice();
                setcolor(11);
                rectangle(50,50,600,400);
                setfillstyle(SOLID_FILL,GREEN);
                rectangle(40,40,610,410);
                floodfill(45,45,11);
                setfillstyle(SOLID_FILL,15);
                floodfill(55,55,11);
                setcolor(9);
                outtextxy(100,200,"Do you wish to play again: [Y/N]");
                rectangle(400,200,440,225);

                setfillstyle(SOLID_FILL,BLACK);
                floodfill(405,205,9);
                while(1)
                {
                    ch=getch();
                    if ((ch=='y') || (ch=='Y'))
                        goto start;
                    else if((ch =='n') || (ch == 'N'))
                    {
                        cleardevice();
                        startpage1();
                    }
                    else
                        continue;
                }
            }
            putimage(155,coord,buff5,COPY_PUT);
            putimage(391,coord,buff5,COPY_PUT);     //display other's car on first and third lane
            if (coord>=450 )
            {
                score=score+5;
                coord=1;
                srand(time(NULL));
go2:
                val1=rand()%3+1;
                val2=rand()%3+1;
                if (val1==val2) goto go2;
            }
        }
        if (val1!=3 && val2!=3)  //same as above, now for random value 1 and 2
        {
            coord=coord+carspeed;
            if (coord>=300 && (posn==1 || posn==2))
            {
                nosound();
                sound(40);
                delay(100);
                nosound();
                record(displayscore);
                cleardevice();
                setcolor(11);
                rectangle(50,50,600,400);
                setfillstyle(SOLID_FILL,GREEN);
                rectangle(40,40,610,410);
                floodfill(45,45,11);
                setfillstyle(SOLID_FILL,15);
                floodfill(55,55,11);
                setcolor(9);
                outtextxy(100,200,"Do you wish to play again: [Y/N]");
                rectangle(400,200,440,225);
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(405,205,9);
                while(1)
                {
                    ch=getch();
                    if ((ch=='y') || (ch=='Y'))
                        goto start;
                    else if((ch =='n') || (ch == 'N'))
                    {
                        cleardevice();
                        startpage1();
                    }
                    else
                        continue;
                }
            }
            putimage(155,coord,buff5,COPY_PUT);    //display others car on first and second lane
            putimage(273,coord,buff5,COPY_PUT);
            if (coord>=450 )
            {
                score=score+5;
                coord=1;
                srand(time(NULL));
go3:
                val1=rand()%3+1;
                val2=rand()%3+1;
                if (val1==val2)
                    goto go3;
            }
        }


        if (posn==1) //for players'car posn = 1 means first lane
        {
            putimage(155,375,buff3,COPY_PUT);   //put image in first lane
        }
        if (posn==2) putimage(278,375,buff3,COPY_PUT);  //like above
        if (posn==3) putimage(391,375,buff3,COPY_PUT);
        x++;

        if (x==6) x=2;   //this is related with displaying moving strips
        if (kbhit())
        {
            ch=getch();
            if (ch==27)             //Esc key
            {
                nosound();
                gotoxy(30,12);
                printf(" Sure to exit the game?" )   ;
                gotoxy(30,13);
                printf(" If yes, press Y");
                switch(getch())
                {
                case  'y':
                    cleardevice();
                    startpage1();
                case 'Y':
                    cleardevice();
                    startpage1();
                    //exit(0);
                }
            }
            if (ch==' ')   //space to pause
            {
                nosound();
                gotoxy(30,12);
                printf("Press any key to continue");
                getch();
                sound(100);

            }
            if (ch==0)
            {
                ch1=getch();
                switch(ch1)
                {
                case 75:
                    posn--;       //changing positions according to left and right arrow
                    break;
                case 77:
                    posn++;
                    break;
                }
            }
        }
        if (posn<1)
            posn=1;
        if (posn>3)
            posn=3;
        displayscore++;  //Score is continously increased by value 1
        nosound();

    }
}
