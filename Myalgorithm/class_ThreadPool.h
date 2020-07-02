#pragma once
#ifndef CLASS_THREADPOOL_H
#define CLASS_THREADPOOL_H
#include"myheadfile.h"
#include<mutex>
//线程池
class ThreadPool
{
public:
	typedef function<void()>Task;//自定义void()的函数类型,？？？？？
	ThreadPool();
	~ThreadPool();

public:
	rsize_t initnum;
	vector<thread> threads_vector;//线程数组
	queue<Task> task_queue;//任务队列
	mutex _mutex;//互斥锁
	condition_variable  cond;//条件变量
	bool done;//线程池工作结束标志
	bool IsEmpty;//线程池是否为空
	bool IsFull;//线程池是否为满

public:
	void addTask(const Task&f);//添加任务线程
	void start(int num);//设置线程数量
	void setSize(int num);//设置线程数组的size
	void runTask();
	void finish();
};

#endif // !CLASS_THREADPOOL_H


