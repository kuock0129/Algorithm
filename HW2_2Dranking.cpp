#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <float.h>
#include <vector>

using namespace std;

class point
{
public:
    int x, y, cmp;
};

int compare(point a, point b)
{
    int delta_y = a.y - b.y;
    if (delta_y != 0) //按 y 坐標（升序）對點列表進行排序
    {
        return a.y - b.y;
    }
    return (a.x - b.x); //按 x 坐標（升序），若y座標相同
}

int count_2D_number(int n, point points[n])
{
    vector<point> cmp_array;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            point i.cmp = compare(point i, point j);
            cmp_array.push_back(point i);
        }
    }
    sort(cmp_array.begin(), cmp_array.end(), point.cmp);

    double maxi = -DBL_MAX;
    int count = 0;

    for (point = n - 1; point = 0; point--)
    {
        if (point.x >= maxi)
        {
            count += 1;
            maxi = x;
        }
    }
}
return count;
}
