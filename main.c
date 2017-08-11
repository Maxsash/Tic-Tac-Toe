#include <stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
//NOTE:int mat15[3][3]={{6,1,8},{7,5,3},{2,9,4}}; the sum of all win situations is 15
int main()
{
    FILE *fp;
    int i,result,move,msglen,mode,w,l,d,menu;
    char k,board[9],winmsg[50]="YOU WIN THIS TIME!",losmsg[50]="HAHAHA I AM UNDEFEATED!";
    char corner[4]={0,2,6,8},side[4]={1,3,5,7},buff[10];
    fp=fopen("D:/Codes/T3/Score.txt","r");
   while(fgets(buff,10,fp)!=NULL)
    {
        i=ftell(fp);
        if(i>=9 && i<=11)
        {
            w=atoi(buff);
        }
        else if(i>=19 && i<=23)
        {
            l=atoi(buff);
        }
        else if(i>=29 && i<=35)
        {
            d=atoi(buff);
        }
    }
    srand(time(0));
    printf("\tWELCOME to AGAINST THE 'O'.\n\t");
    system("pause");
    system("cls");
    menu:
        printf("1.Play game.\n2.Scoreboard.\n3.Music.\n4.exit.\n");
        scanf("%d",&menu);
        system("cls");
        if(menu==2)
        {
            printf("Win:\n%d\nLose:\n%d\nDraw:\n%d\n",w,l,d);
            getch();
            system("cls");
            goto menu;
        }
        else if(menu==3)
        {
            printf("Goto Start menu, find 'Grove Music', click on it.Enjoy!\n");
            getch();
            system("cls");
            goto menu;
        }
        else if(menu==4)
        {
            goto endgame;
        }
    printf("Choose game mode:\n 1.Easy mode \n 2.I Am Possible mode\n");
    scanf("%d",&mode);
    system("cls");
    thegame:
    i=0;
    k='1';
    for(i=0;i<=8;i++)
    {
        board[i]=k;//initiating the game board
        k++;
    }
    do//the game loop
{
    for(i=0;i<=8;i++)
    {
        printf("%c\t",board[i]);//prints the game board
        if(i==2||i==5||i==8)
            printf("\n");
     }
playermove:
printf("Enter the place where you want your mark:");
scanf("%d",&move);
if(board[move-1]=='x'||board[move-1]=='o')//INVALID MOVE CHECK
{printf("Invalid placement\n");
goto playermove;}
else if(move==0)
{
    result=1;
    goto aftergame;
}
else
    {board[move-1]='x';}
compmove:
    i=0;
    k='0';
    for(i=0;i<=8;i++)        //check if the comp can win
    {k++;
        if(board[i]=='x'||board[i]=='o')//validity check
           {continue;}
        else
           {
              board[i]='o';
              if(board[0]=='o'&& board[1]=='o'&& board[2]=='o')// THE COMP WIN CHECK
        {goto aftermove;}                                 //1=p1 win; 2=comp win; 3=draw; 0=not over;
        else if(board[3]=='o'&& board[4]=='o' && board[5]=='o')// keep in mind lose is win for other player
        goto aftermove;
        else if(board[6]=='o'&& board[7]=='o' && board[8]=='o')// so no lose check just check win for all
        goto aftermove;
        else if(board[0]=='o'&& board[3]=='o' && board[6]=='o')
        goto aftermove;
        else if(board[1]=='o'&& board[4]=='o' && board[7]=='o')
        goto aftermove;
        else if(board[2]=='o'&& board[5]=='o' && board[8]=='o')
        goto aftermove;
        else if(board[0]=='o'&& board[4]=='o' && board[8]=='o')
        goto aftermove;
        else if(board[2]=='o'&& board[4]=='o' && board[6]=='o')
        goto aftermove;
    else {
        board[i]=k;
         }
           }
    }
    i=0;
    k='0';
for(i=0;i<=8;i++)        //check if the player can win and stop HIM/HER/IT!
{k++;
    if(board[i]!='x' && board[i]!='o')//validity check
           {
              board[i]='x';
        if(board[0]=='x'&& board[1]=='x'&& board[2]=='x')// THE P1 WIN CHECK
        {   board[i]='o';
            goto aftermove;}                                 //1=p1 win; 2=comp win; 3=draw; 0=not over;
        else if(board[3]=='x'&& board[4]=='x' && board[5]=='x')// keep in mind lose is win for other player
        {board[i]='o';
        goto aftermove;}
        else if(board[6]=='x'&& board[7]=='x' && board[8]=='x')// so no lose check just check win for all
        {board[i]='o';
        goto aftermove;}
        else if(board[0]=='x'&& board[3]=='x' && board[6]=='x')
        {board[i]='o';
        goto aftermove;}
        else if(board[1]=='x'&& board[4]=='x' && board[7]=='x')
        {board[i]='o';
        goto aftermove;}
        else if(board[2]=='x'&& board[5]=='x' && board[8]=='x')
        {board[i]='o';
        goto aftermove;}
        else if(board[0]=='x'&& board[4]=='x' && board[8]=='x')
        {board[i]='o';
        goto aftermove;}
        else if(board[2]=='x'&& board[4]=='x' && board[6]=='x')
        {board[i]='o';
        goto aftermove;}
        else {
                board[i]=k;}
           }
    else
    {continue;}
}
if(mode==2)
{
    special:
if((board[0]=='x' && board[8]=='x') || (board[2]=='x' && board[6]=='x'))
{
    goto side;
}
if((board[1]=='x' && board[3]=='x') || (board[5]=='x' && board[7]=='x')
   || (board[3]=='x' && board[7]=='x') || (board[1]=='x' && board[5]=='x'))
{
    goto corner;
}
special2:   //does not really make much difference
i=0;
k='0';
for(i=0;i<=8;i++)
{k++;
if(board[i]!='x' && board[i]!='o')
    {
        board[i]='o';
    if((board[0]=='o' && board[8]=='o') || (board[2]=='o' && board[6]=='o'))
    {
        goto aftermove;
    }
    else if((board[1]=='o' && board[3]=='o') || (board[5]=='o' && board[7]=='o')
   || (board[3]=='o' && board[7]=='o') || (board[1]=='o' && board[5]=='o'))
    {
        goto aftermove;
    }
    else
    {
        board[i]=k;
    }
}
else
{
    continue;
}
}
}
center:
if(board[4]!='x' && board[4]!='o') //trying to occupy the throne
    {
        board[4]='o';
        goto aftermove;
    }
randmove:
corner:
i=0;
for(i=0;i<=3;i++)   //trying the corners
{
    k=rand()%4;
    if(board[corner[k]]!='x' && board[corner[k]]!='o')
    {
        board[corner[k]]='o';
        goto aftermove;
    }
    else
    {
        continue;
    }
}
side:
i=0;
for(i=0;i<=3;i++)   //trying the sides
{
    k=rand()%4;
    printf("%d",k);
    if(board[side[k]]!='x' && board[side[k]]!='o')
    {
        board[side[k]]='o';
        goto aftermove;
    }
    else
    {
        for(i=0;i<=8;i++)   //Draw check
    {
        if(board[i]=='x' || board[i]=='o')
            {
                if(i==8)
                    {
                        goto aftermove;
                    }
                else
                {
                    continue;
                }
            }
        else
            {
                goto randmove;
            }
    }
    }
}
aftermove:
if(board[0]=='x'&& board[1]=='x'&& board[2]=='x')// THE P1 WIN CHECK
        {result=1;}                                 //1=p1 win; 2=comp win; 3=draw; 0=not over;
        else if(board[3]=='x'&& board[4]=='x' && board[5]=='x')// keep in mind lose is win for other player
        result=1;
        else if(board[6]=='x'&& board[7]=='x' && board[8]=='x')// so no lose check just check win for all
        result=1;
        else if(board[0]=='x'&& board[3]=='x' && board[6]=='x')
        result=1;
        else if(board[1]=='x'&& board[4]=='x' && board[7]=='x')
        result=1;
        else if(board[2]=='x'&& board[5]=='x' && board[8]=='x')
        result=1;
        else if(board[0]=='x'&& board[4]=='x' && board[8]=='x')
        result=1;
        else if(board[2]=='x'&& board[4]=='x' && board[6]=='x')
        result=1;
        else if(board[0]=='o'&& board[1]=='o'&& board[2]=='o')// THE COMP WIN CHECK
        {result=2;}                                 //1=p1 win; 2=comp win; 3=draw; 0=not over;
        else if(board[3]=='o'&& board[4]=='o' && board[5]=='o')// keep in mind lose is win for other player
        result=2;
        else if(board[6]=='o'&& board[7]=='o' && board[8]=='o')// so no lose check just check win for all
        result=2;
        else if(board[0]=='o'&& board[3]=='o' && board[6]=='o')
        result=2;
        else if(board[1]=='o'&& board[4]=='o' && board[7]=='o')
        result=2;
        else if(board[2]=='o'&& board[5]=='o' && board[8]=='o')
        result=2;
        else if(board[0]=='o'&& board[4]=='o' && board[8]=='o')
        result=2;
        else if(board[2]=='o'&& board[4]=='o' && board[6]=='o')
        result=2;
    else {result=0;}
    i=0;
    if(result==0)
    {for(i=0;i<=8;i++)   //Draw check
    {
        if(board[i]=='x' || board[i]=='o')
            {
                if(i==8)
                    {
                        result=3;
                        break;
                    }
                else
                {
                    continue;
                }
            }
        else
            {
                break;
            }
    }}
system("cls");
}
while(result==0);
aftergame:
system("cls");
i=0;
if(result==2)
{   l++;
    msglen=strlen(losmsg);
for(i=0;i<msglen;i++)
    {
        printf("%c",losmsg[i]);
    Sleep(100);
    }
      printf("\nPress 1 to lose again(LOSER!) or Press 2 to accept defeat\n");
   for(i=0;i<=8;i++)
    {
        printf("%c\t",board[i]);//prints the final game board
        if(i==2||i==5||i==8)
            printf("\n");
     }
    scanf("%d",&i);
    if(i==1)
    {
        system("cls");
        goto thegame;
    }
     else if(i==2)
    {
        system("cls");
        goto menu;
    }
}
else if(result==1)
{  w++;
   msglen=strlen(winmsg);
for(i=0;i<msglen;i++)
    {
        printf("%c",winmsg[i]);
    Sleep(100);
    }
    printf("\nTukke me jeet gaye jyada udo mat!\n Press 1 to lose after a game or Press 2 to accept defeat right now.\n");
    for(i=0;i<=8;i++)
    {
        printf("%c\t",board[i]);//prints the final game board
        if(i==2||i==5||i==8)
            printf("\n");
     }
    scanf("%d",&i);
    if(i==1)
    {
        system("cls");
        goto thegame;
    }
     else if(i==2)
    {
        system("cls");
        goto menu;
    }
}
else
{   d++;
    printf("DRAW! Press 1 to try again or Press 2 to accept defeat!\n");
    for(i=0;i<=8;i++)
    {
        printf("%c\t",board[i]);//prints the final game board
        if(i==2||i==5||i==8)
            printf("\n");
     }
    scanf("%d",&i);
    if(i==1)
    {
        system("cls");
        goto thegame;
    }
    else if(i==2)
    {
        system("cls");
        goto menu;
    }
}
fclose(fp);
endgame:
 fp=fopen("D:/Codes/T3/Score.txt","w");
 fprintf(fp,"Win:\n%d\nLose:\n%d\nDraw:\n%d\n",w,l,d);
 fclose(fp);
return 0;
}
/*int checkwin(char a[9]) //checks if someone won, p1 is x or o
{
    if(a[0]=='x'&& a[1]=='x'&& a[2]=='x')
        {return 1;}                                 //1=win; 0=NOT win
        else if(a[3]=='x'&& a[4]=='x' && a[5]=='x')// keep in mind lose is win for other player
        return 1;
        else if(a[6]=='x'&& a[7]=='x' && a[8]=='x')// so no lose check just check win for all
        return 1;
        else if(a[0]=='x'&& a[3]=='x' && a[6]=='x')
        return 1;
        else if(a[1]=='x'&& a[4]=='x' && a[7]=='x')
        return 1;
        else if(a[2]=='x'&& a[5]=='x' && a[8]=='x')
        return 1;
        else if(a[0]=='x'&& a[4]=='x' && a[8]=='x') I DONT KNOW WHY ITS NOT WORKING
        return 1;                                   SO LET IT BE FOR THE TIME BEING
        else if(a[2]=='x'&& a[4]=='x' && a[6]=='x')
        return 1;
    else {return 0;}
}*/
