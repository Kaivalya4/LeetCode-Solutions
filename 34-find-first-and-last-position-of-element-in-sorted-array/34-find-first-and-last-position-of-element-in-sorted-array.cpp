class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
       /* if(nums.size() == 0)
                return ans;
        */ans[0]  = lower_bound(nums.begin(),nums.end() , target) - nums.begin();
        ans[1] = (upper_bound(nums.begin() , nums.end() , target) - nums.begin() ) -  1;
        cout << ans[0] << ' ' << ans[1] << endl;
        if(ans[0] >= nums.size() )
            ans[0] -- ;
        if(ans[0] != -1 && nums[ans[0]] != target){
            ans[0] = ans[1] = -1;
        }
        else if(ans[1] != -1 && nums[ans[1]] != target){
            ans[1] = -1;
        }
        return ans;
    }
};