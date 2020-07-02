#include<queue>//���˶��У�ֻ�ܶ�ͷ������β��
#include<vector>
#include"myheadfile.h"
#include"thread_Lock.h"
#include"class_ThreadPool.h"


ThreadPool::ThreadPool() :done(false), IsEmpty(true), IsFull(false) {
}//���캯����ʼ��

void ThreadPool::setSize(int num)//���ó�ʼ�߳���
{
	this->initnum = num;
}

void ThreadPool::addTask(const Task&f)
{
	if (!done)
	{
		//����������Դ
		unique_lock<mutex> lock(_mutex);

		while (IsFull)
		{
			cond.wait(lock);
		}
		task_queue.push(f);//��������������
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
		//threads_vector[i].join();//������
		cout << "���ǵ�" << i << "���߳�" << endl;
		threads_vector[i].detach();
	}
}

void ThreadPool::runTask() 
{
	//���ϱ�������,�ж�Ҫ��������Ļ�,��ִ��
	while (!done) {
		unique_lock<mutex>lock(_mutex);
		//����Ϊ�յĻ�,�͵ȴ�����
		while (IsEmpty) {
			cond.wait(lock);
		}
		Task ta;
		//ת�ƿ��ƿ�,����ֵ����ת��Ϊ��ֵ����
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
		threads_vector.push_back(thread(&ThreadPool::runTask, this));//���̴߳����߳����鵱��
	}                          //thread(���庯����ַ�������β�)
}

ThreadPool::~ThreadPool(){}
