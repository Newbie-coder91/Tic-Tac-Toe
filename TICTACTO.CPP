#include <conio.h>
#include <iostream.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>;
void drawboard();
void drawmove(char turn, int cell);
int converter(char);
int checkwin(char board[3][3], char);
int checkdraw(char board[3][3]);
void main()
{
  int a=DETECT, b;
  clrscr();
  initgraph(&a,&b,"");

  char p1[20],p2[20];
  cout<<"Enter First Player Name(X) : ";
  cin>>p1;
  cout<<"Enter Second Player Name(O) : ";
  cin>>p2;
  cleardevice();
  settextstyle(0,0,2);
  outtextxy(460,70,"NAME");
  settextstyle(6,0,1);
  outtextxy(460,90,p1);
  outtextxy(460,120,p2);
  settextstyle(0,0,2);
  line(450,120,610,120);
  line(450,90,610,90);
  line(530,60,530,150);
  int win = 1;
  int draw = 1;
  char turn = 'X';
  char key;
  char board[3][3]={
    {' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '}
  };
  strcat(p2," Won!!");
  strcat(p1," Won!!");
  while(win && draw)
  {
    drawboard();
    if(turn == 'X'){
      setcolor(0);
      outtextxy(560,127,"O");
      setcolor(15);
      outtextxy(560,98,"X");
    }
    else{
      setcolor(0);
      outtextxy(560,98,"X");
      setcolor(15);
      outtextxy(560,127,"O");
    }
    key = getch();

    int cell = converter(key);
    if(cell == -1)
    {
      cout<<"Invalid Choice\n";
      continue;
    }

    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if(board[row][col] != ' ')
    {
      cout<<"Invalid Move\n";
      continue;
    }
    board[row][col] = turn;

    drawmove(turn, cell);

    win = checkwin(board, turn);
    draw = checkdraw(board);

    turn = (turn == 'X')?'O':'X';
  }
  cleardevice();
  if(win)
  {
    outtextxy(230,240,"Nobody Won!!");
  }
  else
  {
    if(turn == 'O')
    {
      outtextxy(230,240,p1);
    }
    else
    {
      outtextxy(230,240,p2);
    }

  }

  getch();

}

//---------------------------------------------------------------------------

void drawboard()
{
  line(200,100,200,400);
  line(300,100,300,400);

  line(100,200,400,200);
  line(100,300,400,300);
}

//---------------------------------------------------------------------------

int converter(char key){
  switch(key)
  {
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
  }
}

void drawmove(char turn, int cell)
{
  int x,y;
  switch(cell)
  {
    case 7: x = 150; y = 150;
      break;
    case 8: x = 250; y = 150;
      break;
    case 9: x = 350; y = 150;
      break;
    case 4: x = 150; y = 250;
      break;
    case 5: x = 250; y = 250;
      break;
    case 6: x = 350; y = 250;
      break;
    case 1: x = 150; y = 350;
      break;
    case 2: x = 250; y = 350;
      break;
    case 3: x = 350; y = 350;
      break;
  }
  if(turn == 'X')
  {
    setcolor(14);
    line(x-30,y-30,x+30,y+30);
    line(x+30,y-30,x-30,y+30);
    setcolor(15);
  }
  else
  {
    circle(x,y,30);
  }
}
int checkwin(char board[3][3], char turn)
{
  int i, j;
  for(i = 0; i < 3; i++)
  {
    if(board[i][0] == turn && board[i][1] == turn&& board[i][2] == turn)
    {
      return 0;
    }
  }
  for(j = 0; j < 3; j++)
  {
    if(board[0][j] == turn && board[1][j] == turn&& board[2][j] == turn)
    {
      return 0;
    }
  }
  if(board[0][0]==turn&&board[1][1]==turn&&board[2][2]==turn)
  {
    return 0;
  }
  if(board[0][2]==turn&&board[1][1]==turn&&board[2][0]==turn)
  {
    return 0;
  }
  return 1;
}

int checkdraw(char board[3][3])
{
  int i, j;
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
    {
      if(board[i][j]==' ')
      {
	return 1;
      }
    }
  }
  return 0;
}






