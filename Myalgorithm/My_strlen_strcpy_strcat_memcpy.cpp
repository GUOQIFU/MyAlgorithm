#include"myheadfile.h"
#include"SortOrSearch.h"
#include"class_ThreadPool.h"
#include"thread_Lock.h"
#include"My_String.h"

char* my_strcpy(char *deststr, const char *str)//char*������Ϊ�˷�������ĺ�������  ��ʽ����
{
	assert(str != NULL);
	assert(deststr != NULL);//�ж���������ĺϷ��ԣ��������Ϊ�٣�����ֹ����
	char *res = deststr;
	int length = strlen(str);
	for (size_t i = 0; i <= length; i++)
	{
		deststr[i] = str[i];
	}
	//while ((*deststr++ = *str++)!='\0')
	return res;
}

int my_strlen(const char *str)
{
	if (str == NULL)  return 0;
	int i = 0;
	while (str != '\0')
	{
		i++;
	}
	return i;
}

char *my_strcat(char *deststr, const char *str)//�ַ������Ӻ���,���ַ���str���ӵ��ַ���deststr����
{
	assert(deststr != NULL && str !=NULL);
	char *res = deststr;
	while (deststr)
	{
		*deststr++;
	}
	while (str)
	{
		*deststr++ = *str++;
	}
	*deststr = '\0';
	return res;
}

void *my_memcpy(void *deststr, const void *str,size_t count)//�Ӵ洢��str����n���ַ���deststr��ȥ��
{
	assert((deststr != NULL) && (str != NULL));
	void *res = deststr;
	while (count--)
	{
		*(char*)deststr = *(char*)str;
		deststr = (char*)deststr + 1; 
		str = (char*)str + 1;
	}
	return res;
}

char *mystrcat(char *deststr, const char *str)
{
	assert(deststr != NULL && str != NULL);
	char *res = deststr;
	while (deststr)
	{
		*deststr++;
	}
	while (str)
	{
		*deststr++ = *str;
	}
	*deststr = '\0';
	return res;
}

//char *mymecpy(char *deststr, const char *str, size_t count)
//{
//	assert(deststr != NULL && str != NULL && count > 0 );
//
//	if (strlen(deststr) < strlen(str))//���Ŀ���ַ��ڴ治��
//	{
//		delete []deststr;
//		deststr = new char[count + 1];
//	}
//
//	if (deststr < str && deststr + count > str)//�����ڴ��ص������
//	{
//		delete []deststr;
//		deststr = new char[count + 1];//����ص�����������һ���ڴ�
//	}
//
//	char *res = deststr;
//	while (count--)
//	{
//		*deststr++ = *str++;
//	}
//	*deststr = '\0';
//	return res;
//}
