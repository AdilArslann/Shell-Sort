#include <iostream>

// Function to perform shell sort with Hibbard increment sequence
void shell_sort_hibbard(int arr[], int n)
{
    // Initialize the increment sequence
    int h = 1;

    // Calculate the next value in the sequence
    while (h < n / 3)
        h = 3 * h + 1;

    // Perform insertion sort with increment h
    while (h >= 1)
    {
        // Perform insertion sort for sublist arr[i, i+h, i+2*h, ...]
        for (int i = h; i < n; i++)
        {
            int key = arr[i];
            int j = i;

            // Shift elements of arr[0..i-1], that are greater than key,
            // to one position ahead of their current position
            while (j >= h && arr[j - h] > key)
            {
                arr[j] = arr[j - h];
                j -= h;
            }

            // Put the key in its correct position
            arr[j] = key;
        }

        // Calculate the next value in the sequence
        h /= 3;
    }
}

template <typename T>
void shellSortSedgewick(T arr[], int n)
{
    // Calculate the increment sequence
    int inc = 1;
    while (inc < n / 3)
        inc = 3 * inc + 1;

    // Starting with the largest increment value
    while (inc >= 1)
    {
        for (int i = inc; i < n; i++)
        {
            // Insertion sort for the current increment
            T temp = arr[i];
            int j = i;
            while (j >= inc && arr[j - inc] > temp)
            {
                arr[j] = arr[j - inc];
                j -= inc;
            }
            arr[j] = temp;
        }
        inc /= 3;
    }
}


// Test program
int main()
{
    int arr1[] = { 5, 4, 3, 2, 1, 5, 5, 5, 6, 7, 5, 4, 3, 2, 1, 5, 5, 5, 6, 7, 5, 4, 3, 2, 1, 5, 5, 5, 6, 7, 5, 4, 3, 2, 1, 5, 5, 5, 6, 7, 5, 4, 3, 2, 1, 5, 5, 5, 6, 7 };
    int arr[] = { 5, 4, 3, 2, 1, 5, 5, 5, 6, 7, 5, 4, 3, 2, 1, 5, 5, 5, 6, 7, 5, 4, 3, 2, 1, 5, 5, 5, 6, 7, 5, 4, 3, 2, 1, 5, 5, 5, 6, 7, 5, 4, 3, 2, 1, 5, 5, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr1) / sizeof(arr1[0]);

    // Perform shell sort with Hibbard increment sequence
    shell_sort_hibbard(arr, n);
    shellSortSedgewick(arr1, m);

    // Print the sorted array
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    for (int i = 0; i < m; i++)
        std::cout << arr1[i] << " ";
    std::cout << "\n";
    return 0;
}