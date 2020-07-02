#include"myheadfile.h"
#include"SortOrSearch.h"
#include"class_ThreadPool.h"
#include"thread_Lock.h"
#include"My_String.h"

char* my_strcpy(char *deststr, const char *str)//char*类型是为了方便后续的函数调用  链式连接
{
	assert(str != NULL);
	assert(deststr != NULL);//判断输入参数的合法性，如果条件为假，即终止程序。
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

char *my_strcat(char *deststr, const char *str)//字符串连接函数,将字符串str连接到字符串deststr后面
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

void *my_memcpy(void *deststr, const void *str,size_t count)//从存储区str复制n个字符到deststr中去。
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
//	if (strlen(deststr) < strlen(str))//如果目标字符内存不够
//	{
//		delete []deststr;
//		deststr = new char[count + 1];
//	}
//
//	if (deststr < str && deststr + count > str)//考虑内存重叠的情况
//	{
//		delete []deststr;
//		deststr = new char[count + 1];//如果重叠，重新申请一块内存
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
