#include <stdio.h>

#define MAXTABLE 25 
#define USETABLE 9
int board[ MAXTABLE ];
enum pioni{E, O, X, B};
const int convertTo25[USETABLE] = {
    6,7,8,
    11,12,13,
    16,17,18
};


void initBoard(){
    for (int i=0; i<MAXTABLE; i++){
        board[i] = B;
    }
    for (int i=0; i<USETABLE; i++){
        board[ convertTo25[i] ] = E;
    }
}

void printBoard(){
    for (int i=0; i<MAXTABLE; i++){  
        if (i%5 == 0  && i!=0)
            printf("\n");
        //board[i] = i;
        //printf("\t%d",board[i] );
        switch (board[i]){
            case X:
                printf("\tX");
                break;
            case E:
                printf("\tE");
                break;
            case O:
                printf("\tO");
                break;
            case B:
                printf("\t+");
        }
    }
    printf("\n");
}

void runGame(){
   int place = -1;
    do{  
        printf("Επιλεξτε θεση για το  Χ apo to 1-9");
        if ( scanf("%d",&place) == 1 && (place >=0 || place <=9)){
            //getchar();
            printf("edoses %d\n",place);    
            board[ place ] = X;
            printBoard();
        }else{
            printf("mono arithmous apo 0-9 kai edoses  %d \n ", place);
            place = getchar();
        }
        fflush(stdin);
    }while( place<0 || place>9);
}

int main (int argc, char* argv[]){
    initBoard();
    printBoard();
    runGame();
    return 1;
}
