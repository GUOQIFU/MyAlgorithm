#include"myheadfile.h"
#include"thread_Lock.h"

pthread_mutex_t _mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t event1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t event2 = PTHREAD_COND_INITIALIZER;//互斥锁、条件变量静态初始化

//void *pthreadA(void *)
//{
//	pthread_mutex_lock(&_mutex);
//
//
//	pthread_cond_signal(&event1);
//	pthread_cond_wait(&event2, &_mutex);
//	pthread_mutex_unlock(&_mutex);
//
//}
//void *pthreadB(void *)
//{
//	pthread_mutex_lock(&_mutex);
//
//
//	pthread_cond_signal(&event2);
//	pthread_cond_wait(&event1, &_mutex);
//	pthread_mutex_unlock(&_mutex);
//}

//int main1()
//{
//	int N;
//	pthread_t A;
//	pthread_t B;
//	pthread_create(&A,NULL,pthreadA,(void *)N);
//	pthread_create(&B,NULL,pthreadB,(void *)N);
//	pthread_join(A, NULL);//线程阻塞，等待另外线程结束
//	pthread_join(B, NULL);
//}