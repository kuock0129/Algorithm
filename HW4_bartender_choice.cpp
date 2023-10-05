#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int binary_search(const vector<pair<int, int>> &data, int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }

    int mid = int((low + high) / 2);
    if (key == (data[mid].first))
        return mid;
    else if (key > (data[mid].first))
    {
        low = mid + 1;
        return binary_search(data, low, high, key);
    }
    else
    {
        high = mid - 1;
        return binary_search(data, low, high, key);
    }
}

int main()
{
    int N, Q;
    cout << "請輸入Ｎ杯調酒＆Q個評審:";
    cin >> N; //輸入有Ｎ杯調酒
    cin >> Q; //輸入有Q個評審

    pair<int, int> w;
    pair<int, int> j;
    typedef vector<pair<int, int>> Wine;  // pair<int, int> //酒位置,濃度
    typedef vector<pair<int, int>> Judge; // pair<int, int> //評審位置,最低濃度

    Wine wine;
    Judge judge;

    cout << "請輸入Ｎ杯調酒:";
    for (int i = 0; i < N; i++)
    {
        while (cin >> w.first >> w.second)
        {
            wine.push_back(make_pair(w.first, w.second));
            break;
        }
    }
    cout << "請輸入Q個評審:";
    while (Q--)
    {
        while (cin >> j.first >> j.second)
        {
            judge.push_back(make_pair(j.first, j.second));
            break;
        }
    }

    sort(wine.begin(), wine.end());
    sort(judge.begin(), judge.end());

    // vector<int> data = {1, 9, 2, 7, 4, 10, 3, 8, 5, 6};
    // int key = 7;

    Wine::iterator it;
    for (it = wine.begin(); it != wine.end(); it++)
    {
        cout << it->first << "," << it->second << endl;
    }

    Judge::iterator it2;
    for (it2 = judge.begin(); it2 != judge.end(); it2++)
    {
        cout << it2->first << "," << it2->second << endl;
    }

    //
    for (it2 = judge.begin(); it2 != judge.end(); it2++)
    {
        int ret = binary_search(wine, 0, wine.size() - 1, it2->first);
        if ((it2->second) > (it->second))
        {
            cout << it2->first; //<< "," << it2->second << endl;
        }
        if (ret == -1)
            cout << "找不到\n";
        else
            cout << "找到索引值" << ret << "\n";
    }
}
