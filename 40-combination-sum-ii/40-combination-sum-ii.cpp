class Solution {
public:
    
    set<vector<int>> s;
    map<string,int> umap;
    
    int solve(int idx , string mark , vector<int>&c , int t , vector<int>&sol){
        if(t == 0){
             umap[mark] = 1;
            s.insert(sol);
            return 1;
        }
        if(idx == c.size()){
            return 2;
        }
        if(t<0)
            return 2;
        if(umap[mark])
            return umap[mark] ;
        sol.push_back(c[idx]);
        mark[c[idx]] ++;
        int ans1 = solve(idx+1,mark,c,t-c[idx],sol);
        sol.pop_back();
        mark[c[idx]] --;
        int ans2 = solve(idx+1,mark,c,t,sol);
        return umap[mark] = (ans1 == 1 || ans2 == 1 ? 1 : 2);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> sol; 
        string mark(51,'0');
        solve(0,mark,candidates,target , sol);
        for(auto t:s){
            ans.push_back(t);
        }
        return ans;
    }
};