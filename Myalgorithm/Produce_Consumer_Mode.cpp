
#include<iostream>
#include<stdio.h>
#include<mutex>//�����������̷߳���ͳһ��Դʱ����ֹ��Դ��ͬʱ���ʳ���
#include"myheadfile.h"
#include"thread_Lock.h"

mutex mutexCout;// ȫ�ֶ��߳��������������߳�ͬʱ�����������

void ProduceItem(ItemRepository* ir, int item)//����������
{
	unique_lock<mutex> lock(ir->mutexBuffer);//��������������ʱֻ�������߲����������������ߵȴ�
	while(ir->write_position == kItemRepositorySize - 1)//?????�жϻ������Ƿ�����
	{
		ir->write_position = 0;//��־λ ��0
		{   //���������˵������������������������
			lock_guard<mutex> lock(mutexCout);//�������
			cout << "��������������ȴ�����������" << endl;
		}
		(ir->repo_not_empty).notify_all();//֪ͨ�����߻�������Ϊ��
		(ir->repo_not_full).wait(lock);//˵�������������������������������ʼ�ȴ��������̸߳���֪ͨ��Ϣ��	
		lock.unlock();//����
	}
	(ir->item_buffer)[ir->write_position] = item;//��������������������д������
	ir->write_position++;//��־λ++
	
}

int ConsumeItem(ItemRepository* ir)//����������
{
	unique_lock<mutex> lock(ir->mutexBuffer);
	while(ir->read_position == kItemRepositorySize - 1)//�жϻ������Ƿ�Ϊ��
	{
		ir->read_position = 0;
		{
			lock_guard<mutex> lock(mutexCout);
			cout << "�������գ��ȴ����������ɲ�Ʒ" << endl;
		}
		(ir->repo_not_full).notify_all();//֪ͨ�����߲�Ʒ�ⲻΪ��
		(ir->repo_not_empty).wait(lock);//���ȴ�����������Ϊ����һ�¼��ķ�����
		lock.unlock();
	}
	int data = ir->item_buffer[ir->read_position];
	(ir->read_position)++;
	return data;
}

void ProducerTask(ItemRepository* ir)//����������
{
	int i = 1;
	while (1)
	{
		//this_thread::sleep_for(chrono::seconds(1));
		ProduceItem(ir, i);
	    {
		  lock_guard<mutex> lock(mutexCout);
		  cout << "����������" << i << "����Ʒ" << endl;
		}
		i++;      
	}	
}

void ConsumerTask(ItemRepository* ir)//����������
{
	static int cnt = 0;
	while (1)
	{
		this_thread::sleep_for(chrono::seconds(1));//
		int item = ConsumeItem(ir);
		{
			lock_guard<mutex> lock(mutexCout);
			cout << "�������������ѵ�" << item << "����Ʒ" << endl;
		}
		//if (++cnt == kItemRepositorySize) break;
	}
}

ItemRepository* InitItemRepository(ItemRepository* ir)//��Ŀ��ʼ��
{
	ir->read_position = 0;
	ir->write_position = 0;
	return ir;
}