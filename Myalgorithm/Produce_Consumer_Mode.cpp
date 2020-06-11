
#include<iostream>
#include<stdio.h>
#include<mutex>//互斥锁，多线程访问统一资源时，防止资源被同时访问出错
#include"myheadfile.h"
#include"thread_Lock.h"

mutex mutexCout;// 全局多线程输出锁，避免多线程同时访问输出窗口

void ProduceItem(ItemRepository* ir, int item)//生产者生产
{
	unique_lock<mutex> lock(ir->mutexBuffer);//缓冲区加锁，此时只能生产者操作缓冲区，消费者等待
	while(ir->write_position == kItemRepositorySize - 1)//?????判断缓冲区是否已满
	{
		ir->write_position = 0;//标志位 归0
		{   //这个大括号说明加锁的作用域就在这个区域
			lock_guard<mutex> lock(mutexCout);//输出加锁
			cout << "缓冲区已满，请等待消费者消费" << endl;
		}
		(ir->repo_not_empty).notify_all();//通知消费者缓冲区不为空
		(ir->repo_not_full).wait(lock);//说明缓冲区已满，生产者阻塞在这里，开始等待消费者线程给的通知消息。	
		lock.unlock();//解锁
	}
	(ir->item_buffer)[ir->write_position] = item;//当缓冲区不满，就向其写入数据
	ir->write_position++;//标志位++
	
}

int ConsumeItem(ItemRepository* ir)//消费者消费
{
	unique_lock<mutex> lock(ir->mutexBuffer);
	while(ir->read_position == kItemRepositorySize - 1)//判断缓冲区是否为空
	{
		ir->read_position = 0;
		{
			lock_guard<mutex> lock(mutexCout);
			cout << "缓冲区空，等待生产者生成产品" << endl;
		}
		(ir->repo_not_full).notify_all();//通知消费者产品库不为满
		(ir->repo_not_empty).wait(lock);//锁等待，缓冲区不为空这一事件的发生。
		lock.unlock();
	}
	int data = ir->item_buffer[ir->read_position];
	(ir->read_position)++;
	return data;
}

void ProducerTask(ItemRepository* ir)//生产者任务
{
	int i = 1;
	while (1)
	{
		//this_thread::sleep_for(chrono::seconds(1));
		ProduceItem(ir, i);
	    {
		  lock_guard<mutex> lock(mutexCout);
		  cout << "正在生产第" << i << "个产品" << endl;
		}
		i++;      
	}	
}

void ConsumerTask(ItemRepository* ir)//消费者任务
{
	static int cnt = 0;
	while (1)
	{
		this_thread::sleep_for(chrono::seconds(1));//
		int item = ConsumeItem(ir);
		{
			lock_guard<mutex> lock(mutexCout);
			cout << "消费者正在消费第" << item << "个产品" << endl;
		}
		//if (++cnt == kItemRepositorySize) break;
	}
}

ItemRepository* InitItemRepository(ItemRepository* ir)//项目初始化
{
	ir->read_position = 0;
	ir->write_position = 0;
	return ir;
}