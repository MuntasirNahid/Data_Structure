//LINEAR QUEUE:

//Front and Rear
//after any deletion : Front= Front+1;
//after any insertion : Rear= Rear+1;
//Front==Rear==NULL==0 means the queue is empty.
//we add elements in the Rear.
//Front=Rear means queue has only one element..

//main prob: overflow hoye jay if we want to insert an element after using all the memory...thats why runtime error dekha dey..

#include<iostream>
#define sz 3
using namespace std;

struct queue {
	int q[sz], front, rear;
	queue()
	{
		front = rear = -1; //empty
	}
	bool empty()
	{
		return !(~front);//front er man -1 holey ~front=0 and !0=1..
	}
	void push(int x)
	{
		if (rear + 1 == sz) //memory shob use kora hoye geche..push korar jayga nai..0 based indexing.
		{
			cout << "overflow!" << endl;
			return;
		}
		q[++rear] = x;
	}
	int pop()
	{
		if (empty())
		{
			cout << "Underflow!" << endl;
			return -1;
		}
		int x = q[front++]; //x er moddhe q[front] k rekhe front er man 1 baraya dilam.
		if (front - 1 == rear) //front==rear hoye geley queue ta empty hoye geche..
		{
			front = rear = -1;
		}

		return x;
	}
	int Front()
	{
		if (empty())
		{
			cout << "Queue is Empty!So no front is available." << endl;
			return -1;
		}
		return q[front];
	}
	void printQueue()
	{
		cout << "Start Queue ------------------" << endl;
		if (empty())
		{
			cout << "Empty Queue.Nothing to print!" << endl;
			cout << "End Queue ---------------" << endl;
			return;
		}
		for (int i = front; i <= rear; i++)
		{
			cout << q[i] << " \n"[i == rear];
		}
		cout << "End Queue ---------------" << endl;

	}


};
int main()
{

	queue *q = new queue();
	q->printQueue();
	cout << q->Front() << endl;
	q->pop();
	cout << q->empty() << endl;
	q->push(90);
	q->pop();
	q->pop();
	q->push(75);
	q->printQueue();
	q->push(45);
	q->printQueue();
	cout << q->empty() << endl;
	q->pop();
	q->printQueue();
	q->push(451);
	q->printQueue();
	cout << q->Front() << endl;
	q->push(-98);
	q->printQueue();
	cout << q->Front() << endl;
	q->push(81);
	q->printQueue();
	q->pop();
	q->printQueue();
	q->pop();
	q->printQueue();
	q->pop();
	q->printQueue();
	cout << q->Front() << endl;
	q->pop();
	q->printQueue();
	cout << q->empty() << endl;
	delete q;
	return 0;
}