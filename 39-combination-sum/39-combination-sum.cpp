class Solution {
public:
    set<vector<int>> s;
    
    void solve(int idx , vector<int>&c , int t , vector<int>&sol){
        if(t == 0){
            s.insert(sol);
            return ;
        }
        if(idx == c.size())
            return ;
        if(t<0)
            return;
        sol.push_back(c[idx]);
        solve(idx,c,t-c[idx],sol);
        sol.pop_back();
        solve(idx+1,c,t,sol);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sol; 
        solve(0,candidates,target , sol);
        for(auto t:s){
            ans.push_back(t);
        }
        return ans;
    }
};