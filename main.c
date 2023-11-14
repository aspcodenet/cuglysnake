// TISDAG Kodartisdag !

// Syfte: kodvana 

// Men först: gå igenom multidimensionella arrayer
// genom ett praktiskt exempel - en ETCH-A-SCETCH som kan bli en 
// SNAKE om ni vill

// VI SKA SKAPA ETCH A SCETCH IDAG
// https://wokwi.com/projects/378100012183685121
// fast vi bygger i console
// som ni kan bygga vidare till SNAKE

// Endast egen programmering sen




// #####################
// #      @            #  
// #                   #  
// #                   #  
// #                   #  
// #                   #  
// #                   #  
// #                   #  
// #                   #  
// #                   #  
// #                   #  
// #####################
// Ange vad du vill göra:u + ENTER           

#define ROWS 10 //
#define COLS 30 //
#define WALL '#'
#include <stdio.h>

typedef struct {
    int x;
    int y;
} SNAKE;

//#define clrscr() printf("\e[1;1H\e[2J")

void clrscr(){
    printf("\e[1;1H\e[2J");
}

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}


void drawTopOrBottomBoundaryRow(){
    for(int i = 0; i < COLS+2;i++){
        printf("%c", WALL);
    }
    printf("\n");
}

void drawMiddleBoundaryRow(){
    printf("#");
    for(int i = 0; i < COLS;i++){
        printf(" ");    
    }
    printf("#");
    printf("\n");
}

void drawBoundaries(){
    drawTopOrBottomBoundaryRow();

    for(int row = 0; row < ROWS;row++){
        drawMiddleBoundaryRow();
    }

    drawTopOrBottomBoundaryRow();
} 

void drawSnake(SNAKE snake){
    gotoxy(snake.x,snake.y);
    printf("@");
}
        

int main(){
    SNAKE snake;
    snake.x = 5;
    snake.y = 4;
    while(1){ // gameloop
        clrscr();
        //rita ut spelplanen
        drawBoundaries();
        // rita vår snake
        drawSnake(snake);
        //känna om vi ska byta riktning (läs joystick)
        //                  fråga vad vill du göra  U D L R
        // flytta vår snake
        char input[20];
        gotoxy(0,ROWS+3);
        printf("Enter what to do:");       
        scanf(" %s", input);
        if(input[0] == 'u'){
            snake.y--; 
        }
        else if(input[0] == 'd'){
            snake.y++; 
        }
        else if(input[0] == 'r'){
            snake.x++; 
        }
        else if(input[0] == 'l'){
            snake.x--; 
        }
    }
    return 0;
}