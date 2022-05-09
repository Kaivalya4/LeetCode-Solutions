class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> zeros;
        zeros.push_back(nums[0] == 0 ? 1 : 0);
        int n = nums.size();
        for(int i=1;i<n;i++){
            zeros.push_back(zeros[i-1]+ ( (nums[i] == 0) ? 1 : 0));
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int start = i;
            int end = n-1;
            while(start+1<end){
                int mid = (start+end)/2;
                int x = (i == 0? 0 : zeros[i-1]);
                if(zeros[mid] -x <= k){
                    ans = max(ans , mid-i+1);
                    start = mid+1;
                }
                else {
                    end = mid-1;
                }
            }
            int x = (i == 0 ? 0 : zeros[i-1]);
            if(zeros[start] -x <= k){
                    ans = max(ans , start-i+1);
                }
            if(zeros[end] - x <= k){
                ans = max(ans , end - i +1);
            }
        }
        return ans;
    }
};