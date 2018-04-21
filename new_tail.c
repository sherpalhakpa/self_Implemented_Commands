#include<fcntl.h> //header file for file operations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//max no of chars
const int MAX_CHAR =  256;
//function to count number of lines in a textfile 
int countLine(FILE * textfile, char * content, const int size)
{
int line = 0;
while(!feof(textfile)){
    fgets(content, size, textfile);
    line++;
}
line--; //remove extra line read at end
return line;
}
//funtion to print specific lines from a a text file if given the startingLine
void printSpecificLine(FILE * textfile, char * content, const int size, int startLine)
{
    int currentLine = 0;//counter
    while(!feof(textfile)){
        if(currentLine == startLine)
        {
            while(!feof(textfile)){
            printf("here");
            fgets(content, size, textfile); //read one line as a string
            printf("%s",content);
            currentLine++;
            }
        return;
        }
        fgets(content, size, textfile);//only print the last n lines
        currentLine++;
        printf("%d",currentLine);
    }
    return;
}

int main(int argc,char*argv[])
{
//if more than three argument was passed after ./new_tail
if(argc > 4)
{
    fprintf(stderr, "allowed syntax is: ./new_tail [-n N] [file.txt]\nargs inside[] are optional\nno more than 4 argument accepted\n");
    exit(0);
}
//if one argument i.e only filename is passed after ./new_tail
else if(argc == 2)
{
    FILE * fpointer;
    char content[MAX_CHAR]; //for storing content
    fpointer = fopen(argv[1],"r"); //open file passed
    if(fpointer == NULL)//couldn't open file
    {
        fprintf(stderr, "Cannot open file\n");
        exit(0);
    }
    int totalLine = countLine(fpointer, content, MAX_CHAR);
    int startLine = totalLine - 5;
    printSpecificLine(fpointer, content, MAX_CHAR, startLine);
    fclose(fpointer); //close file
}
else if(argc == 4)
{
    //allow both ordering of [-n | N] and [file.txt]
    if(strcmp(argv[1],"-n")==0)
    {
    FILE * fpointer;
    char content[MAX_CHAR]; //for storing content
    fpointer = fopen(argv[3],"r"); //open file passed
    if(fpointer == NULL)//couldn't open file
    {
    fprintf(stderr, "Cannot open file\n");
    exit(0);
    }
    int totalLine = countLine(fpointer, content, MAX_CHAR);
    int startLine = totalLine - atoi(argv[2]);
    printSpecificLine(fpointer, content, MAX_CHAR, startLine);
    fclose(fpointer); //close file
    }
    else
    {
    FILE * fpointer;
    char content[MAX_CHAR]; //for storing content
    fpointer = fopen(argv[1],"r"); //open file passed
    if(fpointer == NULL)//couldn't open file
    {
        fprintf(stderr, "Cannot open file\n");
        exit(0);
    }
    int totalLine = countLine(fpointer, content, MAX_CHAR);
    int startLine = totalLine - atoi(argv[3]);
    printSpecificLine(fpointer, content, MAX_CHAR, startLine);
    fclose(fpointer); //close file
    }
}
else if(argc == 3) //no textfile passed
{
     char content[MAX_CHAR]; //for storing content
     int lineCount = 0;
     int i = 0;//char counter
     int j = 0;//line counter
     char ch;
     while((scanf ("%c", &ch))!=EOF)
     {
      content[i]=ch;
      i++;
      if(ch == '\n')
      {
        lineCount++;
      }
     }
     int totalChar = i;
     int startLine = lineCount- atoi(argv[2]);
     i= 0;
     while(i < totalChar)
     {
        if(content[i]=='\n')
        {
            j++;
        }
        if(i==startLine)
        {
            while(i < totalChar)
            {
                printf("%c",content[i]);
                i++;
            }
            i=startLine+1;//exit while loop next time
        }
        i++;
    }
}
return 0;
}

