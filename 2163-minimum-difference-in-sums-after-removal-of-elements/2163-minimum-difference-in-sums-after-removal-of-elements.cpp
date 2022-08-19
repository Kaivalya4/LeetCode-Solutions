class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        
        priority_queue<long long> left;
        priority_queue<long long, vector<long long> , greater<long long>> right;
        
        int n = nums.size() /3;
        
        vector<long long> fleft(2*n , 0);
        vector<long long int> fright(2*n , 0);
        
        long long sum = 0;
        for(int i=0;i<2*n;i++){
            left.push(nums[i]);
            sum += nums[i];
            if(left.size() > n){
                sum -= left.top();
                left.pop();
            }
            if(left.size() == n){
                fleft[i] = sum;
            }
        }
        
        sum = 0;
        for(int i=3*n-1;i>=n;i--){
            right.push(nums[i]);
            sum += nums[i];
            if(right.size() > n){
                sum -= right.top();
                right.pop();
            }
            if(right.size() == n){
                fright[i-1] = sum;
            }
        }
        
        long long ans = 1000000000000;
        for(int i=n-1;i<2*n;i++){
            ans = min(ans, fleft[i] - fright[i]);
        }
        
        return ans;
    }
};