class Solution {
public:
    double myPow(double x, int n1) {
        if(n1 <0)
            x = 1/x;
        long long n = n1;
        n = abs(n);
        double ans = 1;
        while(n){
            if(n%2){
                n--;
                ans *= x;
            }
            x *= x;
            n /=2;
        }
        return ans;
    }
};