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
//wierd format 
else
{
     fprintf(stderr,"Allowed format is ./new_echo [arg]...[arg]\n");
     exit(0);

}
return 0;
}
