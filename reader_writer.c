#include <pthread.h> 	//Used for using pthreads
#include <semaphore.h> 	//Used for semaphores
#include <stdio.h> 
#include<unistd.h>	//for sleep function

sem_t mutex,writeblock;	//Declaring varibales of semaphore type
int data = 0,rcount = 0;//Initializing variables for data and readers count 

void *reader(void *arg)	//Fuction for reader thread
{
int c=0;
while(c<3){		//This code will cosider only 3 readers
  c++;
  int f;
  f = ((int)arg);
  sem_wait(&mutex);	//Acquiring lock
  rcount = rcount + 1;	//Increasing readers count
  if(rcount==1)		//If there is only reader,then block the writers to 				 modify that object
   sem_wait(&writeblock);
  sem_post(&mutex);	//Releasing lock
  printf("Data read by the reader %d is %d\n",f,data);
  sleep(1);
  sem_wait(&mutex);	//Acquiring lock
  rcount = rcount - 1;
  if(rcount==0)		//If no readers are there then allow the writer to 				modify the object
   sem_post(&writeblock);
  sem_post(&mutex);	//Releasing lock
}
}
void *writer(void *arg)
{
int c=0;
while(c<3){		//Code considers 3 writers only
  c++;
  int f;
  f = ((int) arg);
  sem_wait(&writeblock); //Acquiring lock 
  data++;		 //Critical section
  printf("Data writen by the writer %d is %d\n",f,data);
  sleep(1);
  sem_post(&writeblock); //Releasing lock
}
}

int main()
{
  int i,b; 
  pthread_t rtid[5],wtid[5];	//Creating threads for writers and readers
  sem_init(&mutex,0,1);		//Initializing semaphores
  sem_init(&writeblock,0,1);	//Initializing semaphores
  printf("The process will now begin:\n");
  for(i=0;i<=3;i++)
  {
    pthread_create(&wtid[i],NULL,writer,(void *)i);//Creating writers threads
    pthread_create(&rtid[i],NULL,reader,(void *)i);//Creating readers threads
  }
  for(i=0;i<=3;i++)
  {
    pthread_join(wtid[i],NULL);	//Joining threads
    pthread_join(rtid[i],NULL); //Joining threads
  }
  printf("\nHence it shows that readers writers problem can be solved by usnig this approach \n");
  printf("\n");
  return 0;
}
