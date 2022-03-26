class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> adj[100001];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int n = edges.size()+1;
        for(int i=1;i<=edges.size()+1;i++){
            if(adj[i].size() == n-1){
                return i;
            }
        }
        return -1;
    }
};