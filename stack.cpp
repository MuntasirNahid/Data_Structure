/*
  1)Insert and deletion happens at the same end...
  2)Push- insert last element O(1)
   Pop- delete last element- O(1)
   Top-return the last element- O(1)
  3)empty() dile purata empty hoye jabey..


*/
#include<bits/stdc++.h>
using namespace std;
void printstk1(stack<int>s)
{
	
	while (!s.empty())
	{
		cout<< s.top() << " ";
		s.pop();
	}
	cout<<endl;

}
int main()
{
	stack<int>stk1;
	stk1.push(45);
	stk1.push(15);
	stk1.push(22);
	stk1.push(98);
	cout << "stack size = " << stk1.size() << endl;
	cout << "last element = " << stk1.top() << endl;
	stk1.pop();
	cout << "last element = " << stk1.top() << endl;
	stk1.push(56);
	cout << "The Elements of stk1 are = " ;
	printstk1(stk1);

//------------------Stack Swap---------------------------------
   
    stack<int>stk2;
    stk2.push(4);
	stk2.push(5);
	stk2.push(2);
	stk2.push(8);
	cout << "The Elements of stk2 are = " ;
    printstk1(stk2);

    stk1.swap(stk2);
    cout<<"After Swapping:"<<endl;
    cout << "The Elements of stk1 are = " ;
	printstk1(stk1);
	cout << "The Elements of stk2 are = " ;
	printstk1(stk2);

    
    stk1.empty();
    stk2.empty();

}