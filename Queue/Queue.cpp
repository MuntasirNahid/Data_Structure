/*
Push- last
Pop- first
front()-first

enqueue=push_back()...dequeue=pop_front()...
*/
#include<bits/stdc++.h>
using namespace std;
void printqueue(queue<int>s)
{
	
	while (!s.empty())
	{
		cout<< s.front() << " ";
		s.pop();
	}
	cout<<endl;

}
int main()
{
	queue<int>stk1;
	stk1.push(45);
	stk1.push(15);
	stk1.push(22);
	stk1.push(98);
	cout << "Queue size = " << stk1.size() << endl;
	cout << "First element = " << stk1.front() << endl;
	stk1.pop();
	cout << "First element = " << stk1.front() << endl;
	stk1.push(56);
	cout << "The Elements of stk1 are = " ;
	printqueue(stk1);

//------------------Queue Swap---------------------------------
   
   queue<int>stk2;
    stk2.push(4);
	stk2.push(5);
	stk2.push(2);
	stk2.push(8);
	cout << "The Elements of stk2 are = " ;
    printqueue(stk2);

    stk1.swap(stk2);
    cout<<"After Swapping:"<<endl;
    cout << "The Elements of stk1 are = " ;
	printqueue(stk1);
	cout << "The Elements of stk2 are = " ;
	printqueue(stk2);

    
    stk1.empty();
    stk2.empty();

}
