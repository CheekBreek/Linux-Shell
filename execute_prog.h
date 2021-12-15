#ifndef execute_prog_H
#define execute_prog_H


#include <stdio.h>       //For printf's
#include <unistd.h>      //for the execve and fork
#include "model.h"       //for the structure
#include <sys/types.h>   //For waitpid
#include <sys/wait.h>

#include <termios.h> //For stopping bg processes from writing to screen (implements fg)


void interpretCommand(struct Command *command);
char** formatt_args(char file_name[], char* args[], int num_arguments); //Currently unused

int background_process(char file_name[], char* args[]);
int open_process(char file_name[], char* args[], int num_arguments, int bg);

void print_jobs(struct Bg *bg);
void default_fg(struct Bg *bg);
void fg(int job_num, struct Bg *bg);





#endif
