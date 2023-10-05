#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <math.h>
#include <iterator>

using namespace std;

vector<int> smallrange(vector<vector<int>> &nums)
{
    //額外宣告一個數列 為範圍最大
    vector<int> v = {-100005, 100005};

    // priority_queue<T, vector<T>, cmp> pq;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    int max_val = INT_MIN;
    int n = nums.size();
    int d = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (nums[i][0] > max_val)
            max_val = nums[i][0];
        pq.push({nums[i][0], i, 0});
    }

    while (!pq.empty())
    {
        vector<int> min_vec = pq.top();
        pq.pop();
        int td = max_val - min_vec[0];
        if (td < d)
        {
            d = td;
            v = {min_vec[0], max_val};
        }
        if (min_vec[2] + 1 < nums[min_vec[1]].size())
        {
            if (nums[min_vec[1]][min_vec[2] + 1] > max_val)
                max_val = nums[min_vec[1]][min_vec[2] + 1];
            pq.push({nums[min_vec[1]][min_vec[2] + 1], min_vec[1], min_vec[2] + 1});
        }
        else
            break;
    }
    // cout<<"aaaa";
    return v;
}

int main()
{
    int k;
    cin >> k;
    int n, temp;

    vector<vector<int>> nums;
    vector<int> v;
    vector<int> answer;
    /*for (int i = 0; i < k; i++)
    {

        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }*/

    for (int i = 0; i < k; i++)
    {
        v.clear(); //每次记得clear
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        nums.push_back(v);
    }

    answer = smallrange(nums);

    // cout << "answer - | ";
    copy(answer.begin(), answer.end(),
         std::ostream_iterator<int>(cout, " "));
    cout << endl;

    // cout << z[0] << ' ' << z[1];

    return 0;
}
