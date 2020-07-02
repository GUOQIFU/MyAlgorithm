#pragma once
#ifndef CLASS_THREADPOOL_H
#define CLASS_THREADPOOL_H
#include"myheadfile.h"
#include<mutex>
//�̳߳�
class ThreadPool
{
public:
	typedef function<void()>Task;//�Զ���void()�ĺ�������,����������
	ThreadPool();
	~ThreadPool();

public:
	rsize_t initnum;
	vector<thread> threads_vector;//�߳�����
	queue<Task> task_queue;//�������
	mutex _mutex;//������
	condition_variable  cond;//��������
	bool done;//�̳߳ع���������־
	bool IsEmpty;//�̳߳��Ƿ�Ϊ��
	bool IsFull;//�̳߳��Ƿ�Ϊ��

public:
	void addTask(const Task&f);//��������߳�
	void start(int num);//�����߳�����
	void setSize(int num);//�����߳������size
	void runTask();
	void finish();
};

#endif // !CLASS_THREADPOOL_H


