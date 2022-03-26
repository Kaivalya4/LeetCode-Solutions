class Solution {
public:
    
    vector<int> in[15];
    void solve(int node , vector<int> temp , vector<vector<int>> &sol){
        if(node == 0){
            reverse(temp.begin(),temp.end());
            sol.push_back(temp);
            return;
        }
        for(int i=0;i<in[node].size();i++){
            temp.push_back(in[node][i]);
            solve(in[node][i],temp,sol);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i=0;i<n;i++)
            in[i].clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                in[graph[i][j]].push_back(i);
            }
        }
        vector<vector<int>> sol;
        vector<int> temp;
        temp.push_back(n-1);
        solve(n-1,temp , sol);
        return sol;
    }
};  