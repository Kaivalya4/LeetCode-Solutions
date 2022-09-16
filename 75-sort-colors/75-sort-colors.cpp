class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0 , start = 0 , ends = n-1 , pivot = 1;
        while(ptr<=ends){
            if(nums[ptr]<pivot){
                swap(nums[ptr] , nums[start]);
                start++ , ptr++;
            } else if(nums[ptr] > pivot){
                swap(nums[ptr] , nums[ends]);
                ends--;
            } else{
                ptr++;
            }
        }
    }
};