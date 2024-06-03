#include "abus_osal.h"

int global_number = 10;

typedef struct
{
	int id;
} STU;

int abus_sem_init(abus_sem_t *sem, unsigned int value)
{
#if POSIX
	sem_init(&sem->sem, 1, value);
#endif
	return 0;
}

int abus_sem_close(abus_sem_t *sem)
{
#if POSIX
	return sem_close(&sem->sem);
#else
	return 0;
#endif
}

int abus_thread_create(abus_thread_t *thread, void *(*__start_routine)(void *), void *arg)
{
#if POSIX

	printf("thread_create\n");
	return pthread_create(&thread->pthread_id, NULL, __start_routine, arg); // 2指定线程属性3函数指针4给线程传递的参数
#else
	return 0;
#endif
}

int abus_thread_cancel(abus_thread_t *thread)
{
#if POSIX

	return pthread_cancel(thread->pthread_id);
#else
	return 0;
#endif
}

int abus_sem_wait(abus_sem_t *sem, uint32_t time)
{
#if POSIX

	return sem_wait(&sem->sem);
#else
	return 0;
#endif
}
int abus_sem_post(abus_sem_t *sem)
{
#if POSIX

	return sem_post(&sem->sem);
#else
	return 0;
#endif
}

void *thread_fun(void *data) // data获得pthread_create的第四个参数传的数据
{
	STU *stu_info = (STU *)data;
	while (1)
	{
		global_number++;
		abus_os_delay(1);
	}
}

void abus_os_delay(uint32_t time)
{
#if POSIX

	sleep(time);
#else
	return ;
#endif
}
#if POSIX

int test(int argc, char *argv[])
{
	abus_thread_t pthread_id;
	STU stu_info;
	stu_info.id = 1001;

	if (abus_thread_create(&pthread_id, thread_fun, &stu_info) < 0) // 2指定线程属性3函数指针4给线程传递的参数
	{
		perror("pthread create err:");
	}
	// 线程合并，类似于wait
	// pthread_join(pthread_id,NULL);
	for (int i = 0; i < 5; i++)
	{
		global_number++;
		printf("main  runnning...\n");
		sleep(1);
	}
	return 0;
}
#endif