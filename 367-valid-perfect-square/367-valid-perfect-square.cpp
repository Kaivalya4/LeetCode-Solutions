class Solution {
public:
    bool isPerfectSquare(int num) {
        long long start =1 , ends = num;
        while(start + 1 <ends){
            long long mid = (start + ends)/2;
            if(mid * mid  == num)
                return true;
            else if(mid * mid >num)
                ends = mid-1;
            else
                start =mid+1;
        }
        if(start * start == num)
            return true;
        if(ends * ends == num)
            return true;
        return false;
    }
};