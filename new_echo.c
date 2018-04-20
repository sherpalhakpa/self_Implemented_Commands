#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
//no arguments passed
if (argc == 1)
{
    printf("\n");
    exit(0);
}
//arguments passed
else if (argc>1)
{
     int i = 1;
     //while all arguments are not read
     while (i < argc)
     {
     printf("%s",argv[i]);
     printf(" ");//one space between [arg]s 
     i++;
     }
     printf("\n");//looks better
}
//something weird happened
else
{
     fprintf(stderr,"Error Occured!\n");
     exit(0);

}
return 0;
}
