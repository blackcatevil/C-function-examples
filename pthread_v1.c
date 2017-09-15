#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>		//usleep()
#include <pthread.h>	//pthread_create()

#define BAR "||||||||||||||||||||"
#define BAR_WIDTH 20

void* pthread_test(void *percentage)
{
	unsigned int lbar, rbar;
    unsigned int pre_percentage = *((unsigned int*)percentage);

	while(*((unsigned int*)percentage)<=100){
        if(pre_percentage != *((unsigned int*)percentage)){
            lbar=*((unsigned int*)percentage)*BAR_WIDTH/100;
            rbar=BAR_WIDTH-lbar;
            printf("\r[%.*s%*s] %d%% Completed.", lbar, BAR, rbar, "", *((unsigned int*)percentage));
            fflush(stdout);
            pre_percentage = *((unsigned int*)percentage);
        }
        if(pre_percentage == 100)
            break;
	}
	printf("\n");
}
int main()
{
	unsigned int percentage=0, arg=0;
	pthread_t id;
	int ret;

	ret = pthread_create(&id, NULL, pthread_test, &arg);
	if(ret!=0)
		printf("pthread creation failed\n");

	while(arg<100){
		++arg;
		usleep(100000);
	}

	pthread_join(id, NULL);

	return 0;
}
