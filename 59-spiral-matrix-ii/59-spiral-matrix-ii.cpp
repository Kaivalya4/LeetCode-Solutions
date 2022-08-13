class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n , vector<int>(n,0));
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int ctr =1;
        int dir = 0;
        int x = 0 , y =0;
        while(ctr<=n*n){
            grid[x][y] = -ctr;
            int newx = x + dx[dir];
            int newy = y + dy[dir];
            if(  newx<0 || newy<0 || newx>=n || newy>=n || grid[newx][newy] <0)             {
                dir++;
                dir %= 4;
            }
            x = x + dx[dir];
            y = y + dy[dir];
            ctr++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = - grid[i][j];
            }
        }
        return grid;
    }
};