#include"myheadfile.h"
#include"SortOrSearch.h"
#include"Class.h"
#include"thread_Lock.h"
using namespace std;

void main()
{
	vector<int> arr = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> arr1 = {2,1,0,6,7,8,9};
	vector<int> arr2 = { 1000,900,800,700,600,500,400,300,200,100 };
	int arr3[] = { 100,90,80,70,60,50,40,30,20,10};
	int length = sizeof(arr3) / sizeof(int);
	double x = 20.0;
	int n = 10;
	List list = ListInsert(arr1);
	//List list1 = ListInsert(arr);
	//List list2 = ListInsert(arr);
	//cout << LoopList_is(list);
	//ListCout(list);
	//cout<<WordsNumOfString(StrCin())<<endl;
	/*string s = StrCin();
    cout<<LengthOfLongestSubstring(s);*/
	//Quick_Sort(arr2,0,arr2.size() - 1);
    //Merge(arr2, 0,arr2.size() - 1);
	//Shell_Sort(arr2);
	//Insert_Sort(arr2);
	//Select_Sort(arr2);
	//Bubble_Sort(arr2);
	//Count_Sort(arr2);
	//heap_Sort(arr2);
	//VectorCout(arr2);
	//IntCout(arr3,length);
	//cout<<SequenceSearch(arr3,80,length)<<endl;//˳����ҿ��Բ�������
	//cout << BinarySearch(arr3, 80, length) << endl;//���ֲ��ҵ�������Ҫ����
	//cout << InsertionSearch(arr3, 80, length) << endl;//������ҵ�������Ҫ����
	//cout << FibonacciSearch(arr3, 80, length) << endl;//쳲��������ҵ�������Ҫ����
	//cout << sqrt1(x) <<endl;
	//cout << sqrt2(x) << endl;
	//cout << GuapiJumpFloor(n)<<endl;
	//LRUCache *LRU = new LRUCache(5);
	//LRU->InserNode(1, 1);
	//LRU->InserNode(2, 2);
	//LRU->InserNode(3, 1);
	//cout << LRU->GetSize() << endl;
	//LRU->InserNode(4, 98);
	//LRU->InserNode(5, 10);
	//LRU->InserNode(6, 3);
	//cout << LRU->GetSize() << endl;
	//cout << LRU->Get(5) << endl;
	//for (size_t i = 1; i <= LRU->GetSize(); i++)
	//{
	//	cout << LRU->Get(i) << endl;
	//}
	ItemRepository* guoItem = new ItemRepository;
	InitItemRepository(guoItem);
	thread producer(ProducerTask,guoItem);//�����������߳�
	thread consumer(ConsumerTask,guoItem);//�����������߳�
	producer.join();
	producer.join();
}