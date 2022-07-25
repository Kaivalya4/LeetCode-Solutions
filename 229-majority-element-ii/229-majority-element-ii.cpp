class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> vec;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int ctr =0;
        for(int i=0;i<n;){
            int val = nums[i];
            ctr = 0;
            while(i<n && nums[i] == val ){
                ctr++;
                i++;
            }
            if(ctr > n/3)
                vec.push_back(val);
        }
        return vec;
    }
};