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
//funtion to print specific lines if given the startingLine
void printSpecificLine(FILE * textfile, char * content, const int size, int startLine)
{
    int currentLine = 0;//counter
    while(currentLine!=startLine){
        fgets(content, size, textfile);//only print the last n lines
        currentLine++;
        printf("%d",currentLine);
    }
    while(!feof(textfile)){
    printf("here");
    fgets(content, size, textfile); //read one line as a string
    printf("%s",content);
    currentLine++;
    }
    return;
}
int main(int argc,char*argv[])
{
//if more than three argument was passed after ./new_tail
if(argc > 4)
{
    fprintf(stderr, "allowed syntax is: ./new_tail [-n N] [file.txt]\nargs inside[] are optional\nno more than 1 argument accepted\n");
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
    int currentLine = 1;
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
    int startLine = totalLine - atoi(argv[2]);
    int currentLine = 1;
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
    int currentLine = 1;
    printSpecificLine(fpointer, content, MAX_CHAR, startLine);
    fclose(fpointer); //close file
    }
}
else if(argc == 3) //no textfile passed
{
    string lines[MAX_CHAR]; //to store stdin inputs
    char content[MAX_CHAR];
    int i = 0;
    printf("type in text to cat\n hit Ctrl+D when you are done\n");
    while(fgets(content,MAX_CHAR, stdin))
    {
        lines[i]=content;
        i++;
        printf("%s",lines[i]); //print whatever was input
    }
    int totalLine = i;
    i =0;
    int startLine = totalLine - atoi(argv[2]);
    while(i<totalLine)
    {
        if(i==startLine){
        while(i<totalLine){
        printf("%s", lines[i]);
        i++;
        }
        break;
        }
        i++;  
    }
}
return 0;
}


