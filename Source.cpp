#include <iostream>

bool balance(int* arr, int n) {
    while (--n > 0)
        if (arr[n - 1] > arr[n])
            return true;
    return false;
}

void mix(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::swap(arr[i], arr[(rand() % n)]);
    }
}

void bogoSort(int* arr, int n) {
    while (balance(arr, n)) {
        mix(arr, n);
    }
}

void insertion_sort(int* arr, int size) {
    for (int i = 1; i < size; ++i)
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j) {
            std::swap(arr[j - 1], arr[j]);
        }
}

void merge(int* arr, int start, int end) {
    if (end - start < 2) {
        return;
    }

    if (end - start == 2) {
        if (arr[start] > arr[start + 1])
            std::swap(arr[start], arr[start + 1]);
        return;
    }

    int mid = start + (end - start) / 2;

    merge(arr, start, mid);
    merge(arr, mid, end);

    int* sol = new int[end];
    int b1 = start;
    int e1 = start + (end - start) / 2;
    int b2 = e1;
    int i = 0;
    while (i < end - start) {
        if (b1 >= e1 || (b2 < end && arr[b2] <= arr[b1])) {
            sol[i] = arr[b2];
            ++b2;
        }
        else {
            sol[i] = arr[b1];
            ++b1;
        }
        ++i;
    }

    for (int i = start; i < end; ++i) {
        arr[i] = sol[i - start];
    }
}

const int SIZE = 10;



int main() {
    int mas[SIZE] = { 5, 1, 12, 4, 18, 16, 14, 24, 30, -50 };
    unsigned int start = clock();
    insertion_sort(mas, SIZE);
    unsigned int final = clock();

   // for (auto& it : mas)
      //  std::cout << it << ' ';

    merge(mas, 0, SIZE);

    for (auto& it : mas)
        std::cout << it << ' ';

    std::cout << "\nTIME: " << final - start;

}