#include <bits/stdc++.h>
using namespace std;

/**********************************************
	Basic Level Assignment
	Implement a Linked List

	・Can add Nodes at a given index from an index parameter
	・Can remove Nodes at a given index from an index parameter
	・Pointer and Node logic should be correct
	・Can get data from an index parameter
***********************************************/

class LinkedList
{
	protected:
		struct ListNode
		{
			double value;
			ListNode *next;
		};
		ListNode *head;//先頭ノードへのポインタ

	public:
		LinkedList();
		~LinkedList();

		//連結リストの機能
		void remove_node(int);//indexの値を削除
		void insert_node(int, double);//indexに値を挿入
		void get_node(int);//indexの値を取得
		int list_count(); //リストの要素をカウント
		void display_list();//リストを全部列挙
		void reverse();//逆にする
};

LinkedList::LinkedList(){
	head = NULL;
}
LinkedList::~LinkedList(){
	//nothing
}

/**********************************************
	insert_node : リストの途中にノードを追加する
	(1)新たなノードを作成する
	(2)リストのindexにそれを追加する
		・リストが空かつindex=0ならheadにセット
		・空でないならindexまで移動してindex以降をずらしてindexをつなぐ
***********************************************/

void LinkedList::insert_node(int idx, double num){
	ListNode *new_node;//今追加したい新しいノード
	ListNode *node_tmp;//リスト移動用のノード
	ListNode *node_save;//リスト保存用のノード

	new_node = new ListNode;

	new_node->value = num;
	new_node->next = NULL;

	if (head==NULL)
	{
		if (idx!=0) {
			cout<<"Error : Can't insert. Index number is wrong."<<endl;
			return;
		}
		head = new_node;
		//cout<<head->value<<endl;
	}
	else
	{
		node_tmp = head;
		int count=1;
		int inserted=0;
		if (idx==1)
		{
				//次に指しているノードをsaveしておく
				node_save = node_tmp->next;
				//append new_node
				node_tmp->next = new_node;
				new_node->next = node_save;

				inserted=1;
		}
		while (node_tmp->next)
		{
			node_tmp = node_tmp->next;
			count++;
			if (count==idx)
			{
				//次に指しているノードをsaveしておく
				node_save = node_tmp->next;
				//append new_node
				node_tmp->next = new_node;
				new_node->next = node_save;

				inserted=1;
			}
		}
		if (inserted==0)
		{
			cout<<"Error : Can't insert. Index number is wrong."<<endl;
			return;
		}
	}
}

/**********************************************
	remove_node : indexのノードを削除する
		index-1番目のノードをindex+1番目のノードに繋げる
***********************************************/

void LinkedList::remove_node(int idx){
	ListNode *node_tmp;//リスト移動用のノード
	ListNode *node_save;//リスト保存用のノード

	node_tmp = head;

	if (head == NULL)//要素０
	{
		cout<<"Error : No elements."<<endl;
		return;
	}

	if (idx == 0){
		node_save = head;
		head = head->next;
		delete node_save;
		return;
	}

	int count=0;
	while (node_tmp->next){
		if (count==idx-1){
			node_save=node_tmp->next;
			node_tmp->next= (node_tmp->next)->next;
			delete node_save;
			return;
		}
		node_tmp = node_tmp->next;
		count++;
	}
	// !(count==idx-1)
	cout<<"Error : Can't remove. Index number is wrong."<<endl;
	return;
}

/**********************************************
	list_count : リストの要素をカウントする
***********************************************/

int LinkedList::list_count()
{
	ListNode *node_save;//リスト保存用のノード

	if (head==NULL) return (0);

	node_save = head;
	int count= 1;
	while (node_save->next){
		count++;
		node_save = node_save->next;
	}
	return (count);
}


/**********************************************
	reverse : リストを逆順にする
	(1)リストの要素数をカウントしてvalueを保存する
	(2)後ろのdataから順に入れてあげる
***********************************************/

void LinkedList::reverse()
{
	ListNode *node_tmp;//リスト移動用のノード
	int len = list_count();

	node_tmp = head;

	vector<int> data(len);
	for (int i=0;i<len;i++){
		data[i]=node_tmp->value;
		node_tmp = node_tmp->next;
	}

	node_tmp = head;//headに戻ってdataを逆順に入れていく
	for (int i=0;i<len;i++){
		node_tmp->value = data[len-i-1];
		node_tmp = node_tmp->next;
	}
}


/**********************************************
	display_list : リストの全要素を表示
***********************************************/

void LinkedList::display_list()
{
	ListNode *node_save;//リスト保存用のノード
	if (head==NULL){
		cout<<"{}"<<endl;
		return;
	}
	node_save = head;
	cout<<"{";
	while (node_save->next){
		cout<<node_save->value<<",";
		node_save = node_save->next;
	}
	cout<<node_save->value;
	cout<<"}"<<endl;
}

/**********************************************
	get_node : indexの要素を取得する
***********************************************/

void LinkedList::get_node(int idx)
{
	ListNode *node_save;//リスト保存用のノード
	if (head==NULL){
		cout<<"Error : No elements."<<endl;
		return;
	}
	node_save = head;
	int count=-1;
	while (node_save->next){
		count++;
		if (idx==count)
		{
			cout<<node_save->value<<endl;
			return;
		}
		node_save = node_save->next;
	}
}