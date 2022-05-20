class Solution {
public:
    string longestPalindrome(string s) {
        int n =  s.length();
        bool dp[n+1][n+1];
        
        memset(dp,0,sizeof(dp));
        
        int start = 0;
        int len = 1;
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                if(len != 2){
                    start = i;
                    len = 2;
                }
            }
        }
        
        for(int j=2;j<n;j++){
            for(int i=0;i<n-j;i++){
                if(dp[i+1][i+j-1] && s[i] == s[i+j]){
                    dp[i][i+j] =true;
                    if(len < j+1){
                        len = j+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,len);
    }
};