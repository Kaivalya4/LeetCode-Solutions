class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long  mins = 0;
        long maxi = 0;
        int n = diff.size() ;
        long sum =0;
        for(int i=0;i<n;i++)
        {
            sum += diff[i];
            mins = min(mins , sum);
            maxi = max(maxi , sum);
        }
        int ans = (upper - lower) - (maxi - mins) +1 ;
        if(ans <0)
            return 0;
        else return ans;
    }
};