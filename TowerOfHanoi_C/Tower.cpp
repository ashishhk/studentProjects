
/**************************************************************************
		       Header File Inclusion
**************************************************************************/

#include     <stdio.h>
#include     <conio.h>
#include     <iostream.h>
#include     <graphics.h>
#include     <stdlib.h>
#include     <string.h>
#include     <e:\ashish\prg\header\support.h>
#include     <e:\ashish\prg\header\mouse.h>
/**************************************************************************
		      Globaly Declring the variable
**************************************************************************/

int maxx,maxy;
int bottom,x,y;
int towerb[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int towera[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int towerl[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int move[]={1,3,7,15,31,64};
int topb=-1,topa=-1,topl=-1;
int beg,aux,last,moves=0;
int beg1,aux1=0,last1=0;

char player[20]={""};
/**************************************************************************
	       Prototype of All Function Used Later
**************************************************************************/

int ok();
int help();
int hold();
int play();
void about();
void hanoi();
void start();
void reset();
int getkey();
int solution();
void welcome();
void mainmenu();
int tower(int,char,char,char);
void filllabel(int,int,int);
void handling(char,char,char);
/*********************************************3*****************************
	       Start Function Where The Execution starts
**************************************************************************/
int hold(int x1,int y1,int x2,int y2)
{
	int bottom,x,y;
	//cout<<x1<<" "<<x2<<" "<<y1<<"  "<<y2<<endl;
	buttonclick(x1,y1,x2,y2);
	sound(3000);delay(100);nosound();

	for(getmousepos(&bottom,&x,&y);(bottom & 1)==1;getmousepos(&bottom,&x,&y))
	 {
	    if(x<x1||x>x2||y<y1||y>y2)
	       {
	       //button(x1,y1,x2,y2);
	       return 0;
	       }
	 }
	 return 1;
}

int getkey()
{
   union REGS i,o;
   while(!kbhit())
   i.h.ah=0;
   int86(22,&i,&o);
   return(o.h.ah);
}
void start()
  {

	cleardevice();
	rect(5,5,635,475,7,1);
	out(maxx-100,50,"WELCOME",0,4,4);    //Welcome Screen
	out(maxx-100,400,"F1: Help",0,1,15);    //Welcome Screen
	out(maxx-200,400,"Esc: Exit",0,1,15);    //Welcome Screen

	mainmenu();
			 //main menu draw
	restrictmouseptr(5,5,635,475);       //Restricting Mouse
	showmouseptr();
       /*	buttonclick(maxx-100,maxy-100,maxx+100,maxy-70);
	button(maxx-100,maxy-100,maxx+100,maxy-70);   */
	fflush(0);
	int key;
    while(1)    		        //loop untill something selected
	{
	 showmouseptr();
	 getmousepos(&bottom,&x,&y);   //Mouse Position getting to Any Event
	 fflush(0);
	 if(kbhit())

	 {
	  char ch; ch=getch();
	 if(ch==59)
	 //if(hold(maxx-100,maxy-20,maxx+100,maxy+10)==0)
			  {hidemouseptr(); hold(maxx-100,maxy-20,maxx+100,maxy+10); help();
			  hidemouseptr();start();}
	   if(ch==27){
	   hidemouseptr();hold(maxx-100,maxy+60,maxx+100,maxy+90);cleardevice();closegraph(); _exit(0);}
	 }
	 if((bottom & 1)==1&&(x>=maxx-100&&x<=maxx+100))
		      {
		      reset();
		   /*Reseting and then Selcting Event And Recalling Satrt*/
		       if(y>=maxy-100&&y<=maxy-70)
			  {
			  if(hold(maxx-100,maxy-100,maxx+100,maxy-70))
			  {hidemouseptr(); reset(); play();}
			  hidemouseptr();start();}
		       else if(y>=maxy-60&&y<=maxy-30)
			  {
			  if(hold(maxx-100,maxy-60,maxx+100,maxy-30))
			  {hidemouseptr(); reset(); solution(); }
			  hidemouseptr();start();}
		       else if(y>=maxy-20&&y<=maxy+10)
			  {
			  if(hold(maxx-100,maxy-20,maxx+100,maxy+10))
			  {hidemouseptr();  help();}
			  hidemouseptr();start();}
		       else if(y>=maxy+20&&y<=maxy+50)
			  {
			  if(hold(maxx-100,maxy+20,maxx+100,maxy+50))
			  {hidemouseptr();  about();}
			  hidemouseptr();start();}
		       else if(y>=maxy+60&&y<=maxy+90)
			  {
			  if(hold(maxx-100,maxy+60,maxx+100,maxy+90))
			  {hidemouseptr();  closegraph();exit(0);}
			  else hidemouseptr(); start();}
		       }

	}
}
/**************************************************************************
	       Reseting all necessary variable
**************************************************************************/

void reset()
{
//towerb[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//towera[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//towerl[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

topb=-1,topa=-1,topl=-1,moves=0;
}
/**************************************************************************
	       Printing the Welcome Window
**************************************************************************/

inline void welcome()
{
     //******border generation********
	rect(5,5,635,475,8,3);
     //out(maxx-55,20,"WELCOME",4,3,14);
}
/**************************************************************************
		Printing the Main Menu Window
**************************************************************************/

void mainmenu()
{
     //******menu drawing**********
	button(maxx-100,maxy-100,maxx+100,maxy-70);
	   out(maxx-90,maxy-100,"Play",1,3,15);
	button(maxx-100,maxy-60,maxx+100,maxy-30);
	  out(maxx-90,maxy-60,"Solution",1,3,15);
	button(maxx-100,maxy-20,maxx+100,maxy+10);
	  out(maxx-90,maxy-20,"Help",1,3,15);
	button(maxx-100,maxy+20,maxx+100,maxy+50);
	  out(maxx-90,maxy+20,"About",1,3,15);
	button(maxx-100,maxy+60,maxx+100,maxy+90);
	  out(maxx-90,maxy+60,"Exit",1,3,15);
}

/**************************************************************************
		on clicking 'ok' performing below event
**************************************************************************/
int messok()
{
		 while(1)
		    {
		      getmousepos(&bottom,&x,&y);
		      fflush(0);
		      if(kbhit())
		      {if(getch()==13){ hold(270,240,320,260);hidemouseptr(); break;}}
		      if((bottom & 1)==1&&(x>=270&&x<=320)&&(y>=240&&y<=260))
				{ hold(270,240,320,260);hidemouseptr(); break;}
		    }
      return 0;
}
int ok()
{
	int bottom,x,y;
	 while(1)
	   {
	    getmousepos(&bottom,&x,&y);
	    fflush(0);
	    if(kbhit())
	    {if(getch()==8) {hold(185,420,260,450);hidemouseptr(); return 0;}}
	     if((bottom & 1)==1&&(x>=185&&x<=260)&&(y>=420&&y<=450))
	       { hold(185,420,260,450); hidemouseptr(); return 0;}
	   }
}

/**************************************************************************
	      Solving Problem by the User himself
**************************************************************************/
int play()
{
   int nofdisk=-1;
   top:               //Label Defining 'TOP' If there is Any Error in NOFDISK
   cleardevice();
   welcome();
   rect(50,20,500,50,9,1);
   out(60,20,"Hello",1,1,15);
   out(108,20,player,1,1,15);
   out(116+strlen(player)*8+8,20,"Enter No of Disks : ",1,1,15);
   gotoxy(58,3); cin>>nofdisk;
   if(nofdisk<1||nofdisk>13)
	{message("!ERORR","Hey are you mad","you cant do that");
	 int bottom,x,y;
		 showmouseptr();
		 messok();
		 goto top;
	 }

   int begdisk=nofdisk,auxdisk=0,lastdisk=0;
   for(int count=nofdisk,j=14;count!=0;)
	   {
	   towerb[++topb]=j--;count--;
	   }

   filllabel(begdisk,auxdisk,lastdisk);
   towerb[-1]=towera[-1]=towerl[-1]=20;
   char currtower;  int key=0;
   while(1)
      {
	showmouseptr();
	if(kbhit())
	{
	key=getkey();
	if(key==1)
	{ hidemouseptr();
	 message("Escape",player,"You are Looser");
	 int bottom,x,y;
		 showmouseptr();
		 messok();
		 return 0;

	}
	if(key==59)
		  {hidemouseptr();  help();
			  hidemouseptr();filllabel(begdisk,auxdisk,lastdisk);
				   continue;}

	}

	if(topl+1==nofdisk)
		{
		 if(move[nofdisk-1]==moves)
		 message("Congratulation!",player,"You have won");
		 else message("Sorry",player," You Loss Try Again");

		 int bottom,x,y;
		 messok();
		 return 0;
		}
	getmousepos(&bottom,&x,&y);

	if((bottom & 2)==2&&(y>=380&&y<=410))
	  {
	    if(x>=100&&x<=250)
	       {currtower='b';}
	    else if(x>=260&&x<=410)
	       {currtower='a';}
	    else if(x>=420&&x<=570)
	       {currtower='l';}
	  }
	if((bottom & 1)==1&&(y>=380&&y<=410))   //push the element in
	  {                              //First tower
	    if(x>=100&&x<=250)
	      {
		switch(currtower)
		  {
		       case 'b':  // errormessage();
				  // filllabel(begdisk,auxdisk,lastdisk);
				   continue;
		       case 'a': if(topa==-1)
				   {//errormessage();
				    //filllabel(begdisk,auxdisk,lastdisk);
				    continue;}
				  else
				   {
				    if(towerb[topb]<towera[topa])
				      continue;
				    towerb[++topb]=towera[topa--];
				    moves++;
				    filllabel(++begdisk,--auxdisk,lastdisk);
				    continue;}
			case 'l': if(topl==-1)
				   {//errormessage();
				   //filllabel(begdisk,auxdisk,lastdisk);
				   continue;
				   }
				 else
				   {if(towerb[topb]<towerl[topl])
				      continue;
				    towerb[++topb]=towerl[topl--];
				    moves++;
				    filllabel(++begdisk,auxdisk,--lastdisk);
				    continue;}
		  }
	      }
	    else if(x>=260&&x<=410) //push in second tower
	      {
		switch(currtower)
		  {
		       case 'b': if(topb==-1)
				   {//errormessage();
				    //filllabel(begdisk,auxdisk,lastdisk);
				   continue;}
				 else
				   {if(towera[topa]<towerb[topb])
				      continue;
				   towera[++topa]=towerb[topb--];
				   moves++;
				   filllabel(--begdisk,++auxdisk,lastdisk);
				    continue;}
		       case 'a':   //errormessage();
				   //filllabel(begdisk,auxdisk,lastdisk);
				   continue;
		       case 'l': if(topl==-1)
				   {//errormessage();
				   //filllabel(begdisk,auxdisk,lastdisk);
				   continue;
				   }
				 else
				   {if(towera[topa]<towerl[topl])
				      continue;
				   towera[++topa]=towerl[topl--];
				   moves++;
				   filllabel(begdisk,++auxdisk,--lastdisk);
				   continue;}

	      }}

	   else if(x>=420&&x<=570)   //push in to third tower
	      {
		 switch(currtower)
		   {
		       case 'b': if(topb==-1)
				   {//errormessage();
				   //filllabel(begdisk,auxdisk,lastdisk);
				   continue;}
				 else
				   {if(towerl[topl]<towerb[topb])
				      continue;
				   towerl[++topl]=towerb[topb--];
				    moves++;
				    filllabel(--begdisk,auxdisk,++lastdisk);
				    continue;}
		       case 'a': if(topa==-1)
				   {//errormessage();
				   //filllabel(begdisk,auxdisk,lastdisk);
				   continue;
				   }
				 else
				   {if(towerl[topl]<towera[topa])
				      continue;
				   towerl[++topl]=towera[topa--];
				   moves++;
				   filllabel(begdisk,--auxdisk,++lastdisk);
				   continue;}
			case 'l':   //errormessage();
				   //filllabel(begdisk,auxdisk,lastdisk);
				   continue;}
		   }
	      }
	}


}

/**************************************************************************
		Showing to user By Disk MOvement
**************************************************************************/

void filllabel(int begdisk,int auxdisk,int lastdisk)
{
	 int height=360,h,nofdisk=1;
	 int stack[]={14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	 cleardevice();
	 welcome();
	 button(100,380,250,410);
	    out(110,380,"Click",1,3,15);
	 button(260,380,410,410);
	    out(270,380,"Click",1,3,15);
	 button(420,380,570,410);
	    out(430,380,"Click",1,3,15);
	 rect(50,20,500,50,7,1);
	 textbackground(9);
	 gotoxy(10,3); cout<<" beg="<<topb+1<<","<<towerb[topb];
	 gotoxy(20,3); cout<<" auix="<<topa+1<<","<<towera[topa];
	 gotoxy(30,3); cout<<" last="<<topl+1<<","<<towerl[topl];
	 gotoxy(45,3); cout<<"Moves="<<moves;
	      if(begdisk>=auxdisk&&begdisk>=lastdisk) nofdisk=begdisk;
	      else {if(auxdisk>=begdisk&&auxdisk>=lastdisk) nofdisk=auxdisk;
	      else nofdisk=lastdisk; }

	 for(h=1;h!=nofdisk;h++) height-=21;

	 int xbeg=170,xaux=330,xlast=490,i=2;
	 if(nofdisk>11) i=4;

	 rect(xbeg-3,height,180-i,380,7,1);
	 rect(xaux-3,height,340-i,380,7,1);
	 rect(xlast-3,height,500-i,380,7,1);

	 int xrad;i=0;
	 for(h=1,height=370;h<=begdisk;h++)
	     {
	     for(xrad=65,i=0;;)
		{
		  if(towerb[h-1]!=stack[i])
		   xrad-=9;
		  else break;
		   i++;
		}

	     disk(xbeg,height,xrad,7,12);
	     height-=20;
	     //xrad-=8;
	     }
	  for(h=1,height=370;h<=auxdisk;h++)
	     {
	     for(i=0,xrad=65;;)
		{
		  if(towera[h-1]!=stack[i])
		   xrad-=9;
		  else break;
		   i++;
		}

	     disk(xaux,height,xrad,7,12);
	     height-=20;
	    // xrad-=8;
	     }
	  for(h=1,height=370;h<=lastdisk;h++)
	     {
	     for( i=0,xrad=65;;)
		{
		  if(towerl[h-1]!=stack[i])
		   xrad-=9;
		  else break;
		   i++;
		}

	     disk(xlast,height,xrad,7,12);
	     height-=20;
	     //xrad-=8;
	     }
}

/**************************************************************************
		Auto Solving of Problem For User Hint
**************************************************************************/
int solution()
{
	top:
	cleardevice();
	welcome();
	rect(50,20,500,50,9,1);
	out(60,20,"Enter the Number of Disks : ",1,1,15);
	gotoxy(58,3); int nofdisk; cin>>nofdisk;
	if(nofdisk<1||nofdisk>13)
	{
	showmouseptr();
	message("!ERORR","Hey! Are You Mad","you cannot do that");
	while(1)
	   {

	    getmousepos(&bottom,&x,&y);
	    if((bottom & 1)==1&&(x>=270&&x<=320)&&(y>=240&&y<=260))
	       { hidemouseptr(); goto top;}
	    }
	 }
	for(int count=nofdisk,j=14;count!=0;)
	   {
	   towerb[++topb]=j--;count--;
	   }

	 beg1=nofdisk,aux1=0,last1=0;
	char begdisk='b',auxdisk='a',lastdisk='l';
	filllabel(beg1,aux1,last1);
	sleep(1);
	//hidemouseptr();
	tower(nofdisk,begdisk,auxdisk,lastdisk);
	message("!Complete",player,"It has Complited ");
	showmouseptr();
	int bottom,x,y;
	messok();
       return 0;
}
void handling(char begdisk,char lastdisk)
{

		if(lastdisk=='l')
		  {	if(begdisk=='b') {towerl[++topl]=towerb[topb--];
					filllabel(--beg1,aux1,++last1);}

			if(begdisk=='a') {towerl[++topl]=towera[topa--];
					  filllabel(beg1,--aux1,++last1);}

		  }
		if(lastdisk=='a')
		  {	if(begdisk=='b') {towera[++topa]=towerb[topb--];
					  filllabel(--beg1,++aux1,last1);}

			if(begdisk=='l') {towera[++topa]=towerl[topl--];
					  filllabel(beg1,++aux1,--last1);}
		  }
		if(lastdisk=='b')
		   {	if(begdisk=='a') {towerb[++topb]=towera[topa--];
					 filllabel(++beg1,--aux1,last1);}

			if(begdisk=='l') {towerb[++topb]=towerl[topl--];
					 filllabel(++beg1,aux1,--last1);}

		   }
}
/**************************************************************************
		Tower Function For Recursing of Function
**************************************************************************/
tower(int n,char begdisk,char auxdisk,char lastdisk)
{
	if(n==1)
	{
		delay(1000);
		handling(begdisk,lastdisk);
		return 0;
	}
	tower(n-1,begdisk,lastdisk,auxdisk);
		sleep(1);
		handling(begdisk,lastdisk);
	tower(n-1,auxdisk,begdisk,lastdisk);
	return 0;
}
/**************************************************************************
		Showing Something  About me
**************************************************************************/
void about()
{
	cleardevice();
	welcome();
	hanoi();
	rect(maxx-100,20,maxx+100,50,7,1);
	    out(maxx-90,20,"ABOUT",1,3,15);
	rect(280,90,620,450,7,1);
	  out(290,110,"Programer : Ashish Dadhore ",0,1,15);delay(10);
	  out(290,130,"       by : Eduord Lucas",0,1,15);delay(10);
	  out(388,150,"ashishhk@gmail.com",0,1,15); delay(10);
	  out(388,170,"",0,1,15);delay(10);
	  out(388,200,"B.Sc.IIYear",0,1,15); delay(10);
	  out(388,220,"Computer(Hons)",0,1,15);
	  out(388,240,"IEHE,Bhopal.",0,1,15);
							   delay(10);
	  out(310,270,"\"Each of us has a Fire in our heart",0,1,15); delay(10);
	  out(310,285," for something It\'s our goal in life ",0,1,15);delay(10);
	  out(310,300," to find it and keep it lit\"",0,1,15); delay(10);
	  out(310,330,"\"Creativity is inventing, experime-",0,1,15);delay(10);
	  out(310,345,"nting,growing,taking risk, breaking",0,1,15); delay(10);
	  out(310,360,"rules,making mistakes and having fun.\"",0,1,15);delay(10);
	  out(310,375,"",0,1,14);
	 button(185,420,260,450);
	 out(190,420,"BACK",1,3,15);
	 showmouseptr();
	 ok();
	}
/**************************************************************************
		Help Menu*********************
**************************************************************************/

int help()
{
	cleardevice();
	welcome();
	hanoi();
	rect(maxx-100,20,maxx+100,50,7,1);
	    out(maxx-90,20,"Help",1,3,15);
	rect(280,90,620,450,7,1);
	  out(290,110,"  You are given to solve a Problem ",0,1,15); delay(10);
	  out(290,130,"  named as \"Tower of Hanoi\". you ",0,1,15); delay(10);
	  out(290,150,"  have to move all the disk of 1st ",0,1,15); delay(10);
	  out(290,170,"  tower to third Tower one by one, ",0,1,15); delay(10);
	  out(290,190,"  But you are not allowed to move  ",0,1,15); delay(10);
	  out(290,210,"  two or more disks simultaniuslly  ",0,1,15);delay(10);
	  out(290,230,"  And also not allowed to put large ",0,1,15);delay(10);
	  out(290,250,"  disk on the smaller one,You have ",0,1,15); delay(10);
	  out(290,270,"  to click on base of tower whose ",0,1,15);  delay(10);
	  out(290,290,"  disk has to be selected,then click",0,1,15);delay(10);
	  out(290,310,"  other base, where disk has to move",0,1,15);delay(10);
	  out(290,330,"  Onece all disks have moved to third",0,1,15);delay(10);
	  out(290,350,"  tower Game will be Over.",0,1,15);  delay(10);
	  out(290,370,"  Press F1         :Help.",0,1,15);  delay(10);
	  out(290,390,"        Esc        :Exit",0,1,15);  delay(10);
	  out(290,410,"        Enter      :Ok.",0,1,15);  delay(10);
	  out(290,430,"        Backspace  :Back.",0,1,15);  delay(10);

	  button(185,420,260,450);
	    out(190,420,"BACK",1,3,15);
	  showmouseptr();
	ok();
	return 0;
}
void hanoi()
{
	  out(30,50,"T",4,8,1);                         out(150,50,"H",4,8,1);
	  out(30,120,"O",4,8,1);                         out(150,120,"A",4,8,1);
	  out(30,190,"W",4,8,1);  out(90,190,"O",4,8,1); out(150,190,"N",4,8,1);
	  out(30,260,"E",4,8,1);  out(90,260,"F",4,8,1); out(150,260,"O",4,8,1);
	  out(30,330,"R",4,8,1);                         out(150,330,"I",4,8,1);

}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	maxx=getmaxx()/2;
	maxy=getmaxy()/2;
	start();
}
/**************************************************************************
				  THANK YOU
**************************************************************************/

