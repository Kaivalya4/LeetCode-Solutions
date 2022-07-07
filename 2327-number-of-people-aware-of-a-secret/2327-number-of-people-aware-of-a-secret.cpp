class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long days =2;
        long long mod = 1000000007;
        vector<array<long long,3>> q;
        q.push_back({1+delay,1+forget,1});
        while(days<=n){
            while(!q.empty() && q[0][1] ==days){
                q.erase(q.begin());
            }
            long long cnt =0;
            for(auto x:q){
                if(x[0] <= days)
                    cnt = cnt +  x[2] %mod;
            }
            
            q.push_back({days+delay,days+forget,cnt});
            days++;
        }
        long long ans =0;
        for(auto x:q){
            ans += x[2];
            ans %= mod;
        }
        return ans;
    }
};