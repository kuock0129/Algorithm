#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int inverse_count(int Arr[], int size, int front, int end);
int merge(int Arr[], int front, int end);

// Main Function
int inverse_count(int Arr[], int size, int front, int end)
{
    front = Arr[0];
    end = Arr[size - 1];
    int inverse_number = 0;

    if (front < end)
    {
        int mid = (front + end) / 2;
        inverse_number += inverse_count(Arr, (size / 2), front, mid - 1);
        inverse_number += inverse_count(Arr, (size / 2), mid, end);

        inverse_number += merge(Arr, front, end);
    }

    return inverse_number;
}

// Sub Function
int merge(int Arr[], int front, int end)
{
    int i, j, k;
    int inverse_countNum = 0;
    int temp[end - front + 1];
    int mid = (front + end) / 2;
    i = front;
    j = mid;
    k = front;

    while ((i <= mid - 1) && (j <= end))
    {
        if (Arr[i] <= Arr[j])
        {
            temp[k++] = Arr[i++];
        }
        else
        {
            temp[k++] = Arr[j++];
            inverse_countNum = inverse_countNum + (mid - i);
        }
    }
    while ((i <= mid - 1))
    {
        temp[k++] = Arr[i++];
    }
    while ((j <= end))
    {
        temp[k++] = Arr[j++];
    }

    for (int m = front; m <= end; m++)
    {
        Arr[m] = temp[m];
    }

    return inverse_countNum;
}

int main()
{
    int Arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int ans = inverse_count(Arr, n, 0, n - 1);
    cout << " Number of inversions are " << ans;
    return 0;
}