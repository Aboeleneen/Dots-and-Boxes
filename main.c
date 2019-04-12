#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include <ctype.h>
#include<string.h>
struct tm *local ;
char board[9][11];
char board1[21][26];
char str1[100];
 char str2[100];
 int temps=0;
void read_input();
void init(); // function determine the elements in board which are 254
void print_board(); // function to print all elements of board for 2*2  and 5*5
void Read_command(); // function to take input from players and print it in board
void check_correct_input(int p1,int p2,int p3,int p4); // function to check if the player command is true or not
void check_square();  //function to check that there is a complete box and increase the the score for the player
void Read_command_com_2_easy(); // the strategy for computer for 2*2 easy mode
void Read_command_com_2_hard(); // the strategy for computer for 2*2 hard mode
void Read_command_com_6_easy(); // the strategy for computer for 5*5 easy mode
void Read_command_com_6_hard();// the strategy for computer for 5*5 hard mode
void player_vs_player(); // function to two players mode
void player_vs_computer_easy(); //function to single player easy mode
void player_vs_computer_hard(); //function to single player hard mode
int get_max(int x,int y); //to arrange the input of of the player if he reverse the two points
int get_min(int x,int y);//to arrange the input of of the player if he reverse the two points
int player1_score=0;  // variable to calculate the score for player one
int player2_score=0; // variable to calculate the score for player two
int player1=0;  // variable to determine that the player one will read command
int player2=0;// variable to determine that the player two will read command
int re1=0; // variable to give player one another turn if he complete a box
int re2=0; // variable to give player two another turn if he complete a box
int row_board_1_old,row_board_2_old,column_board_2_old,column_board_1_old;//variables to take the input from the player
int row_board_1,row_board_2,column_board_1,column_board_2;// variables refer to the two points after after check if there correct
void play();// function to choose the game mode
int turn=0;
int line=0;
int next1=0;
int next2=0;
int next3=0;
int next11=0;
int next22=0;
int gotoxy(int x,int y);
void loading();
int color=0;
int color2=0;
int array_color[100][4];
int array_color2[100][4];
int k1,k2,l=0;
int row4,row5,column4,column5;
char name1[20],name2[20];
struct mahmoud {
      char name[20];
      int player_score;
      } b[9];
struct mahmoud5 {
      char name5[20];
      int player_score5;
      } b5[9];
    void  rank();
int decide3,decide,decide2,choose,decide5;
void frame(int m,int n);
int max_number;
int te1=-1;
int arr1[60][4];
int arr2[60][4];
int te2=-1;

int te3,te4;
void load();
void save();
int x=0,y=-1,z=0;
void zero();
void name(char str[20]);


int main()
{

   loading();
    again: play();
      system("cls");
      gotoxy(40,10);
      printf("if you want to return to menu press 1\n");
      gotoxy(40,12);
       printf("if you want to exit press any key\n");
      scanf("%d",&decide5);
      system("cls");
      if (decide5==1){
               te1=-1;
        te2=-1;
        te3=0;
        te4=0;
        x=0;
        y=-1;
        z=0;
        goto again ;
      }
      else



 //rank();
    return 0;
}
void init()
{
    int i,j;
    int v1,v2;
    if (choose==1)
    {
        v1=9;
        v2=11;
    }
    else
    {
        v1=21;
        v2=26;
    }

    for (i=0; i<v1; i+=4)
    {
        for (j=0; j<v2; j+=5)
        {
            if (choose==1)
                board[i][j]=254;
            else
                board1[i][j]=254;
        }
    }
}

void print_board()
{

     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            WORD saved_attributes; /* Save current attributes */
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            saved_attributes = consoleInfo.wAttributes;
            SetConsoleTextAttribute(hConsole, 10);
           if (decide==2){
        printf("\nplayer one name :%s\n",name1);}
        else{
            printf("\nplayer one name :%s\n",name1);
        printf("player two name :%s",name2);}

          SetConsoleTextAttribute(hConsole, saved_attributes);



    int v1,v2;
    int i,j;

    if (choose==1)
    {
        v1=9;
        v2=11;
    }
    else
    {
        v1=21;
        v2=26;

    }
     SetConsoleTextAttribute(hConsole, 14);
    for(i=69;i<92;i++){
    gotoxy(i,9);
    printf("%c",205);}

    for (i=10;i<15;i++){
    gotoxy(68,i);
    printf("%c",186);}
     for(i=69;i<92;i++){
    gotoxy(i,15);
    printf("%c",205);}
     for (i=10;i<15;i++){
    gotoxy(92,i);
    printf("%c",186);}
     SetConsoleTextAttribute(hConsole, saved_attributes);

    gotoxy(70,10);
       SetConsoleTextAttribute(hConsole, 12);
    printf("player one score : %d",player1_score);
       SetConsoleTextAttribute(hConsole, saved_attributes);
     gotoxy(70,12);
      SetConsoleTextAttribute(hConsole, 9);
    printf("plater two score : %d",player2_score);
     SetConsoleTextAttribute(hConsole, saved_attributes);
     gotoxy(70,14);
      SetConsoleTextAttribute(hConsole, 15);
    printf("line : %d",line);
     SetConsoleTextAttribute(hConsole, saved_attributes);
    gotoxy(7,5);
    printf("\t\t\t\t    ");

    if (choose==1)
    {

        for(i=0; i<3; i++)
            printf("%d    ",i);
        printf("\n\n");

    }
    else
    {
        for(i=0; i<6; i++)
            printf("%d    ",i);
        printf("\n\n");



    }

    for (i=0; i<v1; i++)
    {
        printf("\t\t\t\t");
        if (i%4==0)
        {
            printf("%d   ",i/4);
        }
        else
            printf("    ");


        for (j=0; j<v2; j++)
        {
            if  (choose==1){
                    if(i%4==0&&j%5==0){
                SetConsoleTextAttribute(hConsole, 7);
                printf("%c",board[i][j]);
                 SetConsoleTextAttribute(hConsole, saved_attributes);}
                 else{
                        if (player1==0||color==0){
                    SetConsoleTextAttribute(hConsole, 9);
                printf("%c",board[i][j]);
                 SetConsoleTextAttribute(hConsole, saved_attributes);
                 }
                  else if (player2==0||color2==0){
                    SetConsoleTextAttribute(hConsole, 12);
                printf("%c",board[i][j]);
                 SetConsoleTextAttribute(hConsole, saved_attributes);

                  }

                 }}
            else{


                if(i%4==0&&j%5==0){
                SetConsoleTextAttribute(hConsole, 7);
                printf("%c",board1[i][j]);
                 SetConsoleTextAttribute(hConsole, saved_attributes);}
                 else{
                        if (player1==0){
                    SetConsoleTextAttribute(hConsole, 9);
                printf("%c",board1[i][j]);
                 SetConsoleTextAttribute(hConsole, saved_attributes);}
                  else if (player2==0){
                    SetConsoleTextAttribute(hConsole, 12);
                printf("%c",board1[i][j]);
                 SetConsoleTextAttribute(hConsole, saved_attributes);

               }}}
        }
        printf("\n");

    }
         SetConsoleTextAttribute(hConsole, saved_attributes);
         fflush(stdin);
}
void Read_command()
{
   int i,j;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            WORD saved_attributes; /* Save current attributes */
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            saved_attributes = consoleInfo.wAttributes;
     SetConsoleTextAttribute(hConsole, 11);
     gotoxy(0,8);
    printf("\nenter two dots\n");
    if (line>y){
  read_input();
check_correct_input(row_board_1,column_board_1,row_board_2,column_board_2);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    row4=row_board_1*4;
    row5=row_board_2*4;
    column4=column_board_1*5;
    column5=column_board_2*5;
    if (te1==-1){
    player1=0;
    player2=1;
}

  if (player1==0){

     te1++;
    for(i=te1;i<60;i++){
          for (j=0;j<1;j++){

                arr1[i][j]=row4;

                arr1[i][j+1]=column4;

                arr1[i][j+2]=row5;

                arr1[i][j+3]=column5;

        }
        break;


  }



  FILE*lines;
    if (te1==0)
  lines=fopen("p1.text","w");
  else
   lines=fopen("p1.text","a");
for (i=te1;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines,"%d\n%d\n%d\n%d\n",arr1[i][j]=row4,arr1[i][j+1]=column4,arr1[i][j+2]=row5,arr1[i][j+3]=column5);}
        break; }

fclose(lines);}
if (player2==0){

          te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}

fclose(lines1);}}
else {

   if (te1==-1){
    player1=0;
    player2=1;
}
if (player1==0){

for (i=te3;i<60;i++){
   row4= arr1[i][0];
    column4= arr1[i][1];
    row5 = arr1[i][2];
      column5= arr1[i][3];
      te3++;
      break;}


      te1++;
    for(i=te1;i<60;i++){
          for (j=0;j<1;j++){

                arr1[i][j]=row4;

                arr1[i][j+1]=column4;

                arr1[i][j+2]=row5;

                arr1[i][j+3]=column5;

        }
        break;


  }



  FILE*lines;
    if (te1==0)
  lines=fopen("p1.text","w");
  else
   lines=fopen("p1.text","a");
for (i=te1;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines,"%d\n%d\n%d\n%d\n",arr1[i][j]=row4,arr1[i][j+1]=column4,arr1[i][j+2]=row5,arr1[i][j+3]=column5);}
        break; }

fclose(lines);








      }

if(player2==0){

for (i=te4;i<60;i++){
   row4= arr2[i][0];
    column4= arr2[i][1];
    row5 = arr2[i][2];
      column5= arr2[i][3];
      te4++;
      break;}





         te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}
    fclose(lines1);




      }






}






    if (row4==row5)
    {
        for(i=(column4+1); i<column5; i++)
            if(choose==1)
                board[row4][i]=(char)196;
            else
                board1[row4][i]=(char)196;
    }
    if (column4==column5)
    {
        for(i=(row4+1); i<row5; i++)
            if (choose==1)
                board[i][column4]=(char)179;
            else
                board1[i][column4]=(char)179;

    }

    printf("\n");
    check_square();
    init();
    system("cls");
      save();
    line++;
    print_board();
       fflush(stdin);
}
void check_square()
{
    if (choose==1)
    {
        int i,j,x6,y6;
        for (i=0; i<6; i+=4)
        {
            for (j=0; j<6; j+=5)
            {
                x6=i;
                y6=j;


                if (board[x6+1][y6]==(char)179&&board[x6][y6+1]==(char)196&&board[x6+1][y6+5]==(char)179&&board[x6+4][y6+1]==(char)196)
                {
                    if (player1==0)
                    {
                        if ( board[x6+2][y6+2]=='1'||board[x6+2][y6+2]=='2')
                        {
                            continue;
                        }

                        board[x6+2][y6+2]='1';
                        player1_score++;
                        re1=1;
                        color=0;
                        color2=1;

                    }
                    if (player2==0)
                    {
                        if ( board[x6+2][y6+2]=='2'||board[x6+2][y6+2]=='1')
                        {
                            continue;
                        }

                        board[x6+2][y6+2]='2';
                        player2_score++;
                        re2=1;
                        color2=0;
                        color=1;

                    }
                }
            }
        }
    }
    else
    {
        int i,j,x6,y6;
        for (i=0; i<17; i+=4)
        {
            for (j=0; j<21; j+=5)
            {
                x6=i;
                y6=j;
                if (board1[x6+1][y6]==(char)179&&board1[x6][y6+1]==(char)196&&board1[x6+1][y6+5]==(char)179&&board1[x6+4][y6+1]==(char)196)
                {
                    if (player1==0)
                    {
                        if ( board1[x6+2][y6+2]=='1'||board1[x6+2][y6+2]=='2')
                        {
                            continue;
                        }

                        board1[x6+2][y6+2]='1';
                        player1_score++;
                        re1=1;
                    }
                    if (player2==0)
                    {
                        if ( board1[x6+2][y6+2]=='1'||board1[x6+2][y6+2]=='2')
                        {
                            continue;
                        }

                        board1[x6+2][y6+2]='2';
                        player2_score++;
                    }
                    re2=1;
                }
            }
        }


    }
}
void Read_command_com_2_hard()
{
    int i,j,i1,x6,y6;
    int row4,row5,column4,column5;
    int next1=0;
    int next2=0;
    if (line>y){
    // to  check if there is a box need to one line
    for (i=0; i<5; i+=4)
    {
        int t=0;
        int t2=0;
        for(j=0; j<6; j+=5)
        {
            x6=i;
            y6=j;
            if (board[x6+1][y6]!=(char)179&&board[x6][y6+1]==(char)196&&board[x6+1][y6+5]==(char)179&&board[x6+4][y6+1]==(char)196)
            {
                row4=x6;
                column4=y6;
                row5=x6+4;
                column5=y6;
                t=1;
                next1=1;
            }
            else if (board[x6+1][y6]==(char)179&&board[x6][y6+1]!=(char)196&&board[x6+1][y6+5]==(char)179&&board[x6+4][y6+1]==(char)196)
            {
                row4=x6;
                column4=y6;
                row5=x6;
                column5=y6+5;
                t=1;
                next1=1;
            }
            else if (board[x6+1][y6]==(char)179&&board[x6][y6+1]==(char)196&&board[x6+1][y6+5]!=(char)179&&board[x6+4][y6+1]==(char)196)
            {
                row4=x6;
                column4=y6+5;
                row5=x6+4;
                column5=y6+5;
                t=1;
                next1=1;
            }
            else if (board[x6+1][y6]==(char)179&&board[x6][y6+1]==(char)196&&board[x6+1][y6+5]==(char)179&&board[x6+4][y6+1]!=(char)196)
            {
                row4=x6+4;
                column4=y6;
                row5=x6+4;
                column5=y6+5;
                t=1;
                next1=1;
            }
            if (t==1)
            {
                t2=1;

                break;
            }



        }
        if (t2==1)
        {
            next2=1;

            break;
        }
    }
    // if there are no box need one line it will check for box without any line and play.
    if (next1==0)
    {
         int next2=0;

        for (i=0; i<5; i+=4)
        {
            int t3=0;
            int t4=0;

            for(j=0; j<6; j+=5)
            {
                x6=i;
                y6=j;
                if (board[x6+1][y6]!=(char)179&&board[x6][y6+1]!=(char)196&&board[x6+1][y6+5]!=(char)179&&board[x6+4][y6+1]!=(char)196)
                {
                    if (board[x6+4+1][y6+5]!=(char)179&&board[x6+4+4][y6+1]!=(char)196&&board[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else  if (board[x6+4+1][y6+5]!=(char)179&&board[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else  if (board[x6+4+1][y6+5]!=(char)179&&board[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else  if (board[x6+4+1][y6]!=(char)179&&board[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6][y6+5+1]!=(char)196&&board[x6+1][y6+5+5]!=(char)179&&board[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6][y6+5+1]!=(char)196&&board[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6][y6+5+1]!=(char)196&&board[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6+4][y6+5+1]!=(char)196&&board[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6][y6-4]!=(char)196&&board[x6+1][y6-5]!=(char)179&&board[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6][y6-4]!=(char)196&&board[x6+1][y6-5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6][y6-4]!=(char)196&&board[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6+1][y6-5]!=(char)179&&board[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6-3][y6]!=(char)179&&board[x6-4][y6+1]!=(char)196&&board[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6-3][y6]!=(char)179&&board[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6-3][y6]!=(char)179&&board[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board[x6-1][y6+5]!=(char)179&&board[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }



                }


            }

            if (t3==1)
            {
                t4=1;
                break;
            }


            if (t4==1)
                break;
        }
    }
    if (next2==0)
    {
        for (i=0; i<5; i+=4)
        {
            int t=1;
            int t2=1;
            for(j=0; j<6; j+=5)
            {
                x6=i;
                y6=j;
                if (board[x6][y6+1]!=(char)196)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6;
                    column5=y6+5;
                    t=0;
                }
                else  if (board[x6+1][y6]!=(char)179)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6+4;
                    column5=y6;
                    t=0;
                }
                else if (board[x6+1][y6+5]!=(char)179)
                {
                    row4=x6;
                    column4=y6+5;
                    row5=x6+4;
                    column5=y6+5;
                    t=0;
                }
                else if (board[x6+4][y6+1]!=(char)196)
                {
                    row4=x6+4;
                    column4=y6;
                    row5=x6+4;
                    column5=y6+5;
                    t=0;
                }
                if (t==0)
                {
                    t2=0;
                    break;
                }
            }
            if (t2==0)
                break;
        }
    }


     // to save the command in array then in a file to save and load later
    {

         te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}

fclose(lines1);}}
   else{



     for (i=te4;i<60;i++){
   row4= arr2[i][0];
    column4= arr2[i][1];
    row5 = arr2[i][2];
      column5= arr2[i][3];
      te4++;
      break;}


         te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}
    fclose(lines1);




   }







    if (row4==row5)
    {
        for(i1=(column4+1); i1<column5; i1++)
            board[row4][i1]=(char)196;
    }
    if (column4==column5)
    {
        for(i1=(row4+1); i1<row5; i1++)
            board[i1][column4]=(char)179;
    }


    printf("\n");
    check_square();
    init();
    system("cls");
    save();
    line++;
    print_board();
}

void player_vs_player()
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
     WORD saved_attributes; /* Save current attributes */
     GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
     saved_attributes = consoleInfo.wAttributes;
    init();
    print_board();
    int i;

    int num_of_lines;
    if (choose==1)
        num_of_lines=12;
    else
        num_of_lines=60;

    while(turn!=num_of_lines)
    {

        while(player1==0)
        {


            re1=0;
             SetConsoleTextAttribute(hConsole, 14);
             for (i=39;i<55;i++){
            gotoxy(i,1);
             printf("%c",205);}
           for (i=39;i<55;i++){
           gotoxy(i,3);
           printf("%c",205);}
           SetConsoleTextAttribute(hConsole, saved_attributes);
              gotoxy (32,2);

            SetConsoleTextAttribute(hConsole, 12);
            printf("\t player one");
            SetConsoleTextAttribute(hConsole, saved_attributes);


            time_t t;
            t = time(NULL);
            local = localtime(&t);
            int C_Ts = local->tm_sec;
            int C_Tm=local->tm_min;
            Read_command() ;

            time_t a ;
            a = time(NULL);
            local = localtime(&a);
            int C_Ts1 = local->tm_sec;
            int C_Tm1 =local->tm_min;
            gotoxy(73,8);
            SetConsoleTextAttribute(hConsole,13);
            printf("min:sec %d:%d\n" ,abs(C_Tm1-C_Tm),abs(C_Ts1-C_Ts));
             SetConsoleTextAttribute(hConsole, saved_attributes);
            turn++;
            if (re1==1)
            {
                player1=0;
                player2=1;
                color=0;
                color2=1;

            }
            else
            {
                player1=1;
                player2=0;
                 color2=0;
                color=1;

            }
            if (turn==num_of_lines)
                break;
        }
        if (turn==num_of_lines)
            break;
        while(player2==0)
        {
                re2=0;
            SetConsoleTextAttribute(hConsole, 14);
          for (i=39;i<55;i++){
           gotoxy(i,1);
           printf("%c",205);}
         for (i=39;i<55;i++){
           gotoxy(i,3);
             printf("%c",205);}
             SetConsoleTextAttribute(hConsole, saved_attributes);
              gotoxy (32,2);
            SetConsoleTextAttribute(hConsole, 9);
            printf("\t player two");
            SetConsoleTextAttribute(hConsole, saved_attributes);
                time_t t;
            t = time(NULL);
            local = localtime(&t);
            int C_Ts = local->tm_sec;
            int C_Tm=local->tm_min;
            Read_command() ;

            time_t a ;
            a = time(NULL);
            local = localtime(&a);
            int C_Ts1 = local->tm_sec;
            int C_Tm1 =local->tm_min;
            gotoxy(73,8);
             SetConsoleTextAttribute(hConsole,13);
            printf("min:sec %d:%d\n" ,abs(C_Tm1-C_Tm),abs(C_Ts1-C_Ts));
             SetConsoleTextAttribute(hConsole, saved_attributes);

            turn++;
            if (re2==1)
            {
                player2=0;
                player1=1;
                color=1;
                color2=0;

            }
            else
            {
                player2=1;
                player1=0;
                 color=0;
                color2=1;

            }
            if (turn==num_of_lines)
                break;
        }
        if (turn==num_of_lines)
            break;
    }
}
void Read_command_com_6_hard()
{
    int i,j,i1,x6,y6;
    int row4,row5,column4,column5;
    int next1=0;
    int next2=0;
    int next3=0;
    if (line>y){
    // to check if there a a box need to one line to complete it
    for (i=0; i<17; i+=4)
    {
        int t=0;
        int t2=0;
        for(j=0; j<21; j+=5)
        {
            x6=i;
            y6=j;
            if (board1[x6+1][y6]!=(char)179&&board1[x6][y6+1]==(char)196&&board1[x6+1][y6+5]==(char)179&&board1[x6+4][y6+1]==(char)196)
            {
                row4=x6;
                column4=y6;
                row5=x6+4;
                column5=y6;
                t=1;
                next1=1;
            }
            else if (board1[x6+1][y6]==(char)179&&board1[x6][y6+1]!=(char)196&&board1[x6+1][y6+5]==(char)179&&board1[x6+4][y6+1]==(char)196)
            {
                row4=x6;
                column4=y6;
                row5=x6;
                column5=y6+5;
                t=1;
                next1=1;
            }
            else if (board1[x6+1][y6]==(char)179&&board1[x6][y6+1]==(char)196&&board1[x6+1][y6+5]!=(char)179&&board1[x6+4][y6+1]==(char)196)
            {
                row4=x6;
                column4=y6+5;
                row5=x6+4;
                column5=y6+5;
                t=1;
                next1=1;
            }
            else if (board1[x6+1][y6]==(char)179&&board1[x6][y6+1]==(char)196&&board1[x6+1][y6+5]==(char)179&&board1[x6+4][y6+1]!=(char)196)
            {
                row4=x6+4;
                column4=y6;
                row5=x6+4;
                column5=y6+5;
                t=1;
                next1=1;
            }
            if (t==1)
            {
                t2=1;
                next2=1;
                next3=1;
                break;
            }


        }
        if (t2==1){
                  next2=1;
                next3=1;
            break;}
    }
    /* if  there is not any box need to one line it look for a box without any line  and if it plays it won't give
    the player chance to complete a box*/
    if (next1==0)
    {

        for (i=0; i<17; i+=4)
        {
            int t3=0;
            int t4=0;

            for(j=0; j<21; j+=5)
            {
                x6=i;
                y6=j;
                if (board1[x6+1][y6]!=(char)179&&board1[x6][y6+1]!=(char)196&&board1[x6+1][y6+5]!=(char)179&&board1[x6+4][y6+1]!=(char)196)
                {
                    if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196&&board1[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else  if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else  if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else  if (board1[x6+4+1][y6]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179&&board1[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6+4][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+1][y6-5]!=(char)179&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+1][y6-5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6+1][y6-5]!=(char)179&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-4][y6+1]!=(char)196&&board1[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }
                    else if (board1[x6-1][y6+5]!=(char)179&&board1[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next2=1;
                    }



                }




            if (t3==1)
            {
                next3=1;
                next2=1;
                t4=1;
                break;
            }}


            if (t4==1)
            {
                next3=1;
                next2=1;
                break;
            }
        }
    }
    /* to check if there is a box with only one line it will draw a line without giving the player chance
    to complete a box*/
    if (next2==0)
    {
        for (i=0; i<17; i+=4)
        {
            int t3=0;
            int t4=0;
            for(j=0; j<21; j+=5)
            {
                x6=i;
                y6=j;
                if (board1[x6+1][y6]!=(char)179&&board1[x6][y6+1]!=(char)196&&board1[x6+1][y6+5]==(char)179&&board1[x6+4][y6+1]!=(char)196)
                {
                    if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196&&board1[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else  if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else  if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else  if (board1[x6+4+1][y6]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }

                  else if (board1[x6][y6-4]!=(char)196&&board1[x6+1][y6-5]!=(char)179&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+1][y6-5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6+1][y6-5]!=(char)179&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-4][y6+1]!=(char)196&&board1[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-1][y6+5]!=(char)179&&board1[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }   }    // the second line
          else if (board1[x6+1][y6]==(char)179&&board1[x6][y6+1]!=(char)196&&board1[x6+1][y6+5]!=(char)179&&board1[x6+4][y6+1]!=(char)196)
                {
                    if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196&&board1[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else  if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else  if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else  if (board1[x6+4+1][y6]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179&&board1[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6+4][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-4][y6+1]!=(char)196&&board1[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-1][y6+5]!=(char)179&&board1[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }}
                // the third line
                else if (board1[x6+1][y6]!=(char)179&&board1[x6][y6+1]==(char)196&&board1[x6+1][y6+5]!=(char)179&&board1[x6+4][y6+1]!=(char)196)
                {
                    if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196&&board1[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else  if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else  if (board1[x6+4+1][y6+5]!=(char)179&&board1[x6+4+1][y6]!=(char)179)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else  if (board1[x6+4+1][y6]!=(char)179&&board1[x6+4+4][y6+1]!=(char)196)
                    {
                        row4=x6+4;
                        column4=y6;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179&&board1[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6+4][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+1][y6-5]!=(char)179&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+1][y6-5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6+1][y6-5]!=(char)179&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }}
                    //the fourth line
                else if (board1[x6+1][y6]!=(char)179&&board1[x6][y6+1]!=(char)196&&board1[x6+1][y6+5]!=(char)179&&board1[x6+4][y6+1]==(char)196)
                {

                    if (board1[x6][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179&&board1[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6+5+1]!=(char)196&&board1[x6+4][y6+5+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6+4][y6+5+1]!=(char)196&&board1[x6+1][y6+5+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6+5;
                        row5=x6+4;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+1][y6-5]!=(char)179&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+1][y6-5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6][y6-4]!=(char)196&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6+1][y6-5]!=(char)179&&board1[x6+4][y6-4]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6+4;
                        column5=y6;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-4][y6+1]!=(char)196&&board1[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-3][y6]!=(char)179&&board1[x6-1][y6+5]!=(char)179)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }
                    else if (board1[x6-1][y6+5]!=(char)179&&board1[x6-4][y6+1]!=(char)196)
                    {
                        row4=x6;
                        column4=y6;
                        row5=x6;
                        column5=y6+5;
                        t3=1;
                        next3=1;
                    }}

                if (t3==1)
                {
                    t4=1;
                    next3=1;
                    break;
                }}

            if (t4==1){
                     next3=1;
                break;}
        }}
    /* if it does not play it mean that there are only boxes with two lines so if it plays it will give the player chance to complete a box
  it   will  choose the first line because it won't differ*/
    if (next3==0)
    {    for (i=0; i<17; i+=4)
        {
            int t3=0;
            for(j=0; j<21; j+=5)
            {
                x6=i;
                y6=j;
                if (board1[x6][y6+1]!=(char)196)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6;
                    column5=y6+5;
                    t3=1;
                }
                else  if (board1[x6+1][y6]!=(char)179)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6+4;
                    column5=y6;
                    t3=1;
                }
                else if (board1[x6+1][y6+5]!=(char)179)
                {
                    row4=x6;
                    column4=y6+5;
                    row5=x6+4;
                    column5=y6+5;
                    t3=1;
                }
                else if (board1[x6+4][y6+1]!=(char)196)
                {
                    row4=x6+4;
                    column4=y6;
                    row5=x6+4;
                    column5=y6+5;
                    t3=1;
                }
                if (t3==1)
                    break;}
                if (t3==1)
                    break;}}


       // to save the command in array then in a file to save and load later
    {

         te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}

fclose(lines1);}}
   else{



     for (i=te4;i<60;i++){
   row4= arr2[i][0];
    column4= arr2[i][1];
    row5 = arr2[i][2];
      column5= arr2[i][3];
      te4++;
      break;}


         te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}
    fclose(lines1);




   }






    if (row4==row5)
    {
        for(i1=(column4+1); i1<column5; i1++)
            board1[row4][i1]=(char)196;
    }
    if (column4==column5)
    {
        for(i1=(row4+1); i1<row5; i1++)
            board1[i1][column4]=(char)179;
    }


    printf("\n");
    check_square();
    init();
    system("cls");
     save();
    line++;
    print_board();



}
void player_vs_computer_hard()
{

      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            WORD saved_attributes; /* Save current attributes */
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            saved_attributes = consoleInfo.wAttributes;


    int num_of_lines;
    if (choose==1)
        num_of_lines=12;
    else
        num_of_lines=60;
    init();
    print_board();
     gotoxy(0,6);
     int i ;


    while(turn!=num_of_lines)
    {

        while(player1==0)
        {


            re1=0;

            SetConsoleTextAttribute(hConsole, 14);
             for (i=39;i<55;i++){
            gotoxy(i,1);
             printf("%c",205);}
           for (i=39;i<55;i++){
           gotoxy(i,3);
           printf("%c",205);}
           SetConsoleTextAttribute(hConsole, saved_attributes);
              gotoxy (32,2);

            SetConsoleTextAttribute(hConsole, 12);
            printf("\t player one");
            SetConsoleTextAttribute(hConsole, saved_attributes);
             time_t t;
            t = time(NULL);
            local = localtime(&t);
            int C_Ts = local->tm_sec;
            int C_Tm=local->tm_min;
            Read_command() ;
            time_t a ;
            a = time(NULL);
            local = localtime(&a);
            int C_Ts1 = local->tm_sec;
            int C_Tm1 =local->tm_min;
            gotoxy(73,8);
            SetConsoleTextAttribute(hConsole,13);
            printf("min:sec %d:%d\n" ,abs(C_Tm1-C_Tm),abs(C_Ts1-C_Ts));
             SetConsoleTextAttribute(hConsole, saved_attributes);
            turn++;
            if (re1==1)
            {
                player1=0;
                player2=1;
            }
            else
            {
                player1=1;
                player2=0;
            }
            if (turn==num_of_lines)
                break;
        }
        if (turn==num_of_lines)
            break;
        while(player2==0)
        {

            re2=0;
            if (choose==1)
                Read_command_com_2_hard();
            else
                Read_command_com_6_hard();
            turn++;
            if (re2==1)
            {
                player2=0;
                player1=1;
            }
            else
            {
                player2=1;
                player1=0;
            }
            if (turn==num_of_lines)
                break;
        }
        if (turn==num_of_lines)
            break;







    }
}
void check_correct_input(int p1,int p2,int p3,int p4)
{

    for(;;)
    {
        for (;;){
              if (row_board_1==row_board_2){
                    if (choose==1){
           if (board[row_board_1*4][column_board_1*5+1]==(char)196){
             printf("incorrect input\n");
                read_input();}
                else
                    break;
                }
                else
                {
                     if (board1[row_board_1*4][column_board_1*5+1]==(char)196){
             printf("incorrect input\n");
                read_input();
                }
                else
                break;

               }}


            else if (column_board_1==column_board_2){

                    if (choose==1){
                   if (board[row_board_1*4+1][column_board_1*5]==(char)179){
                     printf("incorrect input\n");
                read_input();}
                  else
                    break;
                   }
                  else{
                          if (board1[row_board_1*4+1][column_board_1*5]==(char)179){
                     printf("incorrect input\n");
                read_input();}
                  else
                    break;
                   }


            }
            else
                break;
             }





        for(;;)
        {
            if (row_board_1!=row_board_2&&column_board_1!=column_board_2)
            {
                printf("incorrect input\n");
                read_input();
            }
            else
                break;
        }
        for(;;)
        {


            if (choose==1)
                max_number=2;
            else
                max_number=5;
            if (row_board_1>max_number||row_board_2>max_number||column_board_1>max_number||column_board_2>max_number)
            {
                printf("incorrect input\n");
                 read_input();
            }
            else
                break;
        }
        for(;;)
        {
            if (((column_board_2+row_board_2)-(column_board_1+row_board_1))!=1)
            {
                printf("incorrect input\n");
                read_input();
            }
            else
                break;
        }



        break;
    }





}

void Read_command_com_6_easy()
{
    int i,j,x6,y6,m,n,i1;
    int row4,row5,column4,column5;
    int next1=0;
    int next2=0;
     //this condition to save and load mode means that it will print the lines until he enter save
    if (line>y){
    // to check if the is a box need to one line it complete it
    for (i=0; i<17; i+=4)
    {
        int t=0;
        int t2=0;
        for(j=0; j<21; j+=5)
        {
            x6=i;
            y6=j;
            if (board1[x6+1][y6]!=(char)179&&board1[x6][y6+1]==(char)196&&board1[x6+1][y6+5]==(char)179&&board1[x6+4][y6+1]==(char)196)
            {
                row4=x6;
                column4=y6;
                row5=x6+4;
                column5=y6;
                t=1;
                next1=1;
                next2=1;
            }
            else if (board1[x6+1][y6]==(char)179&&board1[x6][y6+1]!=(char)196&&board1[x6+1][y6+5]==(char)179&&board1[x6+4][y6+1]==(char)196)
            {
                row4=x6;
                column4=y6;
                row5=x6;
                column5=y6+5;
                t=1;
                next1=1;
                next2=1;
            }
            else if (board1[x6+1][y6]==(char)179&&board1[x6][y6+1]==(char)196&&board1[x6+1][y6+5]!=(char)179&&board1[x6+4][y6+1]==(char)196)
            {
                row4=x6;
                column4=y6+5;
                row5=x6+4;
                column5=y6+5;
                t=1;
                next1=1;
                next2=1;
            }
            else if (board1[x6+1][y6]==(char)179&&board1[x6][y6+1]==(char)196&&board1[x6+1][y6+5]==(char)179&&board1[x6+4][y6+1]!=(char)196)
            {
                row4=x6+4;
                column4=y6;
                row5=x6+4;
                column5=y6+5;
                t=1;
                next1=1;
                next2=1;
            }
            if (t==1)
            {
                t2=1;
                break;
            }


        }
        if (t2==1)
        {
            next1=1;
            next2=1;
            break;
        }
    }
    // if there is not a box need to one line it choose a random command
    if (next1!=1)
    {
        for (i=0; i<17; i+=4)
        {
            int t=1;
            int t2=1;
            for(j=0; j<21; j+=5)
            {
                srand(time(NULL));
                n=(rand()%5)*4;
                m=(rand()%5)*5;
                x6=n;
                y6=m;
                if (board1[x6][y6+1]!=(char)196)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6;
                    column5=y6+5;
                    t=0;
                    next2=1;
                }
                else  if (board1[x6+1][y6]!=(char)179)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6+4;
                    column5=y6;
                    t=0;
                    next2=1;
                }
                else if (board1[x6+1][y6+5]!=(char)179)
                {
                    row4=x6;
                    column4=y6+5;
                    row5=x6+4;
                    column5=y6+5;
                    t=0;
                    next2=1;
                }
                else if (board1[x6+4][y6+1]!=(char)196)
                {
                    row4=x6+4;
                    column4=y6;
                    row5=x6+4;
                    column5=y6+5;
                    t=0;
                    next2=1;
                }
                if (t==0)
                {
                    t2=0;
                    next2=1;
                    break;
                }
            }
            if (t2==0){
                     next2=1;
                break;}

        }
    }
// if the all random command are filled so it will choose the first unfilled line
    if (next2==0)
    {
        for (i=0; i<17; i+=4)
        {
            int t=1;
            int t2=1;
            for(j=0; j<21; j+=5)
            {
                x6=i;
                y6=j;
                if (board1[x6][y6+1]!=(char)196)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6;
                    column5=y6+5;
                    t=0;
                }
                else  if (board1[x6+1][y6]!=(char)179)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6+4;
                    column5=y6;
                    t=0;
                }
                else if (board1[x6+1][y6+5]!=(char)179)
                {
                    row4=x6;
                    column4=y6+5;
                    row5=x6+4;
                    column5=y6+5;
                    t=0;
                }
                else if (board1[x6+4][y6+1]!=(char)196)
                {
                    row4=x6+4;
                    column4=y6;
                    row5=x6+4;
                    column5=y6+5;
                    t=0;
                }
                if (t==0)
                {
                    t2=0;
                    break;
                }
            }
            if (t2==0)
                break;
        }
    }

    // to save the command in array then in a file to save and load later
    {

         te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}

fclose(lines1);}}
   else{



     for (i=te4;i<60;i++){
   row4= arr2[i][0];
    column4= arr2[i][1];
    row5 = arr2[i][2];
      column5= arr2[i][3];
      te4++;
      break;}


         te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}
    fclose(lines1);




   }





    if (row4==row5)
    {
        for(i1=(column4+1); i1<column5; i1++)
            board1[row4][i1]=(char)196;
    }
    if (column4==column5)
    {
        for(i1=(row4+1); i1<row5; i1++)
            board1[i1][column4]=(char)179;
    }


    printf("\n");
    check_square();
    init();
    system("cls");
     save();
    line++;
    print_board();
}
void player_vs_computer_easy()
{
      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            WORD saved_attributes; /* Save current attributes */
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            saved_attributes = consoleInfo.wAttributes;


    int num_of_lines;
    if (choose==1)
        num_of_lines=12;
    else
        num_of_lines=60;
    init();
    print_board();
     gotoxy(0,6);
     int i;


    while(turn!=num_of_lines)
    {

        while(player1==0)
        {


            re1=0;
              SetConsoleTextAttribute(hConsole, 14);
            for (i=39;i<55;i++){
           gotoxy(i,1);
           printf("%c",205);}
           for (i=39;i<55;i++){
           gotoxy(i,3);
           printf("%c",205);}
           SetConsoleTextAttribute(hConsole, saved_attributes);
              gotoxy (32,2);

            SetConsoleTextAttribute(hConsole, 12);
            printf("\t player one");
            SetConsoleTextAttribute(hConsole, saved_attributes);
             time_t t;
            t = time(NULL);
            local = localtime(&t);
            int C_Ts = local->tm_sec;
            int C_Tm=local->tm_min;
            Read_command() ;

            time_t a ;
            a = time(NULL);
            local = localtime(&a);
            int C_Ts1 = local->tm_sec;
            int C_Tm1 =local->tm_min;
            gotoxy(73,8);
            SetConsoleTextAttribute(hConsole,13);
            printf("min:sec %d:%d\n" ,abs(C_Tm1-C_Tm),abs(C_Ts1-C_Ts));
             SetConsoleTextAttribute(hConsole, saved_attributes);
            turn++;
            if (re1==1)
            {
                player1=0;
                player2=1;
            }
            else
            {
                player1=1;
                player2=0;
            }
            if (turn==num_of_lines)
                break;
        }
        if (turn==num_of_lines)
            break;
        while(player2==0)
        {

            re2=0;

            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\t computer");
            SetConsoleTextAttribute(hConsole, saved_attributes);
            if (choose==1)
                Read_command_com_2_easy();
            else
                Read_command_com_6_easy();
            turn++;
            if (re2==1)
            {
                player2=0;
                player1=1;
            }
            else
            {
                player2=1;
                player1=0;
            }
            if (turn==num_of_lines)
                break;
        }
        if (turn==num_of_lines)
            break;







    }
}
void Read_command_com_2_easy()
{
    int i,j,i1,x6,y6,m,n;
    int row4,row5,column4,column5;
    int next22=0;
    //this condition to save and load mode means that it will print the lines until he enter save
    if (line>y){
    // to choose a random command
    for (i=0; i<5; i+=4)
    {
        int t=1;
        int t2=1;
        for(j=0; j<6; j+=5)
        {
            srand(time(NULL));
            n=(rand()%2)*4;
            m=(rand()%2)*5;
            x6=n;
            y6=m;
            if (board[x6][y6+1]!=(char)196)
            {
                row4=x6;
                column4=y6;
                row5=x6;
                column5=y6+5;
                t=0;
                next22=1;
            }
            else  if (board[x6+1][y6]!=(char)179)
            {
                row4=x6;
                column4=y6;
                row5=x6+4;
                column5=y6;
                t=0;
                next22=1;
            }
            else if (board[x6+1][y6+5]!=(char)179)
            {
                row4=x6;
                column4=y6+5;
                row5=x6+4;
                column5=y6+5;
                t=0;
                next22=1;
            }
            else if (board[x6+4][y6+1]!=(char)196)
            {
                row4=x6+4;
                column4=y6;
                row5=x6+4;
                column5=y6+5;
                t=0;
                next22=1;
            }
            if (t==0)
            {
                t2=0;
                break;
            }
        }
        if (t2==0)
            break;
    }
    // if the random command is filled  it will choose the first unfilled line
    if (next22==0)
    {
        for (i=0; i<5; i+=4)
        {
            int t=1;
            int t2=1;
            for(j=0; j<6; j+=5)
            {
                x6=i;
                y6=j;
                if (board[x6][y6+1]!=(char)196)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6;
                    column5=y6+5;
                    t=0;
                }
                else  if (board[x6+1][y6]!=(char)179)
                {
                    row4=x6;
                    column4=y6;
                    row5=x6+4;
                    column5=y6;
                    t=0;
                }
                else if (board[x6+1][y6+5]!=(char)179)
                {
                    row4=x6;
                    column4=y6+5;
                    row5=x6+4;
                    column5=y6+5;
                    t=0;
                }
                else if (board[x6+4][y6+1]!=(char)196)
                {
                    row4=x6+4;
                    column4=y6;
                    row5=x6+4;
                    column5=y6+5;
                    t=0;
                }
                if (t==0)
                {
                    t2=0;
                    break;
                }
            }
            if (t2==0)
                break;
        }
    }
    // to save the command in array then in a file to save and load later
    {

         te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}

fclose(lines1);



    }}
    else{

        for (i=te4;i<60;i++){
   row4= arr2[i][0];
    column4= arr2[i][1];
    row5 = arr2[i][2];
      column5= arr2[i][3];
      te4++;
      break;}


         te2++;
    for(i=te2;i<60;i++){
          for (j=0;j<1;j++){

                arr2[i][j]=row4;

                arr2[i][j+1]=column4;

                arr2[i][j+2]=row5;

                arr2[i][j+3]=column5;

        }
        break;


  }



  FILE*lines1;
  if (te2==0)
  lines1=fopen("p2.text","w");
  else
  lines1=fopen("p2.text","a");
for (i=te2;i<60;i++)
 { for (j=0;j<1;j++){
       fprintf(lines1,"%d\n%d\n%d\n%d\n",arr2[i][j]=row4,arr2[i][j+1]=column4,arr2[i][j+2]=row5,arr2[i][j+3]=column5);}
       break;}
    fclose(lines1);




      }








    if (row4==row5)
    {
        for(i1=(column4+1); i1<column5; i1++)
            board[row4][i1]=(char)196;
    }
    if (column4==column5)
    {
        for(i1=(row4+1); i1<row5; i1++)
            board[i1][column4]=(char)179;
    }


    printf("\n");
    check_square();
    init();
    system("cls");
    save();
    line++;
    print_board();
}
int get_min(int x,int y)
{
    if (x>y)
        return y;
    return x;
}
int get_max(int x,int y)
{
    if (x>y)
        return x;
    return y;
}

void play()
{  if (decide5==1&&z!=1){
     zero();}
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes; /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 10);
     if (x==0||x==2){
     frame(10,40);
     gotoxy(57,11);
    printf("DOTS AND BOXES\n");
gotoxy(57,14);
    printf("(1)start game\n");
gotoxy(57,16);
    printf("(2)load game\n");
gotoxy(57,18);
    printf("(3)player'ranks\n");
gotoxy(57,20);
    printf("(4)about game\n");
    gotoxy(52,12.5);
    printf("--------------------------");

    SetConsoleTextAttribute(hConsole, saved_attributes);
    scanf("%d",&decide3);
    system("cls");}
    if (decide3==1)
    {   if (x==0||x==2){
      frame(6,30);
        gotoxy(50,12);
        printf("(1)two player\n\n");
        gotoxy(50,14);
        printf("(2)single player\n");
        scanf("%d",&decide);
         fflush(stdin);
        printf("\n\n");
        system("cls");}

           if (x==0||x==2){
         frame(6,30);
        gotoxy(50,12);
        printf("(1)  2*2\n");
        gotoxy(50,14);
        printf("(2)  5*5 \n");
        scanf("%d",&choose);
         fflush(stdin);
        system("cls");}

        if (decide==1)
        {   if (x==0||x==2){
             printf("\t\t");
             printf("\n\n\n\n\t\t\t\tenter your name\n");
             name(name1);
              fflush(stdin);
             printf("\t\t\t\tenter your name\n");
             name(name2);
              fflush(stdin);
             system("cls");}

            if (choose==1)
                player_vs_player();
            else
                player_vs_player();
             rank();
        }

        else
        { if (x==0||x==2){
            frame(6,30);
            gotoxy(50,12);
            printf("(1) hard\n");
            gotoxy(50,14);
            printf("(2) easy\n");
            scanf("%d",&decide2);
            fflush(stdin);
            system("cls");}
            if (choose==1)
            {     if (x==0||x==2){
                 printf("\n\n\n\n\t\t\t\tenter your name\n");
                             name(name1);
                              strcpy(name2,"computer");
                              fflush(stdin);
                              system("cls");}
                if (decide2==1)
                    player_vs_computer_hard();
                else
                    player_vs_computer_easy();
                rank();
            }
            else
            {
                   if (x==0||x==2){
                 printf("\n\n\n\n\t\t\t\tenter your name\n");
                            name(name1);
                              strcpy(name2,"computer");
                  fflush(stdin);
                           system("cls");}

                if (decide2==1)
                    player_vs_computer_hard();
                else
                    player_vs_computer_easy();
                 rank();
            }
        }
        if (player1_score>player2_score){
            printf("player one win");}
        else if (player1_score<player2_score){
            printf("player two win");}
        else if (player1_score==player2_score){
            printf("draw");}
            Sleep(5000);
            system("cls");
    }
     else if (decide3==3)
    {  int i;


    FILE *rank2;
 rank2 = fopen("file3.text","r");
 for (i=0;i<9;i++){
        fscanf(rank2,"%s",&b5[i].name5);
 }
 for (i=0;i<9;i++){
        fscanf(rank2,"%d",&b5[i].player_score5);
 }
  gotoxy(51,5);
 printf("leader board\n");
 for (i=0;i<9;i++){


         gotoxy(46,7+2*i);
          printf("[%d] %s",i+1,b5[i].name5);
          printf("\t");
          printf("%d",b5[i].player_score5);
            printf("\n");
              gotoxy(46,8+2*i);
         printf("------------------------");
           printf("\n");
 }
 Sleep(5000);
   fclose(rank2);

}
  else if  (decide3==2)
    {

   zero();
   load();
     x=1;
    z=1;
   play();
   x=2;
   y=-1;
   z=0;




  }




    else if (decide3==4){
        printf("Object of the board:\n\t\tgameTake more boxes than your opponent.\n"
                "\t\tYou move by connecting two dots with a line.When you place\n"
                "\t\tthe last wall of a single square (box),the box is yours.\n"
                "\t\tThe players move in turn but whenever a player takes a box(s)\n"
                "\t\the must move again.The board game ends when all 25 boxes\n"
               "\t\thave been taken.The player with the most boxes wins.\n");
        printf("Connecting dots:\n\t\tYou connect two dots by determine the two \n"
              " \t\tdots between the line like (row,column,row,column)..\n");
        printf("Taking boxes:\n\t\tWhen all four of the lines around a single box\n"
               "\t\tare in place, the player who made the last move owns the box.\n"
               "\t\tThe box is marked in that player number ( 1 or 2) and(s)he must move again.\n");
        printf("End of the board game:\n\t\tThe game is finished when all\n"
                "\t\tconnections have been made and all boxes have been taken.\n"
                "\t\tThe player who owns most boxes wins\n");
        printf("Strategy:\n\t\tOn the surface this doesnt look like a very\n"
              "\t\t strategic board game. A typical beginner game looks like this:\n"
              "\t\t in the beginning connections are made in more or less random fashion,\n"
              "\t\tand no boxes are taken. Only in the endgame one of the players is\n"
              "\t\t usually forced to give away boxes, and after that the players take \n"
              "\t\t turns in giving away ever-larger chains of boxes; the one who gets\n"
              "\t\t the last and largest chain usually wins. However, there are ways to\n"
              "\t\t force your opponent to give away the long chains at the end");

        Sleep(5000);}
        }


int gotoxy(int x,int y)
{
    COORD coord={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}
void loading()
{
    int r,q;
    gotoxy(50,10);

printf("loading........\n");
 gotoxy(50,11);
for(r=1;r<=20;r++)
{
    for(q=0;q<=100000000;q++);
    printf("%c",219);
}
Sleep(300);
system("cls");
}


void rank(){
    int i=0,cmp1,cmp2;
    int counter1=0,counter2=0;
 FILE *rank1;
 rank1 = fopen("file3.text","r");
 for (i=0;i<9;i++){
        fscanf(rank1,"%s",&b[i].name);
 }
 for (i=0;i<9;i++){
        fscanf(rank1,"%d",&b[i].player_score);
 }
 // an attempt to compare between names if there is the same name but it did not complete
 /*for(i=0;i<9;i++){
        cmp1=strcmp(b[i].name,name1);
        if (cmp1==0){
            if (player1_score<=b[i].player_score){
               counter1=1;}
            else
                 b[i].player_score=player1_score;}
      if (decide==1){
        cmp2=strcmp(b[i].name,name1);
     if (cmp2==0){
        if (player2_score<=b[i].player_score){
               counter2=1;}
            else
                b[i].player_score=player2_score;}
               }

     }*/


  fclose(rank1);
 int item=0,j;
 char item2[20];
for (i=0;i<9;i++){
             if  (player1_score>b[i].player_score){
                    item=b[i].player_score;
                    b[i].player_score=player1_score;
                    player1_score=item;
                     strcpy(item2,b[i].name);
                     strcpy(b[i].name,name1);
                     strcpy(name1,item2);}}
if (decide==1){
for (i=0;i<9;i++){
             if  (player2_score>b[i].player_score){
                    item=b[i].player_score;
                    b[i].player_score=player2_score;
                    player2_score=item;
                     strcpy(item2,b[i].name);
                     strcpy(b[i].name,name2);
                     strcpy(name2,item2);}}}

   int i1=0;
   FILE *rank2;
 rank2 = fopen("file3.text","w");
for (i1=0;i1<9;i1++){
    fprintf(rank2,"%s",b[i1].name);
    fprintf(rank2,"\n");}
for (i1=0;i1<9;i1++){
    fprintf(rank2,"%d",b[i1].player_score);
     fprintf(rank2,"\n");}

   fclose(rank2);


}

void frame(int m,int n)
{
     int i ;
   gotoxy(44,10);
   printf("%c",218);
   for(i=0 ;i<m;i++){

    gotoxy(44,11+i);
    printf("%c",179);
    }
    gotoxy(44,11+m);
    printf("%c",192);
    gotoxy(45,10);
   for ( i=0 ;i<n ; i++){
    printf("%c",196);

    }
    gotoxy(45+n,10);
    printf("%c\n",191);

    for(i=0 ;i<m;i++){
    gotoxy(45+n,11+i);
    printf("%c",179);
    }
    gotoxy(45+n,11+m);
    printf("%c",217);
    gotoxy(45,11+m);

   for ( i=0 ;i<n ; i++){

    printf("%c",196);}
}


void read_input(){
    int i,j=0;
    gets(str1);
    fflush(stdin);
    int len = strlen(str1);
    for( i=0;i<len;i++){
    if(str1[i]>='0'&&str1[i]<='5'&&j<=3){
        str2[j]=str1[i];
        j++;
        }
    }

    temps = atoi(str2);
    column_board_2_old=temps%10;
    temps/=10;
    row_board_2_old=temps%10;
    temps/=10;
    column_board_1_old=temps%10;
    temps/=10;
    row_board_1_old=temps;
    row_board_1=get_min(row_board_1_old,row_board_2_old);
    row_board_2=get_max(row_board_1_old,row_board_2_old);
    column_board_1=get_min(column_board_1_old,column_board_2_old);
    column_board_2=get_max(column_board_1_old,column_board_2_old);
check_correct_input(row_board_1,column_board_1,row_board_2,column_board_2);

}
void save (){
    int i,j;
FILE*sboard;
sboard=fopen("f1.text","w");
fprintf(sboard,"%d\n%d\n%d\n%d\n%s\n%s\n%d\n",decide3,decide,choose,decide2,name1,name2,line);
fclose(sboard);}














void load ()
{   int i,j;
FILE*sboard;
sboard=fopen("f1.text","r");
fscanf(sboard,"%d\n%d\n%d\n%d\n%s\n%s\n%d\n",&decide3,&decide,&choose,&decide2,&name1,&name2,&y);
fclose(sboard);

    FILE *play1;
 play1 = fopen("p1.text","r");
       for (i=0;i<60;i++){
        for (j=0;j<4;j++){
            fscanf(play1,"%d",&arr1[i][j]);
        }}
    fclose(play1);

    FILE *play2;
 play2 = fopen("p2.text","r");
       for (i=0;i<60;i++){
        for (j=0;j<4;j++){
            fscanf(play2,"%d",&arr2[i][j]);
        }}
     fclose(play2);
}
void zero(){


     int i ,j;


   for (i=0;i<9;i+=1){
   for (j=0;j<11;j+=1){
    board[i][j]=' ';}}
     choose=1;
    init();

     for (i=0;i<21;i+=1){
   for (j=0;j<26;j+=1){
    board1[i][j]=' ';}}
    choose=2;
    init();


    if (x==0||x==2){
    decide3=0;
    decide2=0;
    decide=0;
    choose=0;
    player1_score=0;
     player2_score=0;
     line=0;
     player1=0;
    player2=0;
     turn=0;}








}
void name(char str[20]){
int i,i1;
  gets(str);
  fflush(stdin);
  i=strcmp(str," ");
  i1=strcmp(str,"");
  if (i==0||i1==0)
 strcpy(str,"unknown");
 fflush(stdin);




}




















