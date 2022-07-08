class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool vis[21][21] ;
    int dp[21][21];
    int count =0;
    int  n , m;
    int solve(int sx , int sy , int &ex , int &ey , int ctr , vector<vector<int>>&grid){
        if(sx == ex && sy == ey){
            if(ctr-1 == count)
                return 1;
            return 0;
        }
        vis[sx][sy] = true;
        int ans =0;
        for(int i=0;i<4;i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if( !(nx<0 || ny<0 || nx>=n || ny >= m || grid[nx][ny] == -1 || vis[nx][ny])){
                ans += solve(nx , ny , ex , ey ,ctr+1, grid);
            }
        }
        vis[sx][sy] =false;
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx , sy;
        int ex , ey;
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j] = false;
                if(grid[i][j] == 1){
                    sx = i , sy = j;
                }
                else if(grid[i][j] == 2){
                    ex = i , ey = j;
                }
                else if(grid[i][j] == 0){
                    count ++;
                }
            }
        }
        int ctr =0;
        return solve(sx , sy , ex , ey ,ctr , grid);
    }
};