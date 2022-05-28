class Solution {
public:
    int reverse(int x) {
        bool mark = (x<0 ? true : false);
        x = abs(x);
        long long y = 0;
        while(x){
            y = y*10 + x%10;
            x /= 10;
        }
        if(mark)
            y = -y;
        if(y > 2147483647)
            return 0;
        if(y < -2147483648 )
            return 0;
        return y;
    }
};