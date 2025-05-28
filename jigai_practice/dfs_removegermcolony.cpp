#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 110
#define ND 4

/** 搜索区域 **/
int arr[MAX_N][MAX_N] = {0};
int n = 0, m = 0;

/** 搜索方向 **/
const int dr[ND] = {0, 0, 1, -1};
const int dc[ND] = {1, -1, 0, 0};

/** 移除当前菌落 **/
void removeGermColony(int r, int c)
{
    if (!arr[r][c])
        return;
    arr[r][c] = 0;
    for (int d = 0; d < ND; d++)
        removeGermColony(r + dr[d], c + dc[d]);  //dfs深搜
}

int main()
{
    int cnt = 0;
    memset(arr, 0, sizeof(arr));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)       
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (arr[i][j])                  
            {
                cnt++;
                removeGermColony(i, j); 
            }
    cout << cnt << endl;
    return 0;
}