#include "Head.h"
void Drecord()
{
    char fname[50];
    int score, numRecords = 0, repeat = 1, x_co = 10, y_co = 10, y_co1 = 10, i, j;
    FILE *fptr;
    char *name;
    if ((fptr = fopen("record.txt","r")) == NULL)
    {
        printf("Error: Loading the file\n");
        exit(1);
    }
    settextstyle(10,0,3);
    outtextxy(100,50,"MOST WANTED RACERS");
    //setcolor(5);
    //line(51,100,52k0,100);
    setcolor(7);
    rectangle(50,110,600,120);
    setfillstyle(5,7);
    floodfill(51,111,7);
    setlinestyle(0,1,3);
    setcolor(RED);
    line(51,180,270,180);
    line(51,230,270,230);
    line(51,280,270,280);
    line(51,330,270,330);
    line(52,380,270,380);

    line(380,180,599,180);
    line(380,230,599,230);
    line(380,280,599,280);
    line(380,330,599,330);
    line(380,380,599,380);
    setlinestyle(0,1,1);

    while(1)
    {
        if(fscanf(fptr,"%s %d",&fname, &score) == EOF)
            break;
        numRecords++;
    }

    if(numRecords == 0)
    {
        setcolor(5);
        settextstyle(3,0,4);
        outtextxy(100,200,"Sorry,No records Available!!!");
    }
    rewind(fptr);

    while ((repeat <= numRecords) && (repeat <= 10))
    {
        if(repeat <= 5)
        {
            fscanf(fptr, "%s %d", &fname, &score);
            gotoxy(x_co, y_co);
            printf("Name:\t  %s\n",fname);
            y_co++;
            gotoxy(x_co, y_co);
            printf("Score:   %d\n\n",score);
            y_co += 2;
            repeat++;
        }
        else if(repeat > 5 && repeat <= 10)
        {
            x_co = 305;
            fscanf(fptr, "%s %d", &fname, &score);
            gotoxy(x_co, y_co1);
            printf("Name:    %s\n",fname);
            y_co1++;
            gotoxy(x_co, y_co1);
            printf("Score:   %d\n\n",score);
            y_co1 += 2;
            repeat++;
        }

    }
}

void record(int displayscore)
{
    int loop;
    char name[50], ch;
    FILE *fptr;
    if ((fptr = fopen("record.txt","a+")) == NULL)
    {
        printf("Error: Opening the file\n");
        exit(1);
    }
    setcolor(WHITE);

    settextstyle(3,0,10);
    outtextxy(100,150,"CRASH!!!");
    delay(2000);
    cleardevice();
    setcolor(11);
    rectangle(50,50,600,400);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(40,40,610,410);
    floodfill(45,45,11);
    setfillstyle(SOLID_FILL,15);
    floodfill(55,55,11);
    setcolor(5);
    settextstyle(3,0,1);
    outtextxy(220,160,"Enter Name:");
    setcolor(11);
    rectangle(220,188,395,213);
    rectangle(215,183,400,218);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(216,184,11);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(225,190,11);
    gotoxy(29,13);
    gets(name);
    name[0] = toupper(name[0]);
    for(loop = 0; loop < strlen(name); loop++)
    {
        if((name[loop]) == ' ')
            break;
    }
    name[loop + 1] = toupper(name[loop + 1]);
    if(strlen(name) > 0)
    {
        fputs(name,fptr);
        fputs("\n",fptr);
        fprintf(fptr, "%d", displayscore);
        fputs("\n",fptr);
    }
    fclose(fptr);

    cleardevice();
    setcolor(11);
    rectangle(50,50,600,400);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(40,40,610,410);
    floodfill(45,45,11);
    setfillstyle(SOLID_FILL,15);
    floodfill(55,55,11);
    setcolor(11);
    rectangle(215,200,400,230);
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(225,215,11);
    gotoxy(29,14);
    printf("RECORD SAVED!!");
    delay(1000);
}

void soundd(void)
{
    int i;
    setcolor(13);
    rectangle(0,0,getmaxx(),getmaxy());
    setcolor(13);
    rectangle(5,5,getmaxx()-5,getmaxy()-5);
    setcolor(13);
    rectangle(10,10,getmaxx()-10,getmaxy()-10);
    setcolor(11);
    rectangle(15,15,getmaxx() - 15, getmaxy() - 15);
    setfillstyle(SOLID_FILL,15);
    floodfill(getmaxx()/2, getmaxy()/2, 11);
    for(i=1; i<5; i++)
    {
        sound (i*50);
        setcolor(i);
        settextstyle(DEFAULT_FONT, HORIZ_DIR,i);
        outtextxy(60,110,"PRESENTED");
        outtextxy(300,200,"BY");
        outtextxy(330,300,"SAF_404");
        setcolor(15);
        delay(1000);
        outtextxy(60,110,"PRESENTED");
        outtextxy(300,200,"BY");
        outtextxy(330,300,"SAF_404");
    }
    nosound();
}



void display(void)
{
    int i,x=0,s=1;
    for(i=1; i<8; i++)
    {
        int k,l;
        setbkcolor(15);
        setcolor(15);
        cleardevice();
        for(k=0;k<=5;k++)
        {
            setcolor(GREEN);
            rectangle(k,k,getmaxx()-k,getmaxy()-k);
        }

        sound(i*500);
        setcolor(i);
        settextstyle(DEFAULT_FONT, HORIZ_DIR,i);
        outtextxy(60,100,"DEATH");
        outtextxy(150,300,"RACE");
        rectangle(0+x,200,100+x,250);
        circle(25+x,260,10);
        circle(70+x,260,10);
        x=x+100;
        delay(250);
        s++;
    }
    nosound();
    cleardevice();
    setbkcolor(0);
}



void main (void)
{
    int driver=DETECT,mode;
    initgraph(&driver,&mode,"C:\\tc\\bgi");
    soundd();
    delay(100);
    display();
    startpage1();
    closegraph();
}

