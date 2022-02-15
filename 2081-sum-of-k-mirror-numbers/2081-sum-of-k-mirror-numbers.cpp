class Solution {
public:
    long long getpalin(long long num , bool odd)
    {
        long long x = num;
        if(odd)
            num/=10;
        while(x)
        {
            num = num*10 + x%10;
            x /= 10;
        }
        return num;
    }
    bool isK(long long num ,long long k)
    {
        string s ;
        while(num)
        {
            s += num%k + '0';
            num/=k;
        }
        int i=0 , j = s.length() -1;
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++ , j--;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        long long x = n;
        long long ans = 0;
        for(long long i=1;x;i*=10)
        {
            for(int j=i;j<i*10 && x;j++){
                long long num1 = getpalin(j, true);
                if(isK(num1 , k))
                {
                    x--;
                    ans += num1;
                }
            }
            for(int j=i;j<i*10 && x;j++){
                long long num2 = getpalin(j, false);
                if(isK(num2 , k))
                {
                    x--;
                    ans+=num2;
                }
            }
        }
        return ans;
    }
};