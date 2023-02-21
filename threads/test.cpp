#include <iostream>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

void independentThread()
{
    cout << "Starting independent thread" << endl;
    for(int i = 0; i <= 10; i++)
    {
        cout << "Independent" << i << endl;
        sleep(1);
    }
    cout << "Exiting independent thread" << endl;
}

void threadCaller()
{
    cout << "Starting thread caller" << endl;
    thread a(independentThread);
    a.detach();
    // a.join();
    for(int i = 0; i <= 5; i++)
    {
        cout << "Caller " << i << endl;
        sleep(2);
    }
    // a.detach();
    // a.join();
    cout << "Exiting thread caller" << endl;
}

int main()
{
    threadCaller();
    system("pause");
    // cin.get();
}