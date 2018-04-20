#include<fcntl.h> //header file for file operations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char*argv[])
{
if(argc > 2)
{
     fprintf(stderr, "allowed syntax is: ./new_cat [file.txt]\nfile.txt is optional\nno more than 1 argument accepted\n");
     exit(0);
}
else if(argc == 2)
{
     FILE * fpointer;
     char content[256];
     fpointer = fopen(argv[1],"r");
     if(fpointer == NULL)
     {
      fprintf(stderr, "Cannot open file\n");
      exit(0);
     }
     while(!feof(fpointer)){
        fgets(content, 256, fpointer);
        printf("%s", content);
     }
     fclose(fpointer);
}


return 0;
}

