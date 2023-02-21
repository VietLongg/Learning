// https://viblo.asia/p/lam-quen-voi-multithreading-p2-AQ3vVka1RbOr

#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
#include <mutex>
#include <ctime>
#include <stdlib.h>
using namespace std;

int check = 0;
mutex m;
vector<int> vec;
void clock_1()
{
    cout << "Starting independent thread clock 1" << endl;
    for(int i = 0; i <= 1; ++i)
    {
		// system("clear");
		time_t now = time(0);
		tm *ltm = localtime(&now);
		cout << "Time 1: "<< ltm->tm_hour << ":";
		cout << ltm->tm_min << ":";
   		cout << ltm->tm_sec << endl;
		i = 0;
		if(ltm->tm_sec == 30)
		{
			check = 1;
		}
		else if(ltm->tm_sec == 0)
		{
			check = 0;
		}
        sleep(1);
		
    }
    cout << "Exiting independent thread clock 1" << endl;
}

void clock_2()
{
	cout << "Starting independent thread clock 2" << endl;
    for(int i = 0; i <= 1; ++i)
    {
		if(check != 0)
		{
		time_t now = time(0);
		tm *ltm = localtime(&now);
		cout << "Time 2: "<< ltm->tm_hour << ":";
		cout << ltm->tm_min << ":";
   		cout << ltm->tm_sec << endl;
		}
		i = 0;
        sleep(1);
	}
    cout << "Exiting independent thread clock 2" << endl;
}

void push()
{
	m.lock();
	for(int i = 0; i <= 10; i++)
	{
		cout << "Push" << i << endl;
		vec.push_back(i);
		sleep(1);
	}
	m.unlock();
}

void pop()
{
	m.lock();
	for(int i = 0; i <= 10; i++)
	{
		if (vec.empty() == false)
		{
			cout << "Pop " << vec.back() << endl;
			vec.pop_back();
		}
		sleep(1);
	}
	m.unlock();
}

int main()
{
	thread countingTime_1(clock_1);
	thread countingTime_2(clock_2);
	// thread pusher(push);
	// thread popper(pop);
		
	countingTime_1.join();
	countingTime_2.join();
	// pusher.join();
	// popper.join();

    system("pause");
    // cin.get();
}