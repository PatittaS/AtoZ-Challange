#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
//windowfunction
void casewindow();
void gotoxy(int,int);
void background();
void window();
void textcolor(int);

//processfunction
void arrow(int,int);
void move(int,int,int);
void stage();
void stage1();
void score();
void help();
void square(int,int,int,int,int);

int main()
{
	bgcolor(11,0);
	window();
	return 0;
}
COORD coord = {0,0};
void gotoxy(int x, int y)
{
	coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void casewindow()
{
	int i,j,k;
	for(j=1;j<=80;j++)
		printf("\xcd");
	gotoxy(0,0);
	printf("%c",201);
	for(k=1;k<=23;k++)
	{
		gotoxy(0,k);
		printf("%c\n",186);
	}
	gotoxy(79,0);
	printf("%c",187);
	for(k=1;k<=23;k++)
	{
		gotoxy(79,k);
		printf("%c",186);
	}
	for(j=0;j<=78;j++)
	{
		gotoxy(j,23);
		printf("\xcd");
	}
	gotoxy(0,23);
	printf("%c",200);
		gotoxy(79,23);
	printf("%c",188);
}
void background()
{
	int i,j,k;
	for(i=1;i<=22;i=i+3)
	{
		for(j=1;j<=78;j=j+3)
		{
			if ((i+j)%2!=0){
			gotoxy(j,i);
			printf("+");	
			}
			
		}
		
	}
}
void square(int a,int b,int c,int d,int y)//y=place,a=startleft,b=lenght,c=startdown,d=height
{
	int i,j,k;
	for(j=a;j<=b;j++)//line above horizon
	{
		gotoxy(j,y);
		printf("\xcd");
	}
	gotoxy(a,y);//corner above right
	printf("%c",201);
	for(k=c;k<=d;k++)//line vertical right
	{
		gotoxy(a,k);
		printf("%c\n",186);
	}
	gotoxy(b,y);
	printf("%c",187);
	for(k=c;k<=d;k++)//vertical left
	{
		gotoxy(b,k);
		printf("%c",186);
	}
	for(j=a;j<=b;j++)//under line
	{
		gotoxy(j,d);
		printf("\xcd");
	}
	gotoxy(a,d);
	printf("%c",200);
	gotoxy(b,d);
	printf("%c",188);
}
void window()
{
	//SetColorAndBackground(11,15);
	casewindow();
	background();
	//word AtoZ
	gotoxy(23,3); printf("%c%c",219,219);
	gotoxy(22,4); printf("%c%c%c%c",219,219,219,219);
	gotoxy(21,5); printf("%c%c",219,219);
	gotoxy(25,5); printf("%c%c",219,219);
	gotoxy(20,6); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(19,7); printf("%c%c",219,219);
	gotoxy(18,8); printf("%c%c",219,219);
	gotoxy(27,7); printf("%c%c",219,219);
	gotoxy(28,8); printf("%c%c",219,219);
	gotoxy(35,5); printf("%c%c",219,219);
	gotoxy(33,6); printf("%c%c%c%c%c%c",219,219,219,219,219,219);
	gotoxy(35,7); printf("%c%c",219,219);
	gotoxy(35,8); printf("%c%c",219,219);
	gotoxy(43,5); printf("%c%c",219,219);
	gotoxy(41,6); printf("%c%c",219,219);
	gotoxy(45,6); printf("%c%c",219,219);
	gotoxy(41,7); printf("%c%c",219,219);
	gotoxy(45,7); printf("%c%c",219,219);
	gotoxy(43,8); printf("%c%c",219,219);
	gotoxy(52,3); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(52,8); printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
	gotoxy(58,4); printf("%c%c",219,219);
	gotoxy(56,5); printf("%c%c",219,219);
	gotoxy(54,6); printf("%c%c",219,219);
	gotoxy(52,7); printf("%c%c",219,219);
	gotoxy(10,10);
	printf("                                                           ");
	//word CHALLANGE
	gotoxy(10,13);
	printf("     C     H     A     L     L     A     N     G     E     ");
	square(5,18,18,19,17);
	square(24,37,18,19,17);
	square(42,55,18,19,17);
	square(60,73,18,19,17);
	//gotoxy(10,16); printf("PLAY");
	//gotoxy(29,16); printf("SCORE");
	//gotoxy(47,16); printf("HELP");
	//gotoxy(65,16); printf("EXIT");
	arrow(4,0);
	//gotoxy(30,23); printf("FUCK");
}
void stage()
{
	system("cls");
	FILE *article;
	article=fopen("AtoZ.txt","r");
	char c;
	if(article==NULL)
		printf("No");
	else
	{
		do
		{
			//c=fgetc(article);
			putchar(c=fgetc(article));
		}while(c!=EOF);
		fclose(article);
	}
	square(5,18,18,19,17);
	square(24,37,18,19,17);
	square(42,55,18,19,17);
	square(60,73,18,19,17);
	gotoxy(22,22); printf("Press spacebar to Back to main menu.");
	arrow(4,1);
	getch();
}
void stage1()
{
	system("cls");
	printf("PLAY");
	getch();
	system("cls");
	window();
}
void arrow(int point,int x)
{
	int count=1; 
	char word='0';
	//gotoxy(64,18);
	while(1)
	{
		switch(word)
        {
        case 77:{
            count++;
            if (count==point+1) count=1;
            break;}
        case 75:{
            count--;
            if(count==0) count=point;
            break;}
        }
		move(point,count,x);
		word=getch();
		if(word=='\r')
		{
			if(point==4)
			{
				switch(x)
				{
					case 0:
					{
						if(count==1)stage();
						else if(count==4) exit(0);
					}
					case 1:
					{
						if(count==1) stage1();
					}
				}
				
			}
		}
		else if(word==32)
		{
			system("cls");
			window();
		}
	}
}
void move(int point,int count,int x)
{
	char *menu[2][4]={{"PLAY","SCORE","HELP","EXIT"},{"STAGE 1","STAGE 2","STAGE 3","STAGE 4"}};
	//int pixel [][]
	
	if(point==4)
	{
		gotoxy(8,18); printf("  %s",menu[x][0]);
		gotoxy(27,18); printf("  %s",menu[x][1]);
		gotoxy(45,18); printf("  %s",menu[x][2]);
		gotoxy(63,18); printf("  %s",menu[x][3]);
		switch (count)
        {
        case 1:
        {
            gotoxy(7,18);
            printf(" %c %s",16,menu[x][0]);
            break;
    	}
        case 2:
        {
            gotoxy(26,18);
            printf(" %c %s",16,menu[x][1]);
            break;
    	}
        case 3:
        {
            gotoxy(44,18);
            printf(" %c %s",16,menu[x][2]);
            break;
    	}
        case 4:
        {
            gotoxy(62,18);
            printf(" %c %s",16,menu[x][3]);
            break;
        }
        }
	}
}
void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    return;
}

void bgcolor(int color, int bg)
{
     WORD wColor = ((bg & 0x0F) << 4) + (color & 0x0F);
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD coord = {0, 0};
     DWORD count;
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}
