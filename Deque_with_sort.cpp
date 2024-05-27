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

void Deque_with_sort::Sort(int maxValue) { // 20 + 227n + 137.5n^2 - 26.5n^3 + 63n^4
    int size = 0; // 1
    Deque_with_sort tmpDeque;
    while (!this->IsEmpty()) { // 1 + ∑_1^n▒〖(6 + 22)〗 = 1 + 28n
        int value = this->Del_front(); // 12
        tmpDeque.Add_back(value); // 9
        size++; // 1
    }

    // Создание вспомогательной таблицы count для подсчета
    Deque_with_sort count;
    for (int i = 0; i < size; ++i) { // 2 + ∑_1^n▒〖(1 + 9)〗 = 2 + 10n
        count.Add_back(0); // 9
    }

    // Восстановление исходного дека для дальнейшей работы
    while (!tmpDeque.IsEmpty()) { // 1 + ∑_1^n▒〖(6 + 20)〗 = 1 + 26n
        this->Add_back(tmpDeque.Del_front()); // 20
    }

    // Подсчет количества ключей, меньших данного
    for (int i = size - 1; i >= 1; --i) { // 3 + ∑_1^n▒〖(29 + 42n + 63n^3 - 63n^2 + 36.5n^2 - 36.5n)〗 = 3 + ∑_1^n▒〖(29 + 63n^3 - 26.5n^2  + 5.5n)〗 = 3 + 29n + 63n^4 - 26.5n^3 + 5.5n^2
        int key_i = this->GetValue(i); // 28 + 42n
        for (int j = i - 1; j >= 0; --j) { // 3 +  ∑_1^i▒〖(1 + 126n + 72)〗 = 3 + ∑_1^i▒〖(126n + 73)〗 = 3 + 126ni + 73i
            int key_j = this->GetValue(j); // 28 +42n
            if (key_i < key_j) { // 1
                count.SetValue(j,count.GetValue(j)+1); // 3 + 26 + 42n + 14+ 42n = 84n + 43
            } else {
                count.SetValue(i,count.GetValue(i)+1); // 84n +43
            }
        }
    }

    // Создание временного дека для хранения отсортированных элементов
    Deque_with_sort sortedKeys;
    for (int i = 0; i < size; ++i) { // 2 + ∑_1^n▒〖(1 + 9)〗 = 2 + 10n
        sortedKeys.Add_back(0); // 9
    }
    for (int i = 0; i < size; ++i) { // 2 + ∑_1^n▒〖(1 + 126n + 70)〗 = 2 + 126n^2 + 70n
        sortedKeys.SetValue(count.GetValue(i),this->GetValue(i)); // 4 + 52 + 84n + 14 +42n = 126n + 70
    }

    // Очистка исходного дека и добавление отсортированных элементов
    while (!this->IsEmpty()) { // 6 ∑_1^n▒〖(6 + 11)〗 = 6 + 17n
        this->Del_front(); // 11
    }
    for (int i = 0; i < size; ++i) { // 2 + ∑_1^n▒〖(1 + 36 + 42n)〗 = 2 + 37n +42n^2
        this->Add_back(sortedKeys.GetValue(i)); // 2 + 26 + 42n + 8
    }
}