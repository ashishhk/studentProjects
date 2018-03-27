//#include   <e:\ashish\program1\header\mouse.h>

#include<dos.h>
#define BLK 0
#define BLU 1
#define G 2
#define C 3
#define R 4
#define M 5
#define B 6
#define LGR 7
#define DGR 8
#define LB 9
#define LG 10
#define LC 11
#define LR 12
#define LM 13
#define Y 14
#define W 15

void rect(int l,int t,int r,int d,int border,int fill)
{
	setcolor(border);
	rectangle(l,t,r,d);
	setfillstyle(1,fill);
	floodfill(l+1,t+1,border);

}
void button(int l,int t,int r,int d)
{
       setcolor(W);
	  line(l,t,r,t);
	  line(l+1,t,r,t);
	  line(l,t,l,d);
      setcolor(0);
	  line(r,t,r,d);
	  line(r+1,t,r+1,d);
	  line(l,d,r,d);
}
void buttonclick(int l,int t,int r,int d)
{
       setcolor(0);
	  line(l,t,r,t);
	  line(l+1,t,r,t);
	  line(l,t,l,d);
      setcolor(W);
	  line(r,t,r,d);
	  line(r+1,t,r+1,d);
	  line(l,d,r,d);
}

void out(int x, int y, char * string,int texttype, int size,int color)
{
	setcolor(color);
	settextstyle(texttype,0,size);
	outtextxy(x,y,string);
}
void outv(int x, int y, char * string,int texttype, int size,int color)
{
	setcolor(color);
	settextstyle(texttype,1,size);
	outtextxy(x,y,string);
}
void disk(int x,int y,int xrad,int border,int fill)
{
      setcolor(border);
      setfillstyle(1,fill);
      fillellipse(x,y,xrad,10);
      ellipse(x,y-1,180,360,xrad,10);
      ellipse(x,y-2,180,360,xrad,10);

      //outtextxy(x-8,y-10,value);

}
void message(char *title,char *note,char *note1)
{
	rect(226,170,390,280,1,1);
	button(226,170,390,280);
	button(228,173,387,203);
	  out(233,173,title,0,1,15);
	out(233,213,note,0,1,15);
	out(233,223,note1,0,1,15);
	button(270,240,320,260);
	out(280,244,"OK",0,1,15);
	sound(250);
	delay(50);
	nosound();
}
//message(){}

