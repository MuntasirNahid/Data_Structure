#include<iostream>
#define sz 3
using namespace std;
struct stack{
	int arr[sz], top;
	stack()
	{
		top = -1; //top=-1 diye initialize kore nilam.
	}
	void push(int x)
	{
		if (top + 1 == sz) //0 based indexing.top+1=sz hoye jawa mane shob memory shesh..push korar ar jayga nai.
		{
			cout << "Overflow!" << endl;
			return;
		}
		arr[++top] = x;
	}
	int Top()
	{
		if (!(~top)) //top=-1 holey ~top=0,!0=1.that means if is true
		{
			cout << "Empty Stack.So,No question about Top." << endl;
			return -1;
		}
		return arr[top];

	}
	int pop()
	{
		if (!(~top)) //top=-1 holey ~top=0,!0=1.that means if is true
		{
			cout << "Underflow!" << endl;
			return -1;
		}
		return arr[top--];
	}
	bool empty()
	{
		return !(~top);
	}
	void printStack()
	{
		cout << "Start Stack --------------" << endl;
		if (!(~top)) {
			cout << "Empty Stack.Nothing to print!" << endl;
			cout << "End Stack   --------------" << endl;
			return;
		}
		for (int i = top; i >= 0; i--)
		{
			cout << arr[i] << " \n"[i == 0];
		}
		cout << "End Stack   --------------" << endl;

	}
};

int main()
{
	stack *st= new stack();
	st->printStack();
	cout << st->Top() << endl;
	st->pop();
	cout << st->empty() << endl;
	st->push(90);
	st->pop();
	st->pop();
	st->push(75);
	st->printStack();
	st->push(45);
	st->printStack();
	cout << st->empty() << endl;
	st->push(451);
	st->printStack();
	cout << st->Top() << endl;
	st->push(-98);
	st->printStack();
	cout << st->Top() << endl;
	st->push(81);
	st->printStack();
	st->pop();
	st->printStack();
	st->pop();
	st->printStack();
	st->pop();
	st->printStack();
	st->pop();
	st->printStack();
	cout << st->Top() << endl;
	st->pop();
	st->printStack();
	cout << st->empty() << endl;
	delete st;
	return 0;

}