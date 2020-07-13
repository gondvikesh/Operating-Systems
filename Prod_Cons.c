//Program for Consumer Producer using pthreads
# include <stdio.h>
# include <pthread.h>	//For including threads
#include<stdlib.h>	//For using malloc() 
# define BufferSize 10

void *Producer();	//Function declaration for Producer
void *Consumer();	//Function declaration for Consumer

int BufferIndex=0;
char *BUFFER;		//Bounder buffer where the producer will produce

pthread_cond_t Buffer_Not_Full=PTHREAD_COND_INITIALIZER;
pthread_cond_t Buffer_Not_Empty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main()
{    
    pthread_t ptid,ctid;	//Declaring pthread variables for producer 					  and consumer

    BUFFER=(char *) malloc(sizeof(char) * BufferSize); //Allocationg 								 memory            
    
    printf("The producer will now start producing and after that the consumer will start consuming\n");	 
    pthread_create(&ptid,NULL,Producer,NULL); //Creating producer threads
    pthread_create(&ctid,NULL,Consumer,NULL); //Creating consumer 							threads	
    
    pthread_join(ptid,NULL);	//Joining threads	
    pthread_join(ctid,NULL);	//Joining threads
    printf("So it is clear now that this solves the consumer producer problem as the consumer can only start consuming as soon as the producer starts producing.\n")	        ;
    
    return 0;
}

void *Producer()
{    int count=3;	//This means that the producer will only produce 3 				  items at max	
    while(count>0)
    {
	count--;
        pthread_mutex_lock(&mVar);	//Acquiring lock
        if(BufferIndex==BufferSize)	//Checking if the buffer is full
        {                        	
            pthread_cond_wait(&Buffer_Not_Full,&mVar);//Wait until the buffer 								is not empty	
        }                        
        BUFFER[BufferIndex++]='@';
        printf("Produce : %d \n",BufferIndex);//Critical Section
        pthread_mutex_unlock(&mVar);	//Releasing lock
        pthread_cond_signal(&Buffer_Not_Empty); //Sending the signal for 							consumer that the buffer is 							not empty now       
    }    
    
}

void *Consumer()
{
      int count=3;	//This means that the consumer will only consume 3 				  items at max	
    while(count>0)
    {
	count--;
        pthread_mutex_lock(&mVar);	//Acquiring lock	
        if(BufferIndex==-1)		//Checking if the buffer is empty
        {            
            pthread_cond_wait(&Buffer_Not_Empty,&mVar);//Waiting for the 								producer to produce 
        }                
        printf("Consume : %d \n",BufferIndex--); //Critical Section       
        pthread_mutex_unlock(&mVar);        //Releasing lock
        pthread_cond_signal(&Buffer_Not_Full);                
    }    
}

