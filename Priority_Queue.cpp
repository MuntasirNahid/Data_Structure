//Normally sorted thake descending order a..
#include<bits/stdc++.h>
using namespace std;
void printprq(priority_queue<int>p)
{
	while (!p.empty())
	{
		cout << p.top() << " ";//top=front one
		p.pop();
	}
	//or iterator use korey kora jay...
}
int main()
{
	priority_queue<int>pq;
	//ascending order er jonno
	//priority_queue<int,vector<int>,greater<int> >pq;
	pq.push(-5);
	pq.push(-10);
	pq.push(-2);
	pq.push(-7);
	pq.push(-5);

	cout << "the max element = " << pq.top() << endl;
	pq.pop();
	cout << "the max element = " << pq.top() << endl;
	pq.pop();
	cout << "the max element = " << pq.top() << endl;
	
	pq.push(100);
	pq.push(756);
	pq.push(32);
	pq.push(-90);
	cout << "The Element of the priority_queue :" << endl;
	printprq(pq);


}
