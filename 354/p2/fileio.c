#include <stdio.h>

int main() {
    FILE *fp;
    /*
    fp = fopen("foo.txt", "w");
    fputs("CS354 @ Epic!\n", fp);
    fclose(fp);
    */

    fp = fopen("fileio.c", "r");
    char buff[100];

    while(fgets(buff, 100, fp)){
        printf("%s", buff);
    }
    return 0;
}
