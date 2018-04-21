#include<fcntl.h> //header file for file operations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
//if more than one argument was passed after ./new_cat
if(argc > 2)
{
     fprintf(stderr, "allowed format is: ./new_cat [file.txt]\nfile.txt is optional\nno more than 2 argument accepted\n");
     exit(0);
}
//if one argument i.e . filename is passed after ./new_cat
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
     while(!feof(fpointer)){
        fgets(content, 256, fpointer); //read one line as a string
        printf("%s", content);
     }
     fclose(fpointer); //close file
}
else if(argc ==1) //no arguments after ./new_cat
{
    char content[256];
    while(fgets(content,256, stdin))
    {
      printf("%s",content); //print whatever was input
    }
}
return 0;
}

