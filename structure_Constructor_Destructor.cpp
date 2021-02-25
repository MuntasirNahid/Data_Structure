//constructor:
//A constructor is a member function of a class that has the same name as the class name.
// It helps to initialize the object of a class.
//It is called whenever an instance of the class is created.
// It can be defined manually with arguments or without arguments.


//destructor:
//deconstructor is also a member function of a class that has the same name as the class name preceded by a tilde(~) operator.
// It helps to deallocate the memory of an object.
//It is called while object of the class is freed or deleted.

#include<iostream>
using namespace std;
struct node
{
	int x;
	node()
	{
		x = 0;
		cout << "x is initialized with = " << x << endl;
	}
	// node(int k)
	// {
	// 	x=k;
	// 	cout<<"x is initialized with = "<<x<<endl;
	//}
	node(int k);
	void hello();
	~node()
	{
		cout << "Bye Bye! " << " x > " << x << endl;
	}

};
//return type structure name :: function name(parameter)
node :: node(int k)
{
	x = k;
	cout << "x is initialized with = " << x << endl;
}
void node:: hello()
{
	x += 77;
	cout << "x is incremented by 77 and x = " << x << endl;

}
void hello()
{
	node(67);
}//scope =validity...ei function shesh howar sathey sathey k er validity shesh hoye jabey..
//ei function er bairey k valid na...destruct korey fele..

int main()
{
	node a, b(5000), *p;
	cout << "what happended?" << endl;
	a.x = 40;
	a.hello();
	p = new node(599); //nije nije construct korley nij theke delete kortey hoy...normally system nijei destruct korey thakey.
	p->x = 99;
	hello();
	p->hello();
	delete p;
	return 0;//return 0 dekhar por destroy kora shuru hoye jay..



}
// output:
// x is initialized with = 0
// x is initialized with = 5000
// what happended?
// x is incremented by 77 and x = 117
// x is initialized with = 599
// x is initialized with = 67
// Bye Bye!  x > 67
// x is incremented by 77 and x = 176
// Bye Bye!  x > 176
// Bye Bye!  x > 5000
// Bye Bye!  x > 117

//for more: https://www.geeksforgeeks.org/difference-between-constructor-and-destructor-in-c/
