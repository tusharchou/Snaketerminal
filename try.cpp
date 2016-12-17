#include<iostream>
#include<ncurses.h>	
#include<unistd.h>
#include<cstdlib>
using namespace std;
int main()
{
initscr();
WINDOW*win=newwin(75, 75, 3, 2);
raw();
noecho();
curs_set(FALSE); 
int a[75],b[75];//storing snake coordinates
int fox=16;	//storing food coordinates
int foy=10;	//storing food coordinates
int l=10;	//initializing lenght
int jk=0,mn=0,g,f;//flag values
int k=3;	//flag value
//-------------------------------------------------------------------------------------------------------------------------------------
 for(int i=0;i<75;i++)//BOUNDARY FUNCTION
	{
	for(int j=0;j<75;j++)
		{
			if(i==0||j==0||i==74||j==74)
			{wmove(win,j,i);
			wprintw(win,"#");}
			
		}
	}
 wrefresh(win);
 getch();

 
//------------------------------------------------------------------------------------------------------------------------------------
	
 for(int i=0;i<l;i++)		//PRINTING SNAKE FOR FIRST TIME
	{
		a[i]=i+2;
		b[i]=10;		
	}
	
	for(int i=0;i<l;i++)		
	{	
		wmove(win,b[i],a[i]);
		wprintw(win,"*");
	}
	wmove(win,foy,fox);
	wprintw(win,"*");
	getch();
	wrefresh(win);
	
//------------------------------------------------------------------------------------------------------------------------------------
 for(;;)
	{ 	int z;
		int f=a[0]; int g=b[0];		//MOVEMENT FUNCTION
		for(int i=0;i<l-1;i++)		 						
		{
			a[i]=a[i+1];
			b[i]=b[i+1];
		}
	
		keypad(stdscr,TRUE);		
		nodelay(stdscr,TRUE);
		z=getch();
			switch(z)
			{
				 case KEY_UP:if(k==2)	
						{
							k=2;
						}
					     else
						{
							k=5;	
						}
        		            	     break;
        		         case KEY_DOWN:if(k==5)
						{
							k=5;
						}
					     else
						{
							k=2;
						}
        		            	     break;
        		            	
        		         case KEY_RIGHT:if(k==1)
						{
							k=1;
						}
					     else
						{
							k=3;
						}
        		            	     break;
        		            	
        		         case KEY_LEFT:if(k==3)
						{
							k=3;
						}
					     else
						{
							k=1;
						}
        		            	     break;
        		        	
			}
			if(k==5)
			{
				b[l-1]-=1;
			}
			if(k==2)
			{
				b[l-1]+=1;
			}
			if(k==3)
			{
				a[l-1]+=1;
			}
			if(k==1)
			{
				a[l-1]-=1;
			}
//----------------------------------------------------------------------------------------------------------------------------------
		wmove(win,g,f);
		wprintw(win," ");	//PRINTING SNAKE AFTER UPDATING
		for(int i=0;i<l;i++)	
			{	
				wmove(win,b[i],a[i]);
				wprintw(win,"*");
					
			}
		wrefresh(win);
//-----------------------------------------------------------------------------------------------------------------------------------
		if(mn==1)			//FOOD FUNCTION
		{
			label2:
			wmove(win,foy,fox);   
			wprintw(win," ");
			wrefresh(win);	
			srand ( time(NULL) );
			int v=1+rand()%68;
			int bv=1+rand()%68;
			for(int i=0;i<l;i++)
				{	
					if(v==a[i]&&bv==b[i])
					goto label2;
				}
			fox=v;
			foy=bv;	
			wmove(win,foy,fox);   
			wprintw(win,"*");
			wrefresh(win);	
			getch();
				
			
		}
		usleep(600000);
//----------------------------------------------------------------------------------------------------------------------------------
		if(fox==a[l-1]&&foy==b[l-1])	//UPDATE FUNCTION
		{	
			l+=1;
			int mn=1;
			
		}
//------------------------------------------------------------------------------------------------------------------------------------
		int gh;				//GAME OVER FUNCTION
		for(int i=0;i<l-2;i++)
		{	
			if(a[l-1]==a[i])		
			 gh=1;	
		}
		if(a[l-1]==74||b[l-1]==74||a[l-1]==1||b[l-1]==1)	
		{
			
			system("CLEAR");
			
			cout<<"---------------------------------------GAME OVER---------------------------------------------";
			jk=1;
			
		}
		
		else if(gh==1)
		{
			system("CLEAR");
			
			cout<<"----------------------------------------GAME OVER--------------------------------------------";
			jk=1;
		}
//----------------------------------------------------------------------------------------------------------------------------------------
		if(jk==1)
		goto end;
	}
		end:
		
		return 0;
}	
