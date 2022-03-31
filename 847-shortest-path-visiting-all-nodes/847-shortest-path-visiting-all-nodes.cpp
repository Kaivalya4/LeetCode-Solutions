class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1 && graph.front().size() ==0)
            return 0;
        int n = graph.size();
        int finalstate = (1<<n)-1;
        int ans = INT_MAX;
        map<vector<int>,bool> umap;
        queue<vector<int>> nodes;
        for(int node=0;node<n;node++)
        {
            nodes.push({node,1<<node,1});
            umap[{node,1<<node}]= true;
        }
        
            while(!nodes.empty()){
                int curr = nodes.front()[0];
                int track = nodes.front()[1];
                int tempans = nodes.front()[2];
                if(track == finalstate){
                    ans = tempans;
                    break;
                }
                nodes.pop();
                for(auto i: graph[curr]){
                    int temp_track = track;
                    temp_track = temp_track | (1<<i);
                    if(umap[{i,temp_track}] == true)
                        continue;
                    umap[{i,temp_track}] = true;
                    nodes.push({i,temp_track,tempans+1});
                }
            }
        
        return ans-1;
    }
        
};