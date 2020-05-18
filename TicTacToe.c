#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Αρχικοποίηση μεγέθους πινάκων
#define MAXTABLE 25 
#define USETABLE 9
//Αρχικοποίηση μεταβλητών και πινάκων
int board[ MAXTABLE ];
enum {E, O, X, B};
enum {HUMAN_WIN, COMPUTER_WIN, DRAW};

//Χρησιμοποιείται για την μετατροπή του πίνακα με τα όρια σε 
//πίνακα με μεταβλητές από 0-8 που θα δίνει ο χρήστης
const int convertTo25[USETABLE] = {
    6,7,8,
    11,12,13,
    16,17,18
};

//Για τις κατευθύνσεις που θα ελέγχει τη νίκη   
const int Directions[4] = {1, 5, 4, 6};

//Αρχικοποίηση πίνακα 
void initBoard(){
    for (int i=0; i<MAXTABLE; i++){
        board[i] = B;
    }
    for (int i=0; i<USETABLE; i++){
        board[ convertTo25[i] ] = E;
    }
}

//Εκτύπωση Board
void printBoard(){
    char intToChar[] = "-OX+";
    printf("\nBoard\n");
    for (int i=0; i<USETABLE; i++){  
        if (i%3 == 0  && i!=0)  printf("\n");
        printf("%4c",intToChar[ board[convertTo25[i]] ] );
        }
    printf("\n");
}

//Έλεγχος του πίνακα εάν έχει κάποια άδεια θέση 
int hasEmpty(){
    for (int i=0; i<USETABLE; i++){
        if (board[convertTo25[i]] == E) 
            return 1;
    }
    return 0;
}

void makeMove(int sq, int side){
    board[sq] = side;
}

int getComputerMove(){
    int freePlaces = 0;
    int availableMoves[9];
    int rndMove = 0;

    for (int i=0; i<USETABLE; i++){
        if( board[convertTo25[i]] == E){
            availableMoves[freePlaces++] = convertTo25[i];
        }
    }
    rndMove = (rand()  % freePlaces);
    return availableMoves[rndMove];
}

int getHumanMove(){

    int place = -1;
    do{  
        printf("Επιλεξτε θεση για το  Χ apo to 0-8");
        if ( scanf("%d", &place) == 1 
            && (place >=0 && place <=8) 
            && board[convertTo25[place]] == E){ 
            getchar();
            printf("edoses %d\n",place);    
            //board[ convertTo25[place] ] = X;
            //printBoard();
        }else{
            printf("mono arithmous apo 0-8 kai edoses  %d \n ", place);
            place = getchar();
        }
        fflush(stdin);
    }while( place<0 || place>9);
return convertTo25[place];
}
void runGame(){
    int gameOver = 0,
    side = X,
    lastMoveMade = 0;
    

    initBoard();

    while(!gameOver){
        if (side == X){
            lastMoveMade  = getHumanMove();
            makeMove( lastMoveMade, side);
            side = O;
            printBoard();
        }else{
            lastMoveMade = getComputerMove();
            makeMove( lastMoveMade, side);
            side = X;
            printBoard();
        }

//        if (){

  //      }

        if(!hasEmpty()){
            printf("DRAW\n");
            gameOver = 1;            
        }
    
    }

}

int main (int argc, char* argv[]){

    initBoard();
    printBoard();
    runGame();
    return 1;
}
