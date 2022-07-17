class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = false;
        if(dividend<0){
            neg = neg ^ true;
        }
        if(divisor<0){
            neg = neg ^ true;
        }
        bool mark = false;
        if(dividend == -2147483648)
            mark = true;
        dividend = abs(dividend);
        divisor = abs(divisor);
        /*
        every number can be expressed as power of 2.
        largest number that can be divisible by divisor below dividend is the 
        summation of (divisor << i) which is equivalent to summation of  divisor * (2 power i)  . Our answer will be summation of 2 power i .  Lets see what is this i .  
        
        
        Observation : lets say divisor is 3 and dividend is 20 .
        largest divisor below 20 is 18.
        18   = 3*(6) = 3*(4 + 2) = 3 * 4 + 3*2 = 3*(2 power 2) + 3*(2 power 1) . 
        And answer of 20/3 = 6.
        
*/
        
        long long num = 0 , q = 0;
        for(int i=30;i>=0;i--){
            if(num + abs((long long)divisor << i) <= dividend){
                num += abs(divisor << i);
                cout << (num) << endl;
                q += 1ll << i;
            }
        }
        if(neg){
            q = -q;
            if(mark && divisor == 1){
                cout << 1 << endl;
                q--;
            }
        }
        return q;
    }
};