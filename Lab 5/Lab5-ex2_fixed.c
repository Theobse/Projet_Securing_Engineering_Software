#include <stdio.h>
void main()
{
    char p[6] = "Mizzou";//code modified segment fault corrected
    p[ 3 ] = 'P';
    printf("%s",p);
}