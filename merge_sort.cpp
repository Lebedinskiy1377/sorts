#include <iostream>
#include "sorting.h"

void mergeSortImpl(int arr[], int l, int r, int& inv);
void merge(int arr[], int l, int mid, int r, int& inv);

// Сортировка слиянием.
// Временная сложность: в общем  случае - O(n * log n).
void mergeSort(int arr[], int n, int &inv) {
    mergeSortImpl(arr, 0, n - 1, inv);
}

void mergeSortImpl(int arr[], int l, int r, int& inv) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSortImpl(arr, l, mid, inv);
        mergeSortImpl(arr, mid + 1, r, inv);
        merge(arr, l, mid, r, inv);
    }
}

/*
void merge(int arr[], int l, int mid, int r) {
    int* tmp = new int[r-l+1];
    int begin1 = l;
    int end1 = mid;
    int begin2 = end1+1;
    int end2 = r;
    int i = 0;
    while (begin1 <= end1 && begin2 <= end2) {
            if (arr[begin1] >= arr[begin2]) {
             tmp[i] = arr[begin2];
             begin2++;
            }
            else {
             tmp[i] = arr[begin1];
             begin1++;
            }
            i++;
    }
    for (int j = begin1; j < end1; j++) {
        tmp[i] = arr[j];
        i++;
    }
    for (int j = begin2; j < end2; j++) {
        tmp[i]= arr[j];
        i++;
    }
    
    for (int i = l; i <= r; i++)
        arr[i] = tmp[i-l];
    
    delete[] tmp;
}*/

void merge(int arr[], int l, int mid, int r, int& inv) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    
    int* temp1 = new int[n1];
    int* temp2 = new int[n2];
    
    for (int i = 0; i < n1; i++) {
        temp1[i] = arr[i + l];
    }
    
    for (int i = 0; i < n2; i++) {
        temp2[i] = arr[i + mid + 1];
    }
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (temp1[i] <= temp2[j]) {
            arr[k] = temp1[i];
            i++;
        } else {
            arr[k] = temp2[j];
            j++;
            inv = inv + (n1 - i);
        }
        k++;
        //inv++;
    }
    
    while (i < n1) {
        arr[k] = temp1[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }
    
    delete[] temp1;
    delete[] temp2;
}

const int SIZE = 4;

void main() {
    int mas[SIZE] = { 8, 4, 2, 1 };
    int inv = 0;
    mergeSort(mas, SIZE, inv);
    std::cout << inv;
}