#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main() {
     int  value = 100;

      printf("Before fork:\n");
      printf("Process ID:%d\n", getpid());
      printf("Value:%d\n", value);
      printf("Address of value:%p\n\n", (void *)&value);

      pid_t pid = fork();

      if(pid < 0) {
           perror("fork failed");
             return 1;
       }

       if(pid == 0) {
         // child process
         printf("CHILD PROCESS\n");
         printf("Process ID:%d\n", getpid());
         printf("Parent Process ID:%d\n", getppid());

         value = 200;


         printf("Child changed value to:%d\n", value);
         printf("Child address of value:%p\n\n", (void *)&value);
       }
       else {
             //Parent  process
             printf("PARENT PROCESS\n");
             printf("Process ID:%d\n", getpid());


             printf("Parent value: %d\n", value);
            printf("Parent address of value: %p\n", (void *)&value);
        }

    return 0;
 }

