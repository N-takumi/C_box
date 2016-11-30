#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define HPmin 0

    struct data{
        int  x;
        int  y;
        int hp;
    };

void map(struct data a,struct data b);
void GameStart();
void GameEnd();

int main(void){

    int key,flag = 1,num;
    int bx,by;
    struct data  pos = {2,2};
    struct data bpos;
                bpos.hp = 5;
    srand((unsigned)time(NULL));
     bx = (int)(rand() / (RAND_MAX+1.0) * 5.0);
     by = (int)(rand() / (RAND_MAX+1.0) * 5.0);
    bpos.x = bx;
    bpos.y = by;
    system("cls");

    GameStart();
    map(pos,bpos);


    while(flag == 1){



        if(kbhit()){
            system("cls");
            key = getch();
            if(key == 0 || key == 224)key = getch();

        switch(key){
            case 0x48:  if(pos.y == 0)break;
                         pos.y--; break;
            case 0x50: if(pos.y == 4)break;
                         pos.y++; break;
            case 0x4b: if(pos.x == 0)break;
                         pos.x--; break;
            case 0x4d: if(pos.x == 4)break;
                         pos.x++; break;
        }
            num = 1 + (int)(rand()*(4-1+1.0)/(1.0+RAND_MAX));
            if(num == 1){
                bpos.x = (int)(rand() / (RAND_MAX+1.0) * 5.0);
                bpos.y = (int)(rand() / (RAND_MAX+1.0) * 5.0);
            }
                if(pos.x == bpos.x && pos.y == bpos.y){
                    Sleep(300);
                    Beep(830,100);
                    Beep(880,100);
                     bpos.hp -= 1;
                     while(pos.x == bpos.x && pos.y == bpos.y){
                     bpos.x = (int)(rand() / (RAND_MAX+1.0) * 5.0);
                     bpos.y = (int)(rand() / (RAND_MAX+1.0) * 5.0);
                     system("cls");
                     }
                }
                if(bpos.hp == HPmin)flag = 0;
        }
        map(pos,bpos);
        printf("\n\n (%d, %d) [8/2/4/6]>\n\n十字キーを使って%dを\n追いかけてください！\n1があなたです\n",pos.x,pos.y,bpos.hp);
    //  Sleep(10);
        system("cls");
    }
    GameEnd();

    return 0;
}

void map(struct data a,struct data b){

    int i,j;
    int  map[5][5];


     for(i = 0;i<5;i++){
        for(j = 0;j<5;j++){
        map[i][j] = 0;
        }
    }

    map[a.y][a.x] = 1;
    map[b.y][b.x] = b.hp;

    printf("\n\n");
    printf("    %d %d %d %d %d \n",map[0][0],map[0][1],map[0][2],map[0][3],map[0][4]);
    printf("    %d %d %d %d %d \n",map[1][0],map[1][1],map[1][2],map[1][3],map[1][4]);
    printf("    %d %d %d %d %d \n",map[2][0],map[2][1],map[2][2],map[2][3],map[2][4]);
    printf("    %d %d %d %d %d \n",map[3][0],map[3][1],map[3][2],map[3][3],map[3][4]);
    printf("    %d %d %d %d %d \n",map[4][0],map[4][1],map[4][2],map[4][3],map[4][4]);
}
void GameStart(){
    system("cls");
    printf("\n\n\n");
    printf("     GAME\n     Start!\n");
    Beep(600,200);
    Beep(900,200);
    system("cls");
}
void GameEnd(){
    system("cls");
    printf("\n\n\n");
    printf("     GAME\n     Clear!\n");
    Sleep(200);
    Beep(740,90);
    Beep(698,90);
    Beep(587,90);
    Beep(415,90);
    Beep(392,90);
    Beep(587,90);
    Beep(784,90);
    Beep(988,90);
    Sleep(1000);
    system("cls");
}
