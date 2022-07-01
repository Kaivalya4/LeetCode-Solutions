class Solution {
public:
    vector<int> adj[1001];
    int xors[1001] ;
    vector<int> pars;
    bool parchild[1001][1001];
    
    int dfs(int node , int par , vector<int> &nums){
        int val = nums[node];
        
        if(node != 0)
            pars.push_back(par);
        
        for(auto i:pars){
            parchild[i][node] = true;
        }
        
        for(auto i:adj[node]){
            if(i != par)
                val ^= dfs(i, node , nums);
        }
        
        if(pars.size()>0)
            pars.pop_back();
        
        xors[node] = val;
        return val;
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        for(int i=0;i<=n;i++)
            xors[i] = 0;
        
        
        int totalxor = 0;
        for(auto i:nums){
            totalxor ^= i;
        }
        
        dfs(0,-1,nums);
        
        for(int i=0;i<n;i++)
            cout << xors[i] << " ";
        cout << endl;
        long long ans = INT_MAX;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                int a1 = edges[i][0];
                int b1 = edges[i][1];
                int a2 = edges[j][0];
                int b2 = edges[j][1];
                
                if(!parchild[a1][b1])
                    swap(a1,b1);
                
                if(!parchild[a2][b2])
                    swap(a2,b2);
                
                if(!parchild[b1][b2] && !parchild[b2][b1]){
                    long long one = xors[b1];
                    long long two = xors[b2];
                    long long three = totalxor ^ xors[b1] ^ xors[b2];
                    
                    ans = min(ans , max(one,max(two,three)) - min(one,min(two,three)));
                }
                
                else if(parchild[b1][b2]){
                    long long one = xors[b2];
                    long long two = xors[b1] ^ xors[b2];
                    long long three = totalxor ^ xors[b1];
                    
                    ans = min(ans , max(one,max(two,three)) - min(one,min(two,three)));
                }
                
                else if(parchild[b2][b1]){
                    long long one = xors[b1];
                    long long two = xors[b2] ^ xors[b1];
                    long long three =totalxor ^ xors[b2];
                    
                    ans = min(ans , max(one,max(two,three)) - min(one,min(two,three)));
                }
            }
        }
        return ans;
    }
};