class Solution {
public:
    
    map<int,map<int,int>> adj;
    map<int,int> in,out;
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int m = pairs.size();
        set<int> nodes;
        for(int i=0;i<m;i++){
            int u = pairs[i][0];
            int v = pairs[i][1];

            adj[u][v] = 1; 
            
            nodes.insert(u);
            nodes.insert(v);
            
            in[v]++;
            out[u]++;
        }
        
        int v1 = -1 , v2 = -1;
        for(auto i:nodes){
            if((in[i] + out[i]) & 1){  
                if(v1 == -1){
                    v1 = i;
                }
                else if(v2 == -1){
                    v2 = i;
                }
            }
        }
        
        
        stack<int> cpath;
        vector<int> epath;
        
        if(v1 != -1){
            if(out[v1]>in[v1]){
                cpath.push(v1);
                
            }
            else
                cpath.push(v2);
        }
        else{
            cpath.push(pairs[0][0]);
        }
        while(!cpath.empty()){ 
            int u = cpath.top();

            ///no edge remain to be visited.
            if(adj[u].size() == 0){
                epath.push_back(u);
                cpath.pop();
            }
            else{
                int x;
                ///chose any random unvisited edge
                for(auto i:adj[u])
                    if(i.second)
                    {
                        x = i.first;
                        break;
                    }
                adj[u].erase(x);
                cpath.push(x);
            }
        }
        
        vector<vector<int>> ans;
        for(int i = epath.size()-1;i>0;i--){
            ans.push_back({epath[i],epath[i-1]});
        }
        
        return ans;
    }
};