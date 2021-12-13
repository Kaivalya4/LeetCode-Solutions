class Solution {
public:
    bool t[1001][1001];
    
    int countSubstrings(string s) {
        int n =s.length();
        memset(t,0,sizeof(t));
        
        int ans= 0;
        ans += n;
        for(int i=0;i<n;i++)
            t[i][i] = true;
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i] == s[i+1]){
                t[i][i+1] = true;
                ans++;
            }
        }
        
        for(int j=2;j<n;j++)
        {
            for(int i=0;i<n-j;i++)
            {
                int l=i;
                int r=i+j;
                
                if(t[l+1][r-1]  && s[l] == s[r])
                {
                    ans++;
                    t[l][r] =true;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            cout << endl;
        }
        return ans;
    }
};