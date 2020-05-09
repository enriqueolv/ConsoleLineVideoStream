#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    struct winsize w;
    


    while(1){
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        printf("lines %d\n", w.ws_row);
        printf("columns %d\n", w.ws_col);
        printf("\n\n");
    }



    return 0;
}