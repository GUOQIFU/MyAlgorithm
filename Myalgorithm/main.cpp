#include"myheadfile.h"
#include"Leetcode.h"
using namespace std;


void func(int i) {
	cout << "task finish" << "------>" << i << endl;
}

void main()
{
	//vector<int> arr = { 0,1,2,3,4,5,6,7,8};
	vector<int> arr1 = {7,1,6,3,5,2,4,8,9 };
	vector<int> arr2 = {10,9,8,7,6,5,4,3,2,1,11,12};
	//vector<int> res = VecBjianVecA(arr1, arr2);//arr2 - arr1
	//VectorCout(res);
	//int arr3[] = { 2,1,0,6,7,8,9 };
	//Guo_Tree Guo_Tree;
	//BiTree GuoTree = NULL;
	//Guo_Tree.Pre_CreatBitree_arr(GuoTree,arr2,0);
	////Guo_Tree.Pre_CreatBiTree_Cin(GuoTree);
	//Mid_OrderTraverse(GuoTree); cout << endl;
	//int NodesNum = CountNodes(GuoTree);
	//cout << "The Full Tree have " << NodesNum << " Nodes total"<<endl;
	//int NumNodes = NumOfTreeNode(GuoTree);//递归统计节点数量
	//cout << "The Tree have " << NumNodes << " Nodes total" << endl;

	//Guo_SearchTree Guo_SearchTree;
	//BiTree GuoSearchTree = NULL;
	//for (size_t i = 0; i < arr1.size(); i++)
	//{
	//	Guo_SearchTree.InsertSerchTreeNode(GuoSearchTree, arr1[i]);
	//}
	//Pre_OrderTraverse(GuoSearchTree);//前序遍历
	//Mid_OrderTraverse(GuoSearchTree);
	//Back_OrderTraverse(GuoSearchTree);
	//cout << endl;
	//Guo_SearchTree.InsertSerchTreeNode(GuoSearchTree, 520);
	//Pre_OrderTraverse(GuoSearchTree);
	//Pre_OrderTraverseWithoutRecursion(GuoSearchTree);//非递归前序遍历
	//Mid_OrderTraverseWithoutRecursion(GuoSearchTree);
	//Back_OrderTraverseWithoutRecursion(GuoSearchTree);
	//cout << endl;
	//Guo_SearchTree.DeleteSerchNode(GuoSearchTree, 7);
	//Pre_OrderTraverse(GuoSearchTree);
	//cout << endl;
	//int MAXdepth = GetMaxDepthBitree(GuoSearchTree);
	//cout << "the tree Maxdepth is "<<MAXdepth<< endl;
	//cout << "the tree Mindepth is "<<GetMinDepthBitree(GuoSearchTree)<< endl;
	//cout << "The Tree have " << NumOfTreeNode(GuoSearchTree) << " Nodes total" << endl;//递归统计节点数量
	//cout << "The Tree have " << NumOfYezhiNode(GuoSearchTree) << " Yezhi Nodes total" << endl; 
	//cout << "The Tree have " << NumOfKlevelTreeNodes(GuoSearchTree,2) << "  Nodes in the level"<< endl;
	
	//vector<int>arr3 = { 100,90,80,70,60,50,40,30,20,10};
	//int length = sizeof(arr3) / sizeof(int);
	//double x = 20.0;
	//int n = 10;
	//List list = ListInsert(arr3);
	////list = ReverseList(list);
	//list = ReverseList2(list);
	//ListCout(list);
	//List list1 = ListInsert(arr);
	//List list2 = ListInsert(arr);

	//cout << LoopList_is(list);
	//ListCout(list);
	//cout<<WordsNumOfString(StrCin())<<endl;
	/*string s = StrCin();
    cout<<LengthOfLongestSubstring(s);*/



	//Quick_Sort(arr2,0,arr2.size() - 1);
    Merge(arr2, 0,arr2.size() - 1);
	//Shell_Sort(arr2);
	//Insert_Sort(arr2);
	//Select_Sort(arr2);
	//Bubble_Sort(arr2);
	//Count_Sort(arr2);
	//heap_Sort(arr2);
	VectorCout(arr2);
	//IntCout(arr3,length);

	//cout<<SequenceSearch(arr3,80,length)<<endl;//顺序查找可以不用排序
	//cout << BinarySearch(arr3, 80, length) << endl;//二分查找的序列需要排序
	//cout << InsertionSearch(arr3, 80, length) << endl;//插入查找的序列需要排序
	//cout << FibonacciSearch(arr3, 80, length) << endl;//斐波拉契查找的序列需要排序
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
	////cout << LRU->Get(1) << endl;
	//LRU->LRUCOUT();
	/*for (size_t i = 1; i <= LRU->GetSize(); i++)
	{
		cout << LRU->Get(i) << endl;
	}*/

	//生产消费模型。
	//ItemRepository* guoItem = new ItemRepository;
	//InitItemRepository(guoItem);
	//thread producer(ProducerTask,guoItem);//创建生产者线程
	//thread consumer(ConsumerTask,guoItem);//创建消费者线程
	//producer.join();//
	//consumer.join();//

	//ThreadPool p;
	//p.start(10);
	//int i = 0;
	//while (1) {
	//	i++;
	//	this_thread::sleep_for(chrono::seconds(1));//休眠等待
	//	auto task = bind(func, i);//auto 类型说明符，通过变量的初始化操作来推断变量的类型，
	//	                          //bind()函数，通用的函数适配器。当调用task的时候，task会调用func()函数，并传入i参数
	//	p.addTask(task);
	//}
	//p.finish();
	//My_String str1("guoqi");
	//My_String str2(str1._str);
	//My_String str3 = str2;
	//StrCout(str1._str);
	//StrCout(str2._str);
	//StrCout(str3._str);

	/*char str1[] = "guoqifu";
    const char str2[] = "liujiao";
	void *str3 = my_memcpy(str1, str2, 7);
	StrCout((char *)str3);*/
 

	/*vector<int> a1 = { 2,4,3 };
	vector<int> a2 = { 5,6,4 };
	ListNode *L1 = ListInsert(a1);
	ListNode *L2 = ListInsert(a2);
	ListCout(L1);
	ListCout(L2);
	ListNode *L3 = AddTwoNumbers(L1, L2);
	ListCout(L3);*/
	
//double guo = FindMedianSortedArray(arr1, arr2);
//cout << guo << endl;

    //动态规划
	/*vector<int> vec1 = { 1,3,1,1,5,1,4,2,1};
	int index = 0;
	vector<vector<int>> grid(vec1.size()/3,vector<int>(vec1.size()/3));
	for (size_t i = 0; i < grid.size(); i++)
	{
		for (size_t j = 0; j < grid[i].size(); j++)
		{
			grid[i][j] = vec1[index++];
		}
	}
	DoubleVectorCout(grid);

	cout << MinPathSum(grid) << endl;*/
	
 /*   vector<int> arr = { 1,2,3,4,5};
	vector<vector<int>> res = permute(arr);
	int n = 1;
	for (size_t i = 0; i < res.size(); i++)
	{
		for (size_t j = 0; j < res[0].size(); j++)
		{
			cout << res[i][j] << " ";	
		}
		cout << "\n";
	}*/
//int n = 1;
//vector<vector<string>> res = SolveNQueens(8);
//	for (size_t i = 0; i < res.size(); i++)
//	{
//		for (size_t j = 0; j < res[0].size(); j++)
//		{
//			string str = res[i][j];
//			StringCout(str);
//		}
//		cout <<"第"<< n++ <<"种"<<endl;
//		cout << "           " << endl;
//	}
}

