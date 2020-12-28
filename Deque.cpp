/*
Double ended queues(Deque) are a special case of queues where insertion and deletion operations are possible at both the ends.
The functions for deque are same as vector, with an addition of push and pop operations for both front and back.

*/
#include<bits/stdc++.h>
using namespace std;
void printdeque(deque<int>dq)
{
	auto it = dq.begin();
	for (it; it != dq.end(); it++)
	{
		cout << *it << " ";
	}
}
int main()
{
	int n;
	deque<int> q;
	q.push_back(4);
	q.push_back(5);
	q.push_front(8756);
	q.push_front(2);
	q.pop_front();
	q.push_back(10);
	q.push_front(20);
	q.push_back(30);
	q.push_front(15);
	cout << "first element = " << q.front() << endl;
	cout << "last element = " << q.back() << endl;
	q.pop_back();
	q.pop_back();
	cout << "first element = " << q.front() << endl;
	cout << "last element = " << q.back() << endl;
	//n tomo position a kon element achey oita check er way..
	cout << "Deque's 3rd element =" << q.at(2) << endl;;
	cout << "The Deque is :" << endl;
	printdeque(q);

	return 0;
}

