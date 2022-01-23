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
        }/*
        if(maxi > upper)
            return 0;
        if(mins<lower)
            return 0;*/
        maxi = upper  - maxi;
        mins = lower - mins;
        if(maxi<mins)
            return 0;
        return maxi - mins +1;
    }
};