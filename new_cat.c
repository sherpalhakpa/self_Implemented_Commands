#include<fcntl.h> //header file for file operations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc,char*argv[])
{
if(argc > 2)
{
     fprintf(stderr, "allowed syntax is: ./new_cat [file.txt]\nfile.txt is optional\nno more than 1 argument accepted");
}
else if(argc == 2)
{
     FILE * fpointer;
     fpointer = fopen(argv[1],"r");
     char content[256];
     
     while(!feof(fpointer)){
 	fget(content,256,fpointer);
        puts(content);
     }
     close(fpointer);
}





return 0;
}

