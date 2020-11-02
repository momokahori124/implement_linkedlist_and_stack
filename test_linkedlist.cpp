#include "LinkedList.cpp"

int main()
{
	LinkedList test;

	test.insert_node(0,0);
	test.display_list();
	test.insert_node(1,1);
	test.display_list();
	test.insert_node(2,2);
	test.display_list();
	test.insert_node(3,3);
	test.display_list();
	test.insert_node(4,4);
	test.display_list();
	test.insert_node(5,5);
	test.display_list();

	//index3に9を挿入
	//{0,1,2,9,3,4,5}
	test.insert_node(3,9);
	test.display_list();

	//index3を削除
	//{0,1,2,3,4,5}
	test.remove_node(3);
	test.display_list();

	//reverse
	//{5,4,3,2,1,0}
	test.reverse();
	test.display_list();

	//index2を表示=4
	test.get_node(2);

	cout<<endl;

	LinkedList test1;

	test1.insert_node(0,0);
	test1.insert_node(1,1);
	test1.reverse();
	test1.display_list();

	return (0);
}