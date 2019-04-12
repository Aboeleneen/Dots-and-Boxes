#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
struct tm *local ;
char board[9][11];
char board1[21][26];
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
int next11=0;
int next22=0;
int choose;
int gotoxy(int x,int y);



int main()
{

    play();
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
    printf("player one score:%d\n",player1_score);
    printf("player two score:%d\n",player2_score);
    printf("line:%d\n",line);
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
            if  (choose==1)
                printf("%c",board[i][j]);
            else
                printf("%c",board1[i][j]);
        }
        printf("\n");

    }
}
void Read_command()
{
    int i,j;
    int row4,row5,column4,column5;
    printf("\nenter two dots\n");
    scanf("%d%d%d%d", &row_board_1_old,&column_board_1_old,&row_board_2_old,&column_board_2_old);

    row_board_1=get_min(row_board_1_old,row_board_2_old);
    row_board_2=get_max(row_board_1_old,row_board_2_old);
    column_board_1=get_min(column_board_1_old,column_board_2_old);
    column_board_2=get_max(column_board_1_old,column_board_2_old);
    check_correct_input(row_board_1,column_board_1,row_board_2,column_board_2);
    row4=row_board_1*4;
    row5=row_board_2*4;
    column4=column_board_1*5;
    column5=column_board_2*5;
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
    line++;
    print_board();
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
            gotoxy(0,3);
            printf("min:sec %d:%d\n" ,abs(C_Tm1-C_Tm),abs(C_Ts1-C_Ts));
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

            SetConsoleTextAttribute(hConsole, 11);
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
                        gotoxy(0,3);
            printf("min:sec %d:%d\n" ,abs(C_Tm1-C_Tm),abs(C_Ts1-C_Ts));

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
void Read_command_com_6_hard()
{
    int i,j,i1,x6,y6;
    int row4,row5,column4,column5;
    int next1=0;
    int next2=0;
    int next3=0;
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
    /* if  there is not any box need to one line it look for a box without any line to and if it play it won't give
    the player chance to complete a box*/
    if (next1==0)
    {
        int next2=0;
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







                if (t3==1)
                {
                    t4=1;
                    break;
                }}

            if (t4==1)
                break;
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
    line++;
    print_board();



}}
void player_vs_computer_hard()
{
    int num_of_lines;
    if (choose==1)
        num_of_lines=12;
    else
        num_of_lines=60;
    init();
    print_board();


    while(turn!=num_of_lines)
    {

        while(player1==0)
        {


            re1=0;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            WORD saved_attributes; /* Save current attributes */
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            saved_attributes = consoleInfo.wAttributes;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

            printf("\t player one");
            SetConsoleTextAttribute(hConsole, saved_attributes);
              time_t t;
            t = time(NULL);
            local = localtime(&t);
            int C_Ts = local->tm_sec;
            int C_Tm=local->tm_min;
            Read_command();

            time_t a ;
            a = time(NULL);
            local = localtime(&a);
            int C_Ts1 = local->tm_sec;
            int C_Tm1 =local->tm_min;
            printf("min:sec %d:%d" ,C_Tm1-C_Tm,C_Ts1-C_Ts);
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
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            WORD saved_attributes; /* Save current attributes */
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            saved_attributes = consoleInfo.wAttributes;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("\t computer");
            SetConsoleTextAttribute(hConsole, saved_attributes);
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

    int i,j;
    for(;;)
    {
        for(;;)
        {
            if (row_board_1!=row_board_2&&column_board_1!=column_board_2)
            {
                printf("incorrect input\n");
                scanf("%d%d%d%d", &row_board_1,&column_board_1,&row_board_2,&column_board_2);
            }
            else
                break;
        }
        for(;;)
        {

            int max_number;
            if (choose==1)
                max_number=2;
            else
                max_number=5;
            if (row_board_1>max_number||row_board_2>max_number||column_board_1>max_number||column_board_2>max_number)
            {
                printf("incorrect input\n");
                scanf("%d%d%d%d", &row_board_1,&column_board_1,&row_board_2,&column_board_2);
            }
            else
                break;
        }
        for(;;)
        {
            if (((column_board_2+row_board_2)-(column_board_1+row_board_1))!=1)
            {
                printf("incorrect input\n");
                scanf("%d%d%d%d", &row_board_1,&column_board_1,&row_board_2,&column_board_2);
            }
            else
                break;
        }

        for(;;)
        {
            if (((column_board_2+row_board_2)-(column_board_1+row_board_1))!=1)
            {
                printf("incorrect input\n");
                scanf("%d%d%d%d", &row_board_1,&column_board_1,&row_board_2,&column_board_2);
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
                    break;
                }
            }
            if (t2==0)
                break;

        }
    }
// if the all random command are filled so it will choose the first unfilled line
    if (next2!=1)
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
    line++;
    print_board();
}
void player_vs_computer_easy()
{
    int num_of_lines;
    if (choose==1)
        num_of_lines=12;
    else
        num_of_lines=60;
    init();
    print_board();


    while(turn!=num_of_lines)
    {

        while(player1==0)
        {


            re1=0;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            WORD saved_attributes; /* Save current attributes */
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            saved_attributes = consoleInfo.wAttributes;
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

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
            printf("min:sec %d:%d" ,C_Tm1-C_Tm,C_Ts1-C_Ts);
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
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            WORD saved_attributes; /* Save current attributes */
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            saved_attributes = consoleInfo.wAttributes;
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

/*void convert(){
 for(;;){
            for(;;){
        if (n==1||n==2||n==3){
            r1_new=0;
            break;}
        if (n==6||n==4||n==5){
            r1_new=1;
            break;}

         if (n==9||n==7||n==8){
            r1_new=2;
            break;}}
           for(;;){
            if (m==1||m==2||m==3){
            r2_new=0;
            break;}
        if (m==6||m==4||m==5){
            r2_new=1;
            break;}

         if (m==9||m==7||m==8){
            r2_new=2;
            break; }}
            for(;;){
            if (n==1||n==4||n==7){
            column_board_1_new=((1%6)-1);
            break;}
        if (n==2||n==5||n==8){
            column_board_1_new=((2%6)-1);
            break;}
         if (n==3||n==6||n==9){
            column_board_1_new=((3%6)-1);
            break; }}
            for(;;){
            if (m==1||m==4||m==7){
            column_board_2_new=((1%6)-1);
            break;}
        if (m==2||m==5||m==8){
            column_board_2_new=((2%6)-1);
            break;}
         if (m==3||m==6||m==9){
            column_board_2_new=((3%6)-1);
            break; }}
            break;



           }

}*/





void play()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes; /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, 14);
    printf("\t\t\t\t\t********************************************\n");
    printf("\t\t\t\t\t*                                          *\n");
    printf("\t\t\t\t\t*             DOTS AND BOXES               *\n");
    printf("\t\t\t\t\t*                                          *\n");
    printf("\t\t\t\t\t********************************************\n");
    printf("\t\t\t\t\t*           (1)start game                  *\n");
    printf("\t\t\t\t\t********************************************\n");
    printf("\t\t\t\t\t*           (2)load game                   *\n");
    printf("\t\t\t\t\t********************************************\n");
    printf("\t\t\t\t\t*           (3)player'ranks                *\n");
    printf("\t\t\t\t\t********************************************\n");
    printf("\t\t\t\t\t*           (4)about game                  *\n");
    printf("\t\t\t\t\t********************************************\n");
    SetConsoleTextAttribute(hConsole, saved_attributes);

    int decide3;
    scanf("%d",&decide3);
    system("cls");
    if (decide3==1)
    {
        int decide;
        printf("\n\n\n\t\t\t(1)two player\n\n\n");
        printf("\t\t\t(2)single player\n\n\n");
        scanf("%d",&decide);
        printf("\n\n");
        system("cls");
        printf("\n\n\n\t\t\t(1)  2*2\n\n\n");
        printf("\t\t\t(2)  5*5 \n");
        scanf("%d",&choose);
        system("cls");
        int decide2;

        if (decide==1)
        {
            if (choose==1)
                player_vs_player();
            else
                player_vs_player();
        }

        else
        {
            printf("\n\n\n\t\t\t(1) hard\n");
            printf("\n\n\n\t\t\t(2) easy\n");
            scanf("%d",&decide2);
            system("cls");
            if (choose==1)
            {

                if (decide2==1)
                    player_vs_computer_hard();
                else
                    player_vs_computer_easy();
            }
            else
            {
                if (decide2==1)
                    player_vs_computer_hard();
                else
                    player_vs_computer_easy();
            }
        }
        if (player1_score>player2_score)
            printf("\t\t\tplayer one win\n\n");
        else if (player1_score<player2_score)
            printf("player two win");
        else
            printf("draw");

    }
    else
        printf("\n\n\n\t\t\t\tcoming soon\n\n\n");

}
int gotoxy(int x,int y)
{
    COORD coord={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);




}
