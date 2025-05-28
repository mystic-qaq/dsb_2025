#include <iostream>
using namespace std;
const int N = 110, M = 12;
int f[N][M];
int n, m;
int main(){
    while(cin >> n >> m){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++)
                f[i][j] = f[i-1][j-1] + f[i-1][j] + 1;
            if(f[i][m] >= n){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}