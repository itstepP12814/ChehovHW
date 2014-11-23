#include "header.h"
void calc(char *ch, double *a, double *b, double *c)
{
    switch(*ch)
    {
    case '+':
        *c=*a+*b;
        break;
    case '-':
        *c=*a-*b;
        break;
    case '*':
        *c=*a*(*b);
        break;
    case '/':
        *c=*a/(*b);
        break;
    case 'S':
    case 's':
        *c=sqrt(*a);
        break;
    case 'Q':
    case 'q':
        *c=*a*(*a);
    default :
        break;
    }
}
