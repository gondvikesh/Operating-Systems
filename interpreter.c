#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <dirent.h>
#include<unistd.h>

int main(){
    char inputCommand[256];
    char argv[64][64];
    int cmdIndex = 0;
    char* tofree;
    int argc = 0;
    int bufIndex = 0;

    system("clear screen");
    printf("####################################################");
    printf("\n###### COMMAND INTERPRETER :: AOS ###### EXP 1 #####");
    printf("\n####################################################\n");
    printf("Start Command Interpreter Porgram : (Y/N) ::\t");
    gets(inputCommand);

    if(!strcmp(inputCommand,"Y")){
        while(strcmp(inputCommand,"exit")){
            printf("$> ");
            fflush(stdout);
            pid_t pid;

            pid = fork();
            if(pid == 0){
            gets(inputCommand);

            // OPTIONAL //
            //argv argv code
            for(cmdIndex = 0;cmdIndex < strlen(inputCommand); cmdIndex++){
                if(inputCommand[cmdIndex] == ' '){
                    argv[argc][bufIndex] = '\0';
                    argc++;
                    bufIndex = 0;
                }
                else{
                    argv[argc][bufIndex] = inputCommand[cmdIndex];
                    bufIndex++;
                }
            }
            argc++;


            if(!strcmp(argv[0],"wc"))
                    execl("/home/shanu/Documens/aoslab/wc","/home/shanu/Documents/aoslab/wc",argv[1]);
            else if(!strcmp(argv[0],"ls"))
                execl("/home/shanu/Documents/aoslab/ls","/home/shanu/Documents/aoslab/wc",argv[1]);
            else if(!strcmp(argv[0],"echo"))
                execl("/home/os/mc18109/echo","/home/os/mc18109/echo",argv[1]);
            else if(!strcmp(argv[0],"ps"))
                execl("/home/os/mc18109/ps","/home/os/mc18109/ps",argv[1]);
            else if(!strcmp(argv[0],"kill"))
                execl("/home/os/mc18109/kill","/home/os/mc18109/kill",argv[1]);
            else if(!strcmp(argv[0],"rm"))
                execl("/home/os/mc18109/rm","/home/os/mc18109/rm",argv[1]);
            else if(!strcmp(argv[0],"cat"))
                execl("/home/os/mc18109/cat","/home/os/mc18109/cat",argv[1]);
            else
                printf("Command Not Found.\n");
            }
            wait(pid);

        }
        }else{
            printf("You Stopped Starting of the Interpreter. Please Restart.\n\n");
        }

    return 0;
}

