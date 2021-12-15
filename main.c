#include <stdio.h>
#include "execute_prog.h"
#include "model.h"
#include "readInput.h"
#include <termios.h>   //For the termios structure declaration


/*ADD ARGUMENTS TO MAIN FOR LOGIN */
int main()
{
/*Reuse the structure*/
    struct Command command;
    int background[10]; //The background processes array.
    
    
    char inputString[MAX];

    struct termios term; //Stop background processes from writing to screen
    struct Bg bg;

    
    tcgetattr(1,&term);  //Copy default terminal attributes
    term.c_lflag |= TOSTOP;  //background processes cannot write out    
//    tcsetattr(1,TCSANOW,&term); //Save new attributes
    //^^^ Could be a 1


    bg.default_pgid = tcgetpgrp(1);  //This will let us change a process back to the main group, which will cause it to print

    printf("default terminal controller: %d\n",bg.default_pgid);
    

    
    /*What the data should look like from the structure */
//    char* args[] = { "-k", "security" };
    //   char file_name[] = "/usr/bin/man";
    // open_process(file_name, args, 2);
    
    //Exit, fg fg 1 
    while(1)
    {
        printShell();
        if(readInput(inputString,&command)) /*pass by references the input string*/
        {
//	    printf("here3\n");
	    interpretCommand(&command);

	    
            continue;   
        }
    }

    term.c_lflag &= ~TOSTOP;     
    tcsetattr(0,TCSANOW,&term); //Undo terminal change

    return 0;
}
