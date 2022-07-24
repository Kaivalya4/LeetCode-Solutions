class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> nums1 = nums;
        nums.clear();
        int n = nums1.size() ;
        for(int i=0;i<n;i++){
            int val = nums1[i];
            nums.push_back(nums1[i]);
            while(i<n && nums1[i] == val ){
                i++;
            }
            i--;
        }
        n = nums.size();
        if(n == 1){
            return 1;
        }
        int ans = 1;
        bool vstart ;
        for(int i=1;i<n;i++){
            if(i == 1){
                if(nums[i]>nums[i-1]){
                    ans++;
                    vstart = true;
                }
                else{
                    ans++;
                    vstart = false;
                }
                continue;
            }
            if(vstart == false && nums[i]>nums[i-1]){
                ans++;
                vstart = true;
            }
            else if(vstart == true && nums[i]<nums[i-1]){
                ans++;
                vstart = false;
            }
        }
        return ans; 
    }
};