#include <iostream>
#include <chrono>
#include "Deque.h"

using namespace std;



int main()
{

    Deque_with_sort t;
    srand(time(0));
    for(int i=0; i < 10;i++) {
        //t.Add_back(i);
        t.Add_back(rand() % 10);
    }
    for(int i=0; i < 10;i++) {
        cout<<t.GetValue(i)<<' ';
    }
    cout<<'\n';

    t.Sort(9);

    for(int i=0; i < 10;i++) {
        cout<<t.GetValue(i)<<' ';
    }
    cout << "\n";

    int key[1000];
    for (int i = 0; i != 1000; ++i) {
        key[i] = rand() % 1000;
    }
    //int n = 100;
    for(int n = 100; n<=1000; n+=100){

        Deque_with_sort deque;

        for (int i = 0; i != n; ++i) {
            deque.Add_back(key[i]);
        }
        cout << "\n";

        typedef std::chrono::high_resolution_clock Time;
        typedef std::chrono::milliseconds ms;

        auto t0 = Time::now();
        deque.Sort(n-1);
        auto t1 = Time::now();

        ms time = std::chrono::duration_cast<ms>(t1 - t0);

        cout << "Sorting " << n << " elements take: " << time.count() << " ms\n";

    }
    return 0;
}

