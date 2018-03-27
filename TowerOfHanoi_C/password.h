#include<graphics.h>
void passgraph()
{
	    char ch[20];//={"ashish"};
	    char pass[20]={"ashish"};
	    int tt=235;int t=0;
	    int gdriver=DETECT,gmode;
	    initgraph(&gdriver,&gmode,"c:\\tc\\bgi");


	re:
	    cleardevice();
	    settextstyle(3, 0, 3);
	    setcolor(14);

		//rectangle(220,255,459,145);
	    rectangle(225,250,454,150);
	    setfillstyle(1,8);
	    floodfill(235,170,14); setcolor(15);
	    outtextxy(235,170,"Enter the Password");

	    for(t=0,tt=235;;t++,tt+=10)
		{
			ch[t]=getch();
			if(ch[t]==27)  exit(0);
			if(ch[t]==13){ ch[t]='\0';break;}
			if(ch[t]==8)
			{
			if(tt==235) continue;
			tt-=10;
			outtextxy(tt,195," ");
			tt-=10;
			t-=2;
			}
			else outtextxy(tt,195,"*");
		}
	    if(strcmp(ch,pass)!=0)
		{
			settextstyle(3, 0, 1);
			outtextxy(235,220,"WRONG PASSWORD!");
			outtextxy(235,240,ch);

			getch();
			goto re;
		}

	    fflush(0);
}
int passtext()
{
	    char ch[20];//={"ashish"};
	    char pass[20]={"ashish"};
	    int t=0;
	    window(10,5,30,25);
	    printf("Enter the Password");
	    for(t=0;;t++)
		{
			ch[t]=getch();
			if(ch[t]==27)  break;
			if(ch[t]==13){ ch[t]='\0';break;}
			if(ch[t]==8)
			{
			printf("\b");
			t-=2;
			}
			else printf("*");
		}
	    if(strcmp(ch,pass)!=0)
	    return 1;
	    return 0;
}






