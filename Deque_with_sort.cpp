#include "Deque.h"

int Deque_with_sort::GetValue(int index) { // 26 + 42n
    Deque_with_sort tmp;
    int ret = 0; // 1
    for(int i = 0; i != index; ++i){ // 1 + 1 + ∑_1^n▒〖(2 + 21)〗
        int t = Del_front(); // 1 + 11
        tmp.Add_back(t); // 1 + 8
    }
    ret = Del_front(); // 1 + 11
    Add_front(ret); // 1 + 8
    while(!tmp.IsEmpty()){ // 1 + ∑_1^n▒〖(1 + 18)〗
        int temp = tmp.Del_back(); // 1 + 8
        Add_front(temp); // 1 + 8
    }
    return ret; // 1
}

void Deque_with_sort::SetValue(int index, int value) { // 14 + 42n
    Deque_with_sort tmp;
    int ret = 0; // 1

    for(int i = 0; i != index; ++i){ // 1 + 1 + ∑_1^n▒〖(2 + 21)〗
        int t = Del_front(); // 1 + 11
        tmp.Add_back(t); // 1 + 8
    }
    Del_front();
    Add_front(value); // 1 + 8

    while(!tmp.IsEmpty()){ // 1 + ∑_1^n▒〖(1 + 18)〗
        int temp = tmp.Del_back(); // 1 + 8
        Add_front(temp); // 1 + 8
    }
}

void Deque_with_sort::Sort(int maxValue) { // 2 + 4n + 2n^2 + 133n^2 + 252n^3
    for (int i = 0; i < maxValue; i++) { // 2 + ∑_1^n▒〖(1 + 3 + 2n + 133n + 252n^2)〗 = 2 + 4n + 2n^2 + 133n^2 + 252n^3
        for (int j = 0; j < maxValue-1; j++) { // 3 + ∑_1^n▒〖(2 + 133 + 252n)〗 = 3 + 2n + 133n + 252n^2
            if (GetValue(j) > GetValue(j+1)) { // 4 + 40 + 84n
                int t = GetValue(j); // 28+42n
                SetValue(j, GetValue(j+1)); // 4 + 26 + 14 + 84n = 44 + 84n
                SetValue(j+1, t); // 3 + 14 + 42n = 42n + 17
            }
        }
    }
}
