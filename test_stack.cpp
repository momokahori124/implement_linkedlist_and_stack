#include "Stack.cpp"

int main()
{
	Stack test;

	test.display_list(); //{}
	test.push(0);
	test.display_list(); //{0}
	test.push(1);
	test.display_list(); //{0,1}
	test.push(2);
	test.display_list(); //{0,1,2}
	test.push(3);
	test.display_list(); //{0,1,2,3}

	test.pop();
	test.display_list(); //{0,1,2}
	test.pop();
	test.display_list(); //{0,1}
	test.pop();
	test.display_list(); //{0}
	test.pop();
	test.display_list(); //{}

}