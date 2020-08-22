#ifndef THREAD_LOCK_H
#define THREAD_LOCK_H
#pragma once;
#include<thread>
#include<pthread.h>
#include<mutex>//互斥锁，多线程访问统一资源时，防止资源被同时访问出错
#include"myheadfile.h"
#define  kItemRepositorySize 5
//#define  kItemToProduce 100
using namespace std;

 //const int kItemRepositorySize = 3;//队列大小
 //const int kItemToProduce = 10;//待生产的数量
//typedef是允许结构体使用别名，如果不加的话，结构体不能有别名，会有重定义的错误。
typedef struct ItemRepository//项目存储库
{
	int item_buffer[kItemRepositorySize];//缓冲区,缓冲区是生产者和消费者数据交互的渠道。										 //生产者生产的数据存入此数组中，然后消费者从此数组中取出数据。
	size_t read_position;//消费者者读取产品位置
	size_t write_position;//生产者写入产品位置
	mutex mutexBuffer;//缓冲区互斥锁，避免多线程同时操作缓冲区
	condition_variable repo_not_full;//条件变量，只是产品缓冲区不满
	condition_variable repo_not_empty;//指示产品缓冲区不为空
}gItemRepository;

void ProduceItem(ItemRepository* ir, int item);//生产者生产
int ConsumeItem(ItemRepository* ir);//消费者消费
void ProducerTask(ItemRepository* ir);//生产者任务
void ConsumerTask(ItemRepository* ir);//消费者任务
ItemRepository* InitItemRepository(ItemRepository* ir);//项目初始化
#endif


