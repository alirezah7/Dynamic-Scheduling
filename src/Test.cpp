#include <iostream>
#include <unistd.h>
#include <queue>
#include <functional>
#include "../include/Client.h"
using namespace std;

void foo(int x)
{
	cout<< "foo started " <<endl;
	sleep(x);
	cout << "foo finished" <<endl;
}

void foo2(int x)
{
	cout<< "foo1 started " <<endl;
	sleep(x);
	cout << "foo1 finished" <<endl;
}

void foo3(int x)
{
	cout<< "foo2 started " <<endl;
	sleep(x);
	cout << "foo2 finished" <<endl;
}

void foo4(int x)
{
	cout<< "foo3 started " <<endl;
	sleep(x);
	cout << "foo3 finished" <<endl;
}

void foo5(int x)
{
	cout<< "foo4 started " <<endl;
	sleep(x);
	cout << "foo4 finished" <<endl;
}

void bar(int x)
{
	cout<< "bar started " <<endl;
	sleep(x);
	cout << "bar finished" <<endl;
}

void bar2(int x)
{
	cout<< "bar1 started " <<endl;
	sleep(x);
	cout << "bar1 finished" <<endl;
}

void bar3(int x)
{
	cout<< "bar2 started " <<endl;
	sleep(x);
	cout << "bar2 finished" <<endl;
}

void bar4(int x)
{
	cout<< "bar3 started " <<endl;
	sleep(x);
	cout << "bar3 finished" <<endl;
}

void bar5(int x)
{
	cout<< "bar4 started " <<endl;
	sleep(x);
	cout << "bar4 finished" <<endl;
}

int main()
{
	vector<function<void()>> q1, q2;
	q1.push_back( [&] { foo(5); } );	q1.push_back( [&] { foo2(5); } );	q1.push_back( [&] { foo3(5); } );	q1.push_back( [&] { foo4(5); } ); q1.push_back( [&] { foo5(5); } );
	q2.push_back( [&] { bar(5); } );	q2.push_back( [&] { bar2(5); } );	q2.push_back( [&] { bar3(5); } );	q2.push_back( [&] { bar4(5); } ); q2.push_back( [&] { bar5(5); } );

	Client client(q1, q2);
	client.Start();
}

