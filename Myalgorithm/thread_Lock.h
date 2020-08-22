#ifndef THREAD_LOCK_H
#define THREAD_LOCK_H
#pragma once;
#include<thread>
#include<pthread.h>
#include<mutex>//�����������̷߳���ͳһ��Դʱ����ֹ��Դ��ͬʱ���ʳ���
#include"myheadfile.h"
#define  kItemRepositorySize 5
//#define  kItemToProduce 100
using namespace std;

 //const int kItemRepositorySize = 3;//���д�С
 //const int kItemToProduce = 10;//������������
//typedef������ṹ��ʹ�ñ�����������ӵĻ����ṹ�岻���б����������ض���Ĵ���
typedef struct ItemRepository//��Ŀ�洢��
{
	int item_buffer[kItemRepositorySize];//������,�������������ߺ����������ݽ�����������										 //���������������ݴ���������У�Ȼ�������ߴӴ�������ȡ�����ݡ�
	size_t read_position;//�������߶�ȡ��Ʒλ��
	size_t write_position;//������д���Ʒλ��
	mutex mutexBuffer;//��������������������߳�ͬʱ����������
	condition_variable repo_not_full;//����������ֻ�ǲ�Ʒ����������
	condition_variable repo_not_empty;//ָʾ��Ʒ��������Ϊ��
}gItemRepository;

void ProduceItem(ItemRepository* ir, int item);//����������
int ConsumeItem(ItemRepository* ir);//����������
void ProducerTask(ItemRepository* ir);//����������
void ConsumerTask(ItemRepository* ir);//����������
ItemRepository* InitItemRepository(ItemRepository* ir);//��Ŀ��ʼ��
#endif


