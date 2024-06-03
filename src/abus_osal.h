#ifndef ABUS_OSAL_H
#define ABUS_OSAL_H
#ifdef __cplusplus
extern "C"{
#endif
#include <stdint.h>
#define POSIX 1
#if POSIX
#include <pthread.h>
#include <stdio.h>//perror
#include <unistd.h>//sleep
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#endif



typedef struct{
    #if POSIX
    sem_t sem;

    #elif CMSIS_RTOS
    #endif
}abus_sem_t;

typedef struct{
    #if POSIX
    pthread_t pthread_id;

    #elif CMSIS_RTOS
    #endif
}abus_thread_t;

int abus_sem_init(abus_sem_t *sem, unsigned int value);
int abus_sem_close(abus_sem_t *sem);
int abus_sem_wait(abus_sem_t *sem,uint32_t time);
int abus_sem_post(abus_sem_t *sem);


int abus_thread_create(abus_thread_t*thread,void *(*__start_routine) (void *),void*arg);
int abus_thread_cancel(abus_thread_t* thread);

void abus_os_delay(uint32_t time);

int test(int argc, char *argv[]);


#ifdef __cplusplus
}
#endif
#endif
