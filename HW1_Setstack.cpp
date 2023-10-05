#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef set<int> Set;
map<set<int>, int> Map;
vector<set<int>> Vector;
stack<int> stk;

int ID(Set x)
{
    if (Map.count(x))
        return Map[x];
    else
    {
        Vector.push_back(x);
        Map[x] = Vector.size() - 1;
        return Map[x];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string oper;
        cin >> oper;
        if (oper == "PUSH")
            stk.push(ID(Set()));
        else if (oper == "DUP")
            stk.push(stk.top());
        else
        {
            set<int> x1 = Vector[stk.top()];
            stk.pop();
            set<int> x2 = Vector[stk.top()];
            stk.pop();

            set<int> temp;
            if (oper == "UNION")
                set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(temp, temp.begin()));
            if (oper == "INTERSECT")
                set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(temp, temp.begin()));
            if (oper == "ADD")
            {
                temp = x2;
                temp.insert(ID(x1));
            }
            stk.push(ID(temp));
        }
        cout << Vector[stk.top()].size() << endl;
    }
    // cout << "***" << endl;
    return 0;
}