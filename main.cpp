#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include<MMSystem.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
void followhead(int x,int y, int i,int ax[],int ay[],int eat)
{
int x1=ax[i];
int y1=ay[i];
setcolor(0);
arc(x,y,0,360,10);
setfillstyle(SOLID_FILL,2);
floodfill(x,y,0);
ax[i]=x;
ay[i]=y;
i++;
if(i<=eat)

    followhead(x1,y1,i,ax,ay,eat);

}






void setfield()
{
int width;
width=40;
setcolor(0);
line(width,width,20*((getmaxx()-width)/20),width);
line(width,width,width,20*((getmaxy()-width)/20));
line(width,20*((getmaxy()-width)/20),20*((getmaxx()-width)/20),20*((getmaxy()-width)/20));
line(20*((getmaxx()-width)/20),20*((getmaxy()-width)/20),20*((getmaxx()-width)/20),width);

}





bool endgame()
{
        cleardevice();
        settextstyle(BOLD_FONT,HORIZ_DIR,10);
        char b[100]="GAME OVER!";
        for(int i=0;i<=300;i=i+10)
        {
        outtextxy(300,i,b);
        delay(50);
        cleardevice();
        }
        while(1)
        {
        settextstyle(BOLD_FONT,HORIZ_DIR,4);
        outtextxy(400,400,"NEW GAME:Press F7");
        outtextxy(400,500,"QUIT:Press Esc");
        if(GetAsyncKeyState(VK_F7))
        {
        cleardevice();
         return false;
         }
        if(GetAsyncKeyState(VK_ESCAPE))
    return true;
        }

}







void drawbar(int x1,int y1,int x3,int y3,int score,int eat,int ax[],int ay[])
{
setfield();
char a[10];
followhead(x1,y1,0,ax,ay,eat);




setcolor(0);
arc(x3,y3,0,360,10);
setfillstyle(SOLID_FILL,4);
floodfill(x3,y3,0);
setcolor(1);
sprintf(a,"SCORE: %d",score);
settextstyle(BOLD_FONT,HORIZ_DIR,4);
outtextxy(0,0,a);
delay(75);
cleardevice();

}





bool ifeat(int x1,int y1,int x3,int y3 )
{
    if(x1==x3&&y1==y3)
        return true;
        else
        return false;
}













void modernsnake()
{
while(1){

settextstyle(BOLD_FONT,HORIZ_DIR,8);
outtextxy(300,300,"THE MODERN SNAKE!");
settextstyle(BOLD_FONT,HORIZ_DIR,4);
outtextxy(250,400,"PRESS ANY OF THE ARROW KEYS TO START THE GAME");
if(GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState(VK_UP))
{cleardevice();
    break;}
    else
    continue;
    }
}







void begingame()
{
    char b[100];
    int i;
    for(i=1;i<=10;i++)
    {settextstyle(BOLD_FONT,HORIZ_DIR,8);
    sprintf(b,"GAME BEGINS IN %d SECONDS",i);
    outtextxy(100,300,b);
    Beep(1200,1000);
    delay(1000);
    cleardevice();

    }
    modernsnake();

}









bool gameover(int x1,int y1,int ax[],int ay[],int eat)
{int a=0;
if(x1<60||y1<60||y1>20*((getmaxy()-60)/20)||x1>20*((getmaxx()-60)/20))
a++;

for(int i=1;i<=eat+1;i++)
if((x1==ax[i]&&y1==ay[i]))
{a++;
break;}


if(a!=0)
return true;

else
return false;

}




void gamepause()
{
    while(1)
    {
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    outtextxy(500,300,"GAME PAUSED!");
    if(GetAsyncKeyState(VK_ESCAPE))
        break;
    }

}





int main()
{
int ax[1000];
int ay[1000];
time_t t;
unsigned int seedval;
seedval=(unsigned)time(&t);
srand(seedval);
int gd=DETECT,gm;
int x1,y1,x3,y3;
    int speed;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setbkcolor(14);
    int score,eat;

begingame();
while(1)
{

modernsnake();
setfield();
ax[0]=100,ay[0]=100;
x1=100,y1=100;
eat=0,score=0;
speed=20;

x3=20*(rand()%(getmaxx()-120)/20)+60;
y3=20*(rand()%(getmaxy()-120)/20)+60;





    while(!gameover(x1,y1,ax,ay,eat))//loop for the whole game//
{

    if(GetAsyncKeyState(VK_RIGHT))
{


    while(!GetAsyncKeyState(VK_DOWN)&&!GetAsyncKeyState(VK_UP)&&!gameover(x1,y1,ax,ay,eat))
    {

     x1+=speed;

    drawbar(x1,y1,x3,y3,score,eat,ax,ay);
    if(ifeat(x1,y1,x3,y3))
    {Beep(1000,75);
        eat++;
        x3=20*(rand()%(getmaxx()-120)/20)+60;
        y3=20*(rand()%(getmaxy()-120)/20)+60;
        score+=5;
    }
    if(GetAsyncKeyState(VK_SPACE))
    gamepause();
    }
}




else if(GetAsyncKeyState(VK_LEFT))
{


    while(!GetAsyncKeyState(VK_DOWN)&&!GetAsyncKeyState(VK_UP)&&!gameover(x1,y1,ax,ay,eat))
   {

       x1-=speed;

       drawbar(x1,y1,x3,y3,score,eat,ax,ay);
        if(ifeat(x1,y1,x3,y3))
    {   Beep(1000,75);
        eat++;
        x3=20*(rand()%(getmaxx()-120)/20)+60;
        y3=20*(rand()%(getmaxy()-120)/20)+60;
        score+=5;
    }
    if(GetAsyncKeyState(VK_SPACE))
    gamepause();
    }

}


else if(GetAsyncKeyState(VK_DOWN))
{



while(!GetAsyncKeyState(VK_LEFT)&&!GetAsyncKeyState(VK_RIGHT)&&!gameover(x1,y1,ax,ay,eat))
   {

    y1+=speed;

    drawbar(x1,y1,x3,y3,score,eat,ax,ay);
     if(ifeat(x1,y1,x3,y3))
    {Beep(1000,75);
    eat++;
       x3=20*(rand()%(getmaxx()-120)/20)+60;
        y3=20*(rand()%(getmaxy()-120)/20)+60;
        score+=5;
    }
    if(GetAsyncKeyState(VK_SPACE))
    gamepause();

}

}

else if(GetAsyncKeyState(VK_UP))
{

while(!GetAsyncKeyState(VK_LEFT)&&!GetAsyncKeyState(VK_RIGHT)&&!gameover(x1,y1,ax,ay,eat))
    {

        y1-=speed;

        drawbar(x1,y1,x3,y3,score,eat,ax,ay);
         if(ifeat(x1,y1,x3,y3))
    {Beep(1000,75);
    eat++;
    x3=20*(rand()%(getmaxx()-120)/20)+60;
        y3=20*(rand()%(getmaxy()-120)/20)+60;

        score+=5;

    }
    if(GetAsyncKeyState(VK_SPACE))
    gamepause();
    }

}


else
{


while(!GetAsyncKeyState(VK_LEFT)&&!GetAsyncKeyState(VK_DOWN)&&!GetAsyncKeyState(VK_UP)&&!GetAsyncKeyState(VK_RIGHT)&&!gameover(x1,y1,ax,ay,eat))
    {
   drawbar(x1,y1,x3,y3,score,eat,ax,ay);
    if(ifeat(x1,y1,x3,y3))
    {   eat++;
        x3=20*(rand()%(getmaxx()-120)/20)+60;
        y3=20*(rand()%(getmaxy()-120)/20)+60;
        score+=5;
    }
    if(GetAsyncKeyState(VK_SPACE))
    gamepause();
     }

    }
       }




    if(endgame()==true)
        break;
    }




    getch();
    closegraph();
    return 0;
}

