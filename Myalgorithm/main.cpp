#include<iostream>
#include<vector>
#include"myheadfile.h"
#include"SortOrSearch.h"
using namespace std;

int main()
{
	vector<int> arr = { 0,1,2,3,4,5 };
	vector<int> arr1 = {0,1,2,3,4,5,6,7,8,9};
	int arr2[] = { 100,90,80,70,60,50,40,30,20,10};
	int length = sizeof(arr2) / sizeof(int);
	ListNode *List = ListInsert(arr1);


	//cout << LoopList_is(List);

	//ListCout(List);

	//cout<<WordsNumOfString(StrCin())<<endl;

	/*string s = StrCin();
    cout<<LengthOfLongestSubstring(s);*/

	//Quick_Sort(arr2,0,length-1);
    //Merge(arr2, 0, length-1);
	//Shell_Sort(arr2, length);
	//Insert_Sort(arr2, length);
	//Select_Sort(arr2,length);
	//Bubble_Sort(arr2, length);
	//Count_Sort(arr2, length);
	heap_Sort(arr2, length);
	VectorCout(arr2,length-1);
	return 0;
}