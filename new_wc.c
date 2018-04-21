#include<fcntl.h> //header file for file operations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//max no of chars
const int MAX_CHAR =  256;
//function to count number of lines in a textfile 
int main(int argc,char*argv[])
{
//if more than two argument was passed after ./new_wc
if(argc > 3)
{
     fprintf(stderr, "allowed syntax is: ./new_wc [-l | c] [file.txt]\nargs inside[] are optional and | means only one of them at a time\nno more than 1 argument accepted\n");
     exit(0);
}
//if one argument i.e . filename is passed after ./new_tail
else if(argc == 2)
{
     FILE * fpointer;
     fpointer = fopen(argv[1],"r"); //open file passed
     if(fpointer == NULL)//couldn't open file
     {
      fprintf(stderr, "Cannot open file\n");
      exit(0);
     }
     int characterCount = 0;
     int wordCount = 0;
     int lineCount = 0;
     char ch;
     while((ch=fgetc(fpointer))!=EOF)
     {
     characterCount++;
     if(ch == ' ')
     {
       wordCount++;      
     }
     if(ch == '\n')
     {
        wordCount++;
        lineCount++;
     }
     }
     printf("%d ",lineCount);
     printf("%d ",wordCount);
     printf("%d ",characterCount);
     printf("%s\n",argv[1]);
}
else if(argc == 3)
{
    if(strcmp(argv[1],"-l")==0)
    {
     FILE * fpointer;
     fpointer = fopen(argv[2],"r"); //open file passed
     if(fpointer == NULL)//couldn't open file
     {
      fprintf(stderr, "Cannot open file\n");
      exit(0);
     }
     int characterCount = 0;
     int wordCount = 0;
     int lineCount = 0;
     char ch;
     while((ch=fgetc(fpointer))!=EOF)
     {
     characterCount++;
     if(ch == ' ')
     {
        wordCount++;
      }
     if(ch == '\n')
     {
        wordCount++;
        lineCount++;
     }
     }
     printf("%d ",lineCount);
     printf("%d ",wordCount);
     printf("%s\n", argv[2]);
     }
    else
    {
     FILE * fpointer;
     fpointer = fopen(argv[2],"r"); //open file passed
     if(fpointer == NULL)//couldn't open file
     {
      fprintf(stderr, "Cannot open file\n");
      exit(0);
     }
     int characterCount = 0;
     int wordCount = 0;
     int lineCount = 0;
     char ch;
     while((ch=fgetc(fpointer))!=EOF)
     {
     characterCount++;
     if(ch == ' ')
     {
        wordCount++;
      }
     if(ch == '\n')
     {
        wordCount++;
        lineCount++;
     }
     }
     printf("%d ",characterCount);
     printf("%d ",wordCount);
     printf("%s\n",argv[2]);
    }
}
else if(argc ==1) //no arguments after ./new_cat
{
     int characterCount = 0;
     int wordCount = 0;
     int lineCount = 0;
     char ch;
     while((scanf ("%c", &ch))!=EOF)
     {
     characterCount++;
     if(ch == ' ')
     {
       wordCount++;      
     }
     if(ch == '\n')
     {
        wordCount++;
        lineCount++;
     }
     }
     printf("%d ",lineCount);
     printf("%d ",wordCount);
     printf("%d\n",characterCount);
 
}
return 0;
}
