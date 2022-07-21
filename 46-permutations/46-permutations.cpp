class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &nums , map<int,bool> umap , vector<int> &sol ){
        if(sol.size() == nums.size())
        {
            ans.push_back(sol);
            return;
        }
        for(auto i:nums){
            if(umap[i] == false){
                sol.push_back(i);
                umap[i] = true;
                solve(nums,umap,sol);
                umap[i] = false;
                sol.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> sol;
        map<int,bool> umap;
        solve(nums,umap,sol);
        return ans;
    }
};