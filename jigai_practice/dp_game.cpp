#include <bits/stdc++.h>
using namespace std;
int dp_max[60][60], dp_min[60][60]; 
int num[60], num_init[60];
char op[60], op_init[60];
int max4(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}
int min4(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c%d", &op_init[(i-1+n)%n], &num_init[i]);
    }
    int max_result = -1e9, max_count = 0;
    int max_index[60];  
    for (int x = 0; x < n; x++) {
        for (int i =0; i < n; i++) {
            num[i] = num_init[(x+i)%n];
            op[i] = op_init[(x+i)%n];
        }
        for (int i = 0; i < n; i++) {
            dp_max[i][i] = num[i];
            dp_min[i][i] = num[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp_max[i][j] = -1e9;
                dp_min[i][j] = 1e9;
                for (int k = i; k < j; k++) {
                    if (op[k] == 't') {
                        dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k+1][j]);
                        dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k+1][j]);
                    } else {
                        int max_max = dp_max[i][k] * dp_max[k+1][j];
                        int max_min = dp_max[i][k] * dp_min[k+1][j];
                        int min_max = dp_min[i][k] * dp_max[k+1][j];
                        int min_min = dp_min[i][k] * dp_min[k+1][j];
                        dp_max[i][j] = max(dp_max[i][j], max4(max_max, max_min, min_max, min_min));
                        dp_min[i][j] = min(dp_min[i][j], min4(max_max, max_min, min_max, min_min));
                    }
                }
            }
        } 
        if (dp_max[0][n-1] > max_result) {
            max_result = dp_max[0][n-1];
            max_count = 1;
            max_index[0] = x;
        } else if (dp_max[0][n-1] == max_result) {
            max_index[max_count] = x;
            max_count++;
        }
    }
    printf("%d\n", max_result);
    for (int i = 0; i < max_count; i++) {
        if (i) printf(" %d", max_index[i] + 1);
        else printf("%d", max_index[i] + 1);
    }
    return 0;
}