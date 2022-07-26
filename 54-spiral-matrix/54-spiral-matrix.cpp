class Solution {
public:
    bool isvalid(int x , int y , int n , int m){
        if(x <0 || y<0 || x>=n || y>=m)
            return false;
        return true;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int count =0;
        int x =0 , y =0;
        int ctr =0;
        while(count <n*m){
            ans.push_back(matrix[x][y]);
            matrix[x][y] = -101;
            if(!isvalid(x+dx[ctr] , y+dy[ctr] , n , m) ||  matrix[x+dx[ctr]][y+dy[ctr]] == -101){
                ctr++;
                ctr %=4;
            }
            x = x+dx[ctr];
            y = y+dy[ctr];
            count++;
        }
        return ans;
    }
};