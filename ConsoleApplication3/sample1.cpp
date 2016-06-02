// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

//void swap(char&a, char&b)
//{
//	char temp = a;
//	a = b;
//	b = temp;
//}
void permuterecursive(string& array, list<string> & out, unsigned int index = 0)
{
	if (index == array.length())
	{
		out.push_back(array);
		cout << array<<endl;
		
		return;
	}

	for (unsigned int i = index; i < array.length(); i++)
	{
		
		swap(array[i], array[index]);
		permuterecursive(array, out, i + 1);
		swap(array[i], array[index]);
	}
}

void getComb(string& array, string& comb, unsigned int index)
{
	for (unsigned long i = 0; i < array.length(); i++)
	{
		auto picked = index & 1<<(i);
			if (picked != 0)
			comb.push_back(array[i]);
	}
	
}
void combination(string& array)
{
	unsigned long total = 1 << array.length();
	
	for (unsigned int i = 0; i < total; i++)
	{
		string comb;
		getComb(array, comb, i);
		cout << "{"+ comb +"}" << endl;
		
		
	}

}

template <typename Iterator>
bool compare(Iterator begin1, Iterator end1, Iterator begin2, Iterator end2)
{
	if (begin1 == end1) throw std::logic_error("....");
	if (begin2 == end2) throw std::logic_error("....");

	auto s1 = begin1;
	auto s2 = begin2;
	for (; s1 != end1 && s2 !=end2; ++s1, ++s2)
	{
		if (*s1 != *s2)
		{
			return false;
		}
	}
	return s1 == end1 && s2 == end2;
}

bool compare(list<string>& list1, list<string>& list2)
{
	 list1.sort();
	 list2.sort();
	auto i = list1.begin();
	auto j = list2.begin();
	
	for (; i != list1.end() && j != list2.end(); i++, j++)
	{
		if (*i != *j)
		{
			return false;
		}
	}

	return i == list1.end() && j == list2.end();
}
template <class T> class Node
{
public:
	T* data;
	Node* left;
	Node* right;
	Node* next;
	Node(T* _data, Node* _left = NULL, Node* _right = NULL, Node* _next = NULL)
	{
		this->left = _left;
		this->right = _right;
		this->next = _next;
		this->data = _data;
	}
};
template <class T> class Queue
{
	Node<T>* head;
	Node<T>* tail;

public:
	T* Pop() {

		if (IsEmpty()) {
			return NULL;
		}
		Node<T>* temp = head;
		T* ret = head->data;
		head = temp->next;
		delete temp;
		return ret;
	}

	void Push(T* _data) {

		Node<T>* node = new Node<T>(_data);

		if (IsEmpty()) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}

	}

	bool IsEmpty() {
		return head == NULL;
	}
	Queue() {
		head = NULL;
		tail = NULL;
	}
	~Queue() {
		if (!IsEmpty()) {
			T* temp;
			while ((temp = Pop()) != NULL)
			{
			}
		}
	}
};
typedef Node<int> IntNode;
//int main()
//{
//	typedef Node<int> IntNode;
//	int data[] = { 2, 1, 0, 5, 9, 11, 17 };
//	IntNode* tree1 = new IntNode(&data[6],
//		new IntNode(&data[0],
//		new IntNode(&data[1]),
//		new IntNode(&data[2])
//		),
//		new IntNode(&data[3],
//		new IntNode(&data[4]),
//		new IntNode(&data[5])
//		)
//		);
//
//	typedef Queue<int> IntQue;
//
//	IntQue que;
//
//	for (int i = 0; i < sizeof(data) / sizeof(int); i++)
//	{
//		que.Push(&data[i]);
//	}
//
//	return 0;
//}
typedef Queue<int> IntQue;
typedef Queue<IntNode> IntNodeQue;
void BFS_Iterate(IntNodeQue& que, int level = 0)
{
	IntNode* root;
	IntNodeQue que1;
	cout << "level:"<< level << endl;

	while ((root = que.Pop()) != NULL)
	{
		if (root->left != NULL) { que1.Push(root->left); }
		if (root->right != NULL) { que1.Push(root->right); }

		cout << *(root->data) << endl;
	}
	if (!que1.IsEmpty())
	{
		BFS_Iterate(que1, ++level);
	}
}

void BFS(IntNode* root)
{
	IntNodeQue que;
	que.Push(root);
	BFS_Iterate(que);
}
int GetPivot(int start, int end) { return (start + end) / 2; }

int partition(int* arr, int start, int end)
{
	int x = arr[start];
	int j = start;
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] < x)
		{
			++j;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[start], arr[j]);

		return j;

}

void Qsort(int* arr, int start, int end)
{

	if (start >= end) return;
	int pivot = GetPivot(start, end);
	swap(arr[pivot], arr[start]);
	int m = partition(arr, start, end);

		Qsort(arr, start, m - 1);
	    Qsort(arr, m + 1, end);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int data[] = { 2, 1, 0, 5, 9, 11, 17 };

	list<string> list1;
	list<string> list2;
	
	IntNode* tree1 = new IntNode(&data[6],
				new IntNode(&data[0],
				new IntNode(&data[1]),
				new IntNode(&data[2])
				),
				new IntNode(&data[3],
				new IntNode(&data[4]),
				new IntNode(&data[5])
				)
				);
	BFS(tree1);
	IntQue* que = new IntQue();
	//permuterecursive(string("abc"), list2);
	//compare(list1, list2);
	combination(string("abc"));

	int arr[] = { 8, 9, 6, 5, 4, 3, 2, 2, 1 };
	Qsort(arr, 0, sizeof(arr) / sizeof(*arr)-1);

	return 0;
}

