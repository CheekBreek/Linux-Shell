 #ifndef MODEL_H
#define MODEL_H

//then a struct model needs to be declared inside of main.
//Then make an array of these once we have to do pipe.

/*EXAMPLE CALL: /usr/bin/man -k security &
               File_directory    args    run in background

 */
struct Command
{
    char *file_directory;  //The full file name.
    char **args;     //This is the arguments for the program. 30 allowed
    int num_args;     //required for later parsing. DOES NOT INCLUDE & or | or others.
    int bg;         //1 for true, 0 for false
};


struct Bg
{
    int fill;   //For the fg command (shows the most recent job)
    int pids[10]; //The process id's of the children
    int default_pgid;
    char* process_name;
};




#endif
