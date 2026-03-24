#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        const int MOD=12345;
        vector<vector<int>> p(n, vector<int>(m));
        long long prod=1;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                p[i][j]=prod;
                prod=(prod*(grid[i][j]%MOD))%MOD;
            }
        }
        prod=1;
        for (int i=n-1;i>=0;i--) {
            for (int j=m-1;j>=0;j--) {
                p[i][j]=(p[i][j]*prod)%MOD;
                prod=(prod*(grid[i][j]%MOD))%MOD;
            }
        }
        return p;
    }
};
