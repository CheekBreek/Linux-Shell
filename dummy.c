#include <stdio.h>
/*#include <unistd.h>
#include <sys/types.h>


/*you need the argc for some reason*/
int main(int argc, char* num[])  /*takes in an array of char pointers(arrays)*/
{

    
    printf("Here! %s \n", num[1]);




    
     return 0;

}

/*Parent runs, hits fork, Parent will continue to run until its 
time slice is done, then child wakes up!!!! */
