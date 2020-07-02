#include<queue>//单端队列，只能对头出、队尾进
#include<vector>
#include"myheadfile.h"
#include"thread_Lock.h"
#include"class_ThreadPool.h"


ThreadPool::ThreadPool() :done(false), IsEmpty(true), IsFull(false) {
}//构造函数初始化

void ThreadPool::setSize(int num)//设置初始线程数
{
	this->initnum = num;
}

void ThreadPool::addTask(const Task&f)
{
	if (!done)
	{
		//保护共享资源
		unique_lock<mutex> lock(_mutex);

		while (IsFull)
		{
			cond.wait(lock);
		}
		task_queue.push(f);//任务队列添加任务
		if (task_queue.size() == initnum)
		{
			IsFull = true;
		}
		cout << "Add a Task" << endl;
			IsEmpty = false;
		cond.notify_one();
		lock.unlock();
	}
}

void ThreadPool::finish()
{
	for (size_t i = 0; i < threads_vector.size(); i++)
	{
		//threads_vector[i].join();//？？？
		cout << "我是第" << i << "个线程" << endl;
		threads_vector[i].detach();
	}
}

void ThreadPool::runTask() 
{
	//不断遍历队列,判断要是有任务的话,就执行
	while (!done) {
		unique_lock<mutex>lock(_mutex);
		//队列为空的话,就等待任务
		while (IsEmpty) {
			cond.wait(lock);
		}
		Task ta;
		//转移控制快,将左值引用转换为右值引用
		ta = move(task_queue.front());
		task_queue.pop();
		if (task_queue.empty()) {
			IsEmpty = true;
		}

		IsFull = false;
		ta();
		cond.notify_one();
	}
}

void ThreadPool::start(int num) 
{
	setSize(num);
	for (int i = 0; i < num; i++) 
	{
		threads_vector.push_back(thread(&ThreadPool::runTask, this));//将线程存入线程数组当中
	}                          //thread(具体函数地址，函数形参)
}

ThreadPool::~ThreadPool(){}
