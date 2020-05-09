#include <stdio.h>
#include "CLVS.h"


int main(){

    int columns, rows;
    CLVS_get_console_sizes(&columns, &rows);
    printf("%d, %d", columns, rows);

    print_pixel(10, 10, 'l'); 
    return 0;
}
