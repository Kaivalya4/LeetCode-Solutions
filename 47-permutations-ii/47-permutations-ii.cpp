class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int> &nums , int dp , vector<int> &ans){
        if(dp == (1<<nums.size()) - 1){
            s.insert(ans);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if( (dp&(1<<i)) == 0 ){
                dp ^= (1<<i);
                ans.push_back(nums[i]);
                solve(nums,dp,ans);
                ans.pop_back();
                dp ^= (1<<i);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int dp = 0;
        sort(nums.begin(),nums.end());
        vector<int> vec;
        solve(nums,dp,vec);
        vector<vector<int>> sol;
        for(auto i:s){
            sol.push_back(i);
        }
        return sol;
    }
};