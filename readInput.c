#include "readInput.h"

void printShell()
{
    printf("mysh$ ");
}

int splitString(char* strIn, char** strOut) 
{
    //printf("%s", strIn);
    //printf("%s", strOut[0]);

    int j = 0;
    int ctr = 0;
    
    //printf("%lu", strlen(strIn));

    for(int i = 0; i < (strlen(strIn)-1); i++) /*-1 since '\n' is last character*/
    {
        if(strIn[i] == ' ' || strIn[i] == '\0')
        {
            strOut[ctr][j] = '\0';
            ctr++;
            j = 0;
        }
        else
        {
            strOut[ctr][j] = strIn[i];

            j++;
        }
    }

    int nCtr = 0;

    while(nCtr <= ctr)
    {
//        printf("%s", strOut[nCtr]); This is echoing it

        nCtr++;
    }

    nCtr = nCtr - 1;
    
    return nCtr;
}


int readInput(char* str, struct Command* command)
{
    fgets(str, MAX, stdin);
    //str[strcspn(str, "\n")] = 0;
    //printf("%lu", strlen(str));

    char** output;
    int args = 0;
    int counter = 0;

    
    output = malloc(MAX);  

    for(int i = 0; i < 10; i++)
    {
        output[i] = malloc(MAX);

    }


    
    args = splitString(str, output);
//    printf("In Read Input: %s\n", output[0]);
    //    printf("%s\n", output[1]);
    // printf("%s\n",output[2]);
    

    command-> file_directory = output[0];
    command -> bg = 1;  //TEST: runs it as a background process
    
//    printf("args: %d\n",args);
//    printf("HERE\n");
    
    
    command-> args = output; //this FIXED IT!!!
    

    //  printf("made it!!!\n");
 


    
 for(; counter < args; counter++){ //SEG FAULTING HERE

     //   printf("output:: %s \n",output[counter+1]);
	command-> args[counter] = output[counter+1]; //args gets filled at 0, but pulled at 1. EX 2 args -> 1,2 are filled
	}
// printf("NOT HERE\n");
    
    
    command-> num_args = args;

    
    return args;
}
