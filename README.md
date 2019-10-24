# My Own linux Commands
# Implemented by Lhakpa Sherpa

This Program implements some popular linux programs(listed) with some modification.
1. new_cat 
   ./new_cat [file.txt] 
   - When the file.txt argument is passed, the content is printed
   - if there is no second argument, user input is printed back until the
     the user hits CTRL+D
   - No flags are implemented
2. new_echo
   ./new_echo [arg] [arg] ... [arg] 
   - When [arg] is passed, all of it is printed      
   - if there is no second argument, user input a newline is printed and the 
     program ends
   - No flags are implemented 
3. new_tail
   ./new_tail [-n N] [file.txt]
   - if file.txt is specified, last N lines from file is printed (last 5 lines 
     is printed as deafault if [-n N] is not specified)
   - if no text file is specified user input is read through stdin until user
     hits Ctrl+D and last N lines is printed
   - no other flags implemented
4. new_wc
   ./new_wc [-l|c] [file.txt]
   - if textfile is specified word count of file.txt is printed
   - if no textfile is speciified word count of user input read from stdin until
     user hits Ctrl+D is printed
   - -l flag prints number of lines and number of words 
   - -c flag prints number of characters and number of words 
   - implementation only supports one flag at a time
   - no other flags implemented 

Additional Makefile is implemented to make each program, make all and make clean(to 
remove executables)
