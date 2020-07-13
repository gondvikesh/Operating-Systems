#include <pthread.h> 	//Used for using pthreads
#include <semaphore.h> //Used for semaphores
#include <stdio.h> 
#include<unistd.h>
  
#define N 5 		//Defining numeric values for various operations
#define THINKING 2 
#define HUNGRY 1 
#define EATING 0 
#define LEFT (phnum + 4) % N 
#define RIGHT (phnum + 1) % N 
  
int state[N]; 		//Current states of the philosphers i.e, 				 Thinking ,Hungry,Eating.
int phil[N] = { 0, 1, 2, 3, 4 }; //Philosphers array of consisting of 					  philosphers
  
sem_t mutex; 		//mutex lock in semaphores
sem_t S[N]; 		//array of type semaphore
  
void test(int phnum) 
{ 
    if (state[phnum] == HUNGRY	//To check whether the philoshers sitting
        && state[LEFT] != EATING //at right and left of the current phiospher
        && state[RIGHT] != EATING) {  //are eating or not
        state[phnum] = EATING; 
  
        sleep(2);
  
        printf("Philosopher %d takes fork %d and %d\n",
                      phnum + 1, LEFT + 1, phnum + 1);  //Enters its critcal 								section
  
        printf("Philosopher %d is Eating\n", phnum + 1); //Philospher Eating 
  	
	sem_post(&S[phnum]); //Current phil is asked to move to next state.
    } 
} 
  
void take_fork(int phnum)    //Pick up the fork
{ 
  
    sem_wait(&mutex); 		//Acquring lock
  
    state[phnum] = HUNGRY;  	//Updating the state of the philospher
  
    printf("Philosopher %d is Hungry\n", phnum + 1); 
  
    test(phnum); 	//Check if nearby phils are eating or not
  	
    sem_post(&mutex); 	//Releasing lock
  
    sem_wait(&S[phnum]); //If nearby phils are eating then the current phil 				  is asked to wait.
  
    sleep(1); 
} 
  

void put_fork(int phnum) //Put down fork 
{ 
  
    sem_wait(&mutex); 	//Acquring lock	
  
    state[phnum] = THINKING; //Updating the state of current philospher
  
    printf("Philosopher %d putting fork %d and %d down\n", 
           phnum + 1, LEFT + 1, phnum + 1); 
    printf("Philosopher %d is thinking\n", phnum + 1); //Critical Section
  
    test(LEFT); 	//If the other neighbour of left philospher is not 				eating then allowing left phil to eat
    test(RIGHT); 	//If the other neighbour of right philospher is not 				eating then allowing right phil to eat
  
    sem_post(&mutex); 	//Releasing lock
} 
  
void* philospher(void* num) //Driving function which would initiate the 			    process
{ 
  int x=5;		//This code considers only 5 philosphers
  
    while (x--) { 
  
        int* i = num; 
  
        sleep(1); 
  
        take_fork(*i); 	//Calling take_fork() for philosphers
  
        sleep(0); 
  
        put_fork(*i); 	//Calling put_fork() for philosphers
    } 
} 
  
int main() 
{ 
  
    int i; 
    pthread_t thread_id[N]; 
  
    sem_init(&mutex, 0, 1); 	//Initializing the semaphores 
  
    for (i = 0; i < N; i++) 
  
        sem_init(&S[i], 0, 0); 
    
    printf("Now the processes will start executing i.e, the philosphers will start thinking and as soon as one of them gets hungry he will check whether he can eat or not\n "); 
    for (i = 0; i < N; i++) { 
  	
	pthread_create(&thread_id[i], NULL,philospher, &phil[i]); //Creating 					philosphers threads i.e, creating philosphers
  
        printf("Philosopher %d is thinking\n", i + 1); 
    } 
  
    for (i = 0; i < N; i++) 
  
        pthread_join(thread_id[i], NULL); //Joining threads
    printf("\nThe above order makes it clear that this code solves the dining philosphers problem as it neither lets any philospher to wait indefinitely nor does let two nearby philosphers eat at the same time\n");	
} 
