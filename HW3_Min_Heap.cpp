#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

int arr[100000 + 100]; //創建minHeap array (0<n<1024)
int n;                 //輸入n個值

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void HeapifyMin(int arr[], int i, int n)
{
    int left = 2 * i;
    int right = 2 * i + 1;

    int largest = i; //最大值為root

    if (left <= n && arr[left] > arr[i])
    {
        // temp = *arr[i];
        largest = left;
        //*arr[left] = temp;
    }
    else
    {
        largest = i;
    }

    if (right <= n && arr[right] > arr[largest])
    {
        // temp = *arr[i];
        largest = right;
        //*arr[right] = temp;
    }

    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        HeapifyMin(arr, largest, n);
    }
}

void Build_minheap(int arr[], int n)
{
    for (int j = (n / 2); j >= 1; j--)
    {
        HeapifyMin(arr, j, n);
    }
}

void HeapSort(int arr[], int n)
{

    Build_minheap(arr, n); // 將array調整成Max Heap

    int size = n; // size用來記錄「目前要處理的矩陣」之長度
    for (int i = n; i > 0; i--)
    {
        swap(arr[0], arr[i]); // 將最大值放到array的最後一個位置
        size--;
        HeapifyMin(arr, 0, size); // 調整「忽略最後一個位置」的矩陣
    }
}

int main()
{

    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    //
    // cout << ("代表有N個數將要插入:");
    while (cin >> n) //輸入n個值
    {
        for (int ptr = 1; ptr <= n; ptr++)
        {
            cin >> arr[ptr]; //輸入n個值
        }

        Build_minheap(arr, n);

        for (int i = 1; i <= n; i++) //輸出minHeap
            cout << arr[i] << ' ';
        cout << '\n';

        HeapSort(arr, n);

        for (int i = 0; i < n; i++) //輸出minHeap
            cout << arr[i] << ' ';
        cout << '\n';

        return 0;
    }
}