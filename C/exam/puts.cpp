#include "header.h"
void sputs(char *name) {
    FILE* p_file=fopen(name, "wb");
    char str[SIZE], *p1, *p2;
    int c;
    cout<<"\tВведите любой текст, для прекращения ввода введите ~\n";
    while(1) {
        scanf("%s", &str);
        fputs(str, p_file);
        p2=strchr(str, '~');
        if(p2!=NULL) break;
    }
    fcloseall();
}
