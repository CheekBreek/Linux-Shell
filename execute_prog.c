// TEST:  /usr/bin/man -k security

#include "execute_prog.h"



void interpretCommand(struct Command *command) {

//    printf("here2\n");
    open_process(command->file_directory,command->args,command->num_args,command->bg);

    
    return;
}


/*Handles the reformatting of args so that the file name leads, and is terminated with a null
char** format_args(char file_name[], char* args[], int num_arguments){



    return arg_array;

}




/*Formats the arg array with the file name and args, and adds a null*/
int open_process(char file_name[], char* args[], int num_arguments, int bg){



    int max_size = num_arguments+2;  /*arguments + file name + null*/
    printf("max size: %d\n",max_size);
    char*arg_array[max_size]; /*The new array*/
    int counter = 0;

    char * const newenvp[] = { NULL };

    
    int pid;
    int i = 0;
    int status;

    arg_array[counter] = file_name;//full_file;           /*THIS PART ONLY ADDS NULL AND THE FILE NAME*/
    arg_array[max_size-1] = NULL;
    counter++;

	    printf("Here\n");
    for(; counter <num_arguments+1; counter++) {

	arg_array[counter] = args[i];   /*fill the array*/
	i++;
    }

    
     if(bg==1){
	background_process(file_name, arg_array);
        }
     else{
	


    pid = fork();
    
    if(pid==0){
	//child

	printf("bg: %d\n",bg);
	if (bg == 1) {
	    setpgid(0,0); //give child a new group process id. Cannot print to the terminal
	    printf("THIS SHOULD NOT BE VISABLE\n");
    }
	
	if (!execve(file_name, arg_array, newenvp))
	{
	    printf("execve failed\n");
	    _exit(1);
	}	
    }
    
    else{
	//parent
	if (bg != 1) {
 	waitpid(pid,&status,0);     //Waits for a child to change its state/die
	}
    }    
    }
    return 0;
}

 
/*These inputs must be formatted correctly


IF background process, its gonna set the child into a different group with 
setpgid(0,0) and
tcsetpgrp()

https://stackoverflow.com/questions/8319484/regarding-background-processes-using-fork-and-child-processes-in-my-dummy-shel

FROM man 2 setpgid
int setpgid(pid_t pid, pid_t pgid);
       pid_t getpgid(pid_t pid);

pgid means process group id. pid is process id.

setpid takes in a process id, and sets that process id's process group to whatever you put.
getpid takes in a process id, and tells you what process group it was in.

if you use a '0' for the pid, it will refer to the current running process. 
If you use a '0' for the gpid. it will automatically put its group to be its process id.


TEST with getpgrp - returns the current group the process is in.

Return: 0 if good -1 if bad.  


terminal control: sets/gets the process group currently running

pid_t tcgetpgrp(int fd);
int tcsetpgrp(int fd, pid_t pgrp);


STOP background from printing to screen!!!: 
tcsetattr()

*/
int background_process(char file_name[], char* args[]) {
/*
    struct termios term;

    //Might be |=
    term.c_lflag &= TOSTOP;    //Logical bit flipped - its a background process now!
*/  
    int status;
    int pid;
    char * const newenvp[] = { NULL };

    //1: the fd of writing to the terminal.
    //
//    tcsetattr(1,TCSANOW, &term);

    

    
    pid = fork();

    if(pid==0){
//Child

/*	pid info of child before swap
    printf("\nCHILD process id: %d \n",getpid());
    printf("CHILD group: %d \n",getpgrp());
*/

    printf("Current controller of terminal: %d \n",tcgetpgrp(1));
    printf("child group: %d \n",getpgrp());
    
    setpgid(0,0); //give child a new group process id.

    printf("CHILD group: %d \n",getpgrp());
//     pid after swap    
  
    printf("CHILD PID: %d \n",getpid());

    //1 is the fd for writing to terminal
    printf("Current controller of terminal(after swap): %d \n",tcgetpgrp(1));

    
    //Yup, different group.
	
	//execute command
	if (!execve(file_name, args, newenvp))
	{
	    printf("execve failed\n"); //Grandson running here
	    _exit(1);
	}
    }
    //PARENT

//    printf("\n\nParent process id: %d \n",getpid());
    printf("Parent group: %d \n",getpgrp());
    printf("Current controller of terminal(at parent): %d \n",tcgetpgrp(1));
    


    
    
    return 0;
}



void fg(int job_num, struct Bg *bg){

    return;
}
 
/*overloaded version, places the highest job into the forground*/
void default_fg(struct Bg *bg){
    
    return;
}

/*prints all the jobs that are running*/
void print_jobs(struct Bg *bg){
    return;
}




/* Double child version
int background_process(char file_name[], char* args[]) {

    printf("In the background!\n");
    int status;
    int pid;
    int child_pid;
    char * const newenvp[] = { NULL };

    pid = fork();

    if(pid==0){
//Child

	child_pid = fork(); //Now a child of the child, parent can do whatever


	if(child_pid==0){
	    //Grandson running
	 if (!execve(file_name, args, newenvp))
	 {
        printf("execve failed\n"); //Grandson running here
        _exit(1);
	 }

	 
	}
	waitpid(child_pid,&status,0); //Child waits for grandson
//Now it needs to wait for parent to call it
	
	
	_exit(0);                  
    }
    
    
    
    
    return 0;
}
*/



/* EXTRA CODE FOR LATER FEATURES: 



	
    /*can use "which" to find the location of the file*/
//    char root[] = "/home/kkoiv395/labs/procintro/hard_core/printTst";

/*CAN IMPLEMENT THIS LATER (ROOT DIRECTR 
	
      char root[] = "/usr/bin/man";
      char full_file[80];
*/

/*
    strcpy(full_file,root);
      strcat(full_file,file_name);
*/   

