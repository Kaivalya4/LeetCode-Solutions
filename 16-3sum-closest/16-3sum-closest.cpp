class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int prev = -30001;
        for(int i=0;i<nums.size();i++){
            int l = i+1 , r = n -1;
            while(l<r){
                int sum = nums[l] + nums[r];
                if(abs(target-prev) > abs(target-sum - nums[i])){
                    prev = sum+nums[i];
                }
                if(sum + nums[i] == target){
                    return sum+nums[i];  
                }
                else if(sum+ nums[i]<target){
                    l++;
                }
                else{
                    r--;
                }
            }
                        
        }
        return prev;

    }
};