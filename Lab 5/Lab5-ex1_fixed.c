#include <stdio.h>
 
int main()
{
    char* fileName;
    printf("Specify file name you would like to print to: \n");
    scanf("%s",fileName);//code modified segment fault corrected
 

    FILE* file1 = fopen(fileName, "a+");
 
    char c;
    while ((c=getchar()) != EOF)
    {
        fprintf(file1,"%c", c);//code modified segment fault corrected
    }
 
    fclose(file1);
 
    printf("CTRL+d is a correct ending");
 
    return 0;
}