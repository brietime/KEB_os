#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>

sem_t semaphore;
int num = 2;

void *threadF1(void *arg)
{
	int i;
	if(num != 0)
	{		
		sem_wait(&semaphore);
                num--;
		printf("thread 1 starts using.\n");

		//
		for(i=0; i < 1000000; i++){}

		printf("thread 1 finished using\n");
		num++;
		sem_post(&semaphore);
	}
	else if(num == 0)
	{
		printf("Full of threads! thread 1 is waiting!\n");

		while(num ==0){}
		sem_wait(&semaphore);
                num--;

		printf("thread 1 starts and finised using.\n");
		num++;
		sem_post(&semaphore);
	}
	return NULL;
}

void *threadF2(void *arg)
{
        int i;
        if(num != 0)
        { 
                sem_wait(&semaphore);
                num--;

                printf("thread 2 starts using.\n");

                //
                for(i=0; i < 1000000; i++){}

                printf("thread 2 finished using\n");
                num++;
                sem_post(&semaphore);
        }
        else if(num == 0)
        {
                printf("Full of threads! thread 2 is waiting!\n");

                while(num ==0){}
                sem_wait(&semaphore);
                num--;

                printf("thread 2 starts and finised using.\n");
                num++;
                sem_post(&semaphore);
        }
        return NULL;
}


void *threadF3(void *arg)
{
        int i;
        if(num != 0)
        {
                sem_wait(&semaphore);
                num--;

                printf("thread 3 starts using.\n");

                //
                for(i=0; i < 1000000; i++){}

                printf("thread 3 finished using\n");
                num++;
                sem_post(&semaphore);
        }
        else if(num == 0)
        {
                printf("Full of threads! thread 3 is waiting!\n");

                while(num ==0){}
                
                sem_wait(&semaphore);
                num--;

                printf("thread 3 starts and finised using.\n");
                num++;
                sem_post(&semaphore);
        }
        return NULL;
}



int main()
{
	pthread_t thread1, thread2, thread3;

	sem_init(&semaphore, 0, num); //make semaphore instance

	printf("Semaphore test Start!\n");

	pthread_create(&thread1, NULL, threadF1, NULL);
        pthread_create(&thread2, NULL, threadF2, NULL);
        pthread_create(&thread3, NULL, threadF3, NULL);

	pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);

	printf("every thread finished using.\n");

	sem_destroy(&semaphore);//delete semaphore instance

	return 0;
}
