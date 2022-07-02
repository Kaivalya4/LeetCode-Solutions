class Solution {
public:
    bool canJump(vector<int>& nums){
        int i = 0 ,  maxfar = 0;
        int currseglast =0;
        int n = nums.size();
        while(i<n){
            maxfar = max(maxfar, i + nums[i]);
            if(i == currseglast){
                currseglast = maxfar;
                if(currseglast == i && i < n-1)
                    return false;
            }
            i++;
        }
        return true;
    }
};