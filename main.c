#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX 20
#define MAXCALDA 399

void setUp();
void mapa();
void entrada();
void logica();

int gameOver=0; // loop controller
int x,y; // position of snake head
int score; // player score 
int encX,encY; // value for increment the player position
int comX,comY; // food position
int calX[MAXCALDA],calY[MAXCALDA],caldaT; // array for tail in x and y, size of tail

int record; // For the height score
FILE *data; // file data


// Function for setup everything
void setUp(){
    data = fopen("data","rb");
    if(data == NULL){
        printf("Erro na abertira");
        exit(1);
    }
    /*record = 10;
    fwrite(&record,sizeof(int),1,data);*/
    fread(&record,sizeof(int),1,data);
    fclose(data);

    srand(time(NULL));
    x=MAX/2;
    y=MAX/2;
    encX=0;
    encY=0;
    comX=rand()%(MAX-1);
    comY=rand()%(MAX-1);
    score=0;
    caldaT=0;
}

// Draw the map
void mapa(){
    int i,j,k;
    for(i=0;i<MAX+2;i++){
        printf("#");
    }
    printf("\n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            if(j==0){
                printf("#");
            }
            if(j==x && i==y){
                printf("O");
            }else if(j==comX && i==comY){
                printf("T");
            }else{
                //mostrar calda
                int arrumarCanto = 0;
                for(k=0;k<caldaT;k++){
                    if(calX[k]==j && calY[k]==i){
                        printf("o");
                        arrumarCanto=1;
                    }
                }
                if(arrumarCanto!=1){
                    printf(" ");
                }
            }
            if(j==MAX-1){
                printf("#");
            }
        }
        printf("\n");
    }
    for(i=0;i<MAX+2;i++){
        printf("#");
    }
    printf("\nScore: %d",score);
    printf("\nRecorde: %d",record);

}

// input of keyboard
void entrada(){
    char comando;
    while(_kbhit()){
        switch(comando=getch()){
            case 'w':
                encX=0;
                encY=-1;
            break;
            case 's':
                encX=0;
                encY=1;
            break;
            case 'a':
                encX=-1;
                encY=0;
            break;
            case 'd':
                encX=1;
                encY=0;
            break;
            case 'z':
                gameOver=1;
            break;
        }
    }

}

// Game logic
void logica(){

    int i;
    int posCalX,posCalY // the position of the tail behind the head
    int posSeguiCalX, posSeguiCalY; // help variable for change the positions
    calX[0]=x;
    calY[0]=y;
    for(i=1;i<MAXCALDA;i++){ // like a "bubbleSort" for tail caldas
        posSeguiCalX = posCalX;
        posSeguiCalY = posCalY;
        posCalX=calX[i];
        posCalY=calY[i];
        calX[i]=posSeguiCalX;
        calY[i]=posSeguiCalY;
    }
    ////////////////////
    x += encX;
    y += encY;
    if(x<0){
        x=MAX-1;
    }
    if(x>MAX-1){
        x=0;
    }
    if(y<0){
        y=MAX-1;
    }
    if(y>MAX-1){
        y=0;
    }
    if(x==comX && y==comY){
        score+=10;
        comX=rand()%(MAX-1);
        comY=rand()%(MAX-1);
        caldaT++;
    }
    for(i=0;i<caldaT;i++){
        if(calX[i]==x && calY[i]==y){
            gameOver=1;
        }
    }

}

// main function
int main()
{
    setUp();
    // Game loop
    while(gameOver!=1){
        entrada();
        logica();
        mapa();
        Sleep(80);
        system("cls");
    }
    if(score > record){
        data=fopen("data","wb");
        if(data == NULL){
            printf("Falha ao salvar o recorde\n");
            exit(1);
        }
        fwrite(&score,sizeof(int),1,data);
        fclose(data);
        printf("********************\n");
        printf("*** NOVO RECORDE ***\n");
        printf("********************\n");
        printf("NOVO RECORD: %d\n\n",score);
        system("pause");
    }else{
        printf("!!!!!!!!!!!!!!!!!\n");
        printf("!!! GAME OVER !!!\n");
        printf("!!!!!!!!!!!!!!!!!\n");
        printf("SCORE: %d\n",score);
        if(score != record){
            printf("RECORD: %d\n",record);
        }
        system("pause");
    }

    return 0;
}

