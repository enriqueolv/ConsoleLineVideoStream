#include <windows.h>
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#ifndef CLVS_MAX_COLS
#define CLVS_MAX_COLS 200
#endif
#ifndef CLVS_MAX_ROWS
#define CLVS_MAX_ROWS 100
#endif





char old_picture[CLVS_MAX_COLS][CLVS_MAX_ROWS];
//EL transmisor de vide necesita saber cuando ha sido actualizado el 
//el tamaño de la consola para de ser así, limpiar la pantalla para que
//el flujo de video no se vea distorcionado
int CLVS_old_columns;
int CLVS_old_rows;


void CLVS_get_console_sizes(int* columns, int* rows){
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;    
}


//funcion interna usada por draw_picture, no debe formar parte de la interfaz de CLVS
void print_pixel(char pix, int col, int row){
    COORD coord;
    coord.X = col;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("%c", pix);
}

void CLVS_Start_Video(){
    system("@cls||clear");
    
}

void CLVS_Finalize_Video(){
    system("@cls||clear");
}




void CLVS_draw_picture(char** picture, int pic_columns, int pic_rows){
    
    if((CLVS_old_columns != pic_columns) || (CLVS_old_rows != pic_rows)){
        system("@cls||clear");
    }

    CLVS_old_columns = pic_columns;
    CLVS_old_rows = pic_rows;

    for(int r=0; r<pic_columns; r++){
        for(int c=0; c< pic_rows; c++){
            if(old_picture[r][c] != picture[r][c]){            
                print_pixel(picture[r][c], c, r);
            }
            old_picture[r][c] = picture[r][c];
        }
    }

}



