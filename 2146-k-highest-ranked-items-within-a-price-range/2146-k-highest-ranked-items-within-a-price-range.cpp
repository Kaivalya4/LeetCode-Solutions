class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size();
        int m = grid[0].size();
    vector<vector<int>> dis;
        for(int i=0;i<n;i++)
        {
            vector<int> temp(m,0);
            dis.push_back(temp);
        }
        vector<vector<int>> vec;
        queue<pair<int,int>> q;
        dis[start[0]][start[1]] = 1;
        //unordered_map<string,int> dis;
        //dis[to_string(start[0]) +'+'+to_string(start[1])] = 0;
        q.push({start[0],start[1]});
        while(!q.empty())
        {
            //cout << 1 << endl;
            int startx = q.front().first;
            int starty = q.front().second;
            q.pop();
            if(grid[startx][starty] >=pricing[0] && grid[startx][starty] <= pricing[1] ){
                //cout << 2 << endl;
                vec.push_back({dis[startx][starty],grid[startx][starty],startx,starty});
            }
            for(int i=0;i<4;i++)
            {
                int xx = startx + dx[i];
                int yy = starty + dy[i];
                if(xx <0 || xx>=n || yy<0 || yy >=m)
                    continue;
                if(grid[xx][yy] ==0 || dis[xx][yy] >0)
                    continue;
                    dis[startx+dx[i]][starty+dy[i]] = 1 + dis[startx][starty];
                    q.push({startx+dx[i],starty+dy[i]});
            }
        }
        sort(vec.begin(),vec.end());
        vector<vector<int>> res;
        for(int i=0;i<vec.size() && i<k ;i++)
            res.push_back({vec[i][2],vec[i][3]});
        return res;
    }
};