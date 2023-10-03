#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void shellsorthibbard(int arr[], int n, int k) {

    // perform shell sort using Hibbard increments
    while (k >= 0) {
        // calculate the current increment value
        int h = pow(2, k) - 1;

        // perform insertion sort for elements separated by h
        for (int i = h; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= h && arr[j - h] > temp) {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = temp;
        }

        // decrement k to get the next increment value
        k--;
    }
}

void shellSortSedgewick(int arr[], int n, int h)
{

    // Perform insertion sort with increment h
    while (h >= 1)
    {
        // Perform insertion sort for sublist arr[i, i+h, i+2*h, ...]
        for (int i = 0; i < n; i++)
        {
            int key = arr[i];
            int j = i;
            while (j >= h && arr[j - h] > key)
            {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = key;
        }

        // Calculate the next value in the Sedgewick increment sequence
        h = (h - 1) / 3;
    }
}

int* randomgen(int n) {
    srand(time(0));

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Return the array
    return arr;
}

int* randomgendes(int n) {
    srand(time(0));

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; 
    }

    sort(arr, arr + n, greater<int>());

    return arr;
}

int main()
{
    int n = 20000;
    int h = 1;
    while (h < n)
    {
        h = (4 << h) + 3 * (2 << (h - 1)) + 1;
    }
    int k = 1;
    while (pow(2, k) - 1 < n) {
        k++;
    }

    // decrement k to get the largest Hibbard increment value less than n
    k--;
    
    
    for(int i = 0; i < 10; i++)
    {
        int *arr = randomgen(n);
        int *arr1 = randomgendes(n);
        auto start = chrono::high_resolution_clock::now();
        shellsorthibbard(arr, n, k);
        auto end = chrono::high_resolution_clock::now();
        cout << "Hibbard data 1 TIME: " << chrono::duration<double, micro>(end - start).count() << endl;
     
        auto start2 = chrono::high_resolution_clock::now();
        shellSortSedgewick(arr, n, h);
        auto end2 = chrono::high_resolution_clock::now();
        cout << "Sedgewick data 1 TIME: " << chrono::duration<double, micro>(end2 - start2).count() << "\n\n";

        auto start1 = chrono::high_resolution_clock::now();
        shellsorthibbard(arr1, n, k);
        auto end1 = chrono::high_resolution_clock::now();
        cout << "Hibbard data 2 time: " << chrono::duration<double, micro>(end1 - start1).count() << endl;
        
        auto start3 = chrono::high_resolution_clock::now();
        shellSortSedgewick(arr1, n, h);
        auto end3 = chrono::high_resolution_clock::now();
        cout << "Sedgewick data 2 TIME: " << chrono::duration<double, micro>(end3 - start3).count() << "\n###################################################################\n";

        delete[] arr;
        delete[] arr1;
    }
    return 0;
}