
/**
 * start代表上一次迴圈執行到的位置,k代表填到第幾格
 * 相當於for-loop 中  i < j < k 的算法
 */
void combination(char data[], int n, int r, int start, int k, char *bag)
{
    if (k == r)
    { // 0 到 r-1 = 已經填了 r 格
        print_data(++count, bag, r);
        return;
    }
    // C(n,r)次
    for (int i = start; i < n; i++)
    {
        bag[k] = data[i];
        // 每下一次遞迴，loop會從i+1開始
        combination(data, n, r, i + 1, k + 1, bag);
    }
}

/**
 * 不可重複拿取的組合
 * n是陣列長度, r是選取數
 * 時間複雜度應為C(n,r)=O(n!)
 */
void combination(char data[], int n, int r)
{
    printf("Combination(%d,%d)\n", n, r);
    count = 0; // 紀錄組合次數
    char *bag = new char[r];
    combination(data, n, r, 0, 0, bag);
    delete[] bag;
}