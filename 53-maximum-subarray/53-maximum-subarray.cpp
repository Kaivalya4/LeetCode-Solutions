class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        for(auto i:nums){
            sum += i;
            maxi = max(sum , maxi);
            if(sum<0)
                sum = 0;
        }
        return maxi;
    }
};