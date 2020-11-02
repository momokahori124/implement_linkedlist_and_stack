#include <bits/stdc++.h>
using namespace std;
#include "LinkedList.cpp"

/**********************************************
	Advanced Level Assignment
	Implement a Stack

	・Can push data to the stack
	・Can pop data to the stack
	・All stack logic should be correct
***********************************************/

class Stack : public LinkedList{
	public:
		Stack();
		~Stack();

		//スタックの機能
		void pop();//最後に入れた値を削除
		void push(double);//値を末尾に挿入
};

Stack::Stack(){
	head = NULL;
}
Stack::~Stack(){
	//nothing
}

/*******************************************
	push : 末尾に値を追加
*******************************************/

void Stack::push(double val){
	int len = LinkedList::list_count();
	LinkedList::insert_node(len,val);
}

/*******************************************
	pop : 末尾の要素を削除
*******************************************/

void Stack::pop(){
	int len = LinkedList::list_count();
	LinkedList::remove_node(len-1); //index = len-1
}