class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i-1][j-1];
            }
        }
        
       /* for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
            cout << dp[i][j] << " ";
        }
            cout << endl;
        }*/
        
        int stamp[n+1][m+1];
        memset(stamp , 0 , sizeof(stamp));
        for(int i=h;i<=n;i++){
            for(int j=w;j<=m;j++){
                if(dp[i][j] - dp[i-h][j] - dp[i][j-w] + dp[i-h][j-w] == 0){
                    stamp[i][j] = 1;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                stamp[i][j] = stamp[i-1][j] + stamp[i][j-1] - stamp[i-1][j-1] + stamp[i][j];
            }
        }
        
       /* cout << endl;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
            cout << stamp[i][j] << " ";
        }
            cout << endl;
        }*/
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int lown = min(n,i+h-1);
                int lowm = min(m,j+w-1);
                int value = stamp[lown][lowm] - stamp[i-1][lowm] - stamp[lown][j-1] + stamp[i-1][j-1];
                if(grid[i-1][j-1] == 0 && value == 0){
                    return false;
                }
            }
        }
        return true;
    }
};