#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int block[1000][1000]; // block的二維陣列做模擬
int position[1000];    //紀錄每一個格子目前在block當中的位置
int top[1000];         //紀錄每一堆最上層是第幾格

void init_place(int a);
void pile(int a, int b);

void init_place(int a)
{
    int box, id = position[a];
    while (block[id][top[id]] != a)
    {
        box = block[id][top[id]--];
        position[box] = box;
        block[box][++top[box]] = box;
    }
}

int temp[1000];
void pile(int a, int b) //將a和上面全部移到b上
{
    // int temp[];
    int topt = -1, id_a = position[a], id_b = position[b];
    //先將a上面元素逆序存入temp
    while (block[id_a][top[id_a]] != a)
        temp[++topt] = block[id_a][top[id_a]--];
    //置入a
    position[a] = id_b;
    block[id_b][++top[id_b]] = a;
    top[id_a]--;
    //將temp裡面元素逆序存入b
    while (topt >= 0)
    {
        position[temp[topt]] = id_b;
        block[id_b][++top[id_b]] = temp[topt--];
    }
}

int main()
{
    int N = 0, M = 0, a = 0, b = 0;
    printf("Please enter 2 interger :");
    scanf("%d%d\n", &N, &M);

    int block[N][N]; // block的二維陣列做模擬
    int position[N]; //紀錄每一個格子目前在block當中的位置
    int top[N];      //紀錄每一堆最上層是第幾格
    char oper[5], type[5];

    for (int i = 0; i < N; ++i)
    {
        block[i][0] = i;
        position[i] = i;
        top[i] = 0;
    }
    printf("Please enter operator:");
    for (int k = 0; k < M; k++)
    {
        cin >> oper;
        scanf("%d", &a);
        cin >> type;
        scanf("%d", &b);

        if (position[a] == position[b])
            continue;

        if (oper[0] == 'm')
            init_place(a);

        if (type[0] == 'o')
            init_place(b);

        pile(a, b);
    }

    for (int i = 0; i < N; ++i)
    {
        printf("%d:", i);
        int now = 0;
        while (now <= top[i])
        {
            printf("%d", block[i][now++]);
        }
        printf("\n");
    }
    return 0;
}
