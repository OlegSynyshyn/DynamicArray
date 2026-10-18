// ConsoleApplication51.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* arr;
    int size;

public:
    DynamicArray(int s) {
        size = s;
        arr = new T[size];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    void input() {
        for (int i = 0; i < size; i++) {
            cout << "Element " << i << ": ";
            cin >> arr[i];
        }
    }

    void output() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T max() {
        T m = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] > m) {
                m = arr[i];
            }
        }
        return m;
    }

    T min() {
        T m = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] < m) {
                m = arr[i];
            }
        }
        return m;
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    int search(T value) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == value) {
                return mid;
            }

            if (arr[mid] < value) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    void replace(int index, T value) {
        if (index >= 0 && index < size) {
            arr[index] = value;
        }
        else {
            cout << "Error!" << endl;
        }
    }
};

int main() {
    int n;

    cout << "Size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error!" << endl;
        return 0;
    }

    DynamicArray<int> a(n);

    a.input();

    cout << "Max: " << a.max() << endl;
    cout << "Min: " << a.min() << endl;

    a.sort();

    cout << "Sorted: ";
    a.output();

    int x;
    cout << "Find: ";
    cin >> x;

    int index = a.search(x);

    if (index != -1) {
        cout << "Index: " << index << endl;
    }
    else {
        cout << "Not found!" << endl;
    }

    int pos, value;

    cout << "Index to replace: ";
    cin >> pos;

    cout << "New value: ";
    cin >> value;

    a.replace(pos, value);

    cout << "Result: ";
    a.output();

    return 0;
}