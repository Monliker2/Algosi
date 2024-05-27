#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    struct deque {
        int value;
        deque* next;
        deque* prev;
    };
    deque* head;
    deque* tail;
public:
    Deque();
    ~Deque();
    void Add_front(int value);
    void Add_back(int value);
    int Del_front();
    int Del_back();
    void ShowAll();
    int ShowHead();
    int ShowTail();
    bool IsEmpty();
};

class Deque_with_sort : public Deque{
private:
    void swap(int a, int b);
    int pivot(int low, int high);
public:
    int GetValue(int index);
    void SetValue(int index, int value);
    void Sort(int maxValue);
};

#endif //DEQUE_H
