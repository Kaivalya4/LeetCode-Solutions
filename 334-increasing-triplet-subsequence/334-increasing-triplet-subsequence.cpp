class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int ctr =0;
        if(nums.size() < 3){
            return false;
        }
        int maxi1 = INT_MAX;
        int maxi2 = INT_MAX;
        for(auto i:nums){
            if(i <= maxi1){
                maxi1 = i;
            }
            else if(i <=maxi2){
                maxi2 = i;
            }
            else {
                return true;
            }
        }
        return false;
    }
};