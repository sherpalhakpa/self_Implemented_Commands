#include<fcntl.h> //header file for file operations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//max no of chars
//function to count number of lines in a textfile 
const int MAX_CHAR =  256;
int countLine(FILE * textfile, char content[], int size)
{
int line = 0;
while(!feof(textfile)){
    fgets(content, size, textfile)
    line++;
}
return line;
}
int main(int argc,char*argv[])
{
//if more than three argument was passed after ./new_tail
if(argc > 4)
{
     fprintf(stderr, "allowed syntax is: ./new_tail [-n N] [file.txt]\nargs inside[] are optional\nno more than 1 argument accepted\n");
     exit(0);
}
//if one argument i.e . filename is passed after ./new_tail
else if(argc == 2)
{
     FILE * fpointer;
     char content[256]; //for storing content
     fpointer = fopen(argv[1],"r"); //open file passed
     if(fpointer == NULL)//couldn't open file
     {
      fprintf(stderr, "Cannot open file\n");
      exit(0);
     }
     int totalLine = countLine(fpointer, content[], MAX_CHAR)
     int startLine = totalLine - 5;
     int currentLine = 1;
     while(!feof(fpointer)){
     if(currentLine == startLine)
     {
        
           
 

     }
fgets(content, 256, fpointer); //read one line as a string
        currentLine++;
     }
     fclose(fpointer); //close file
}
else if(argc ==1) //no arguments after ./new_cat
{
    char content[256];
    printf("type in text to cat\n hit Ctrl+D when you are done\n");
    while(fgets(content,256, stdin))
    {
      printf("%s",content); //print whatever was input
    }
}
return 0;
}
 
