class Solution {
public:
    int t[2000][2000];
    int isP[2000][2000];
    string s ;
    bool isPalin(int i , int  j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(int i , int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(t[i][j] != -1)
            return t[i][j];
        /*if(isP[i][j] == -1)
        {
            isP[i][j] = isPalin(i , j);
            if(isP[i][j])
                return 0;
        }
        else if(isP[i][j])
            return 0;*/
        if(isPalin(i,j))
            return 0;
        int temp = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int l , r;
            if(isPalin(i,k)){
                r = solve(k+1,j);
            temp = min(temp , 1+r);
            }
            
        }
        return t[i][j] = temp;
    }
    int minCut(string str) {
        s = str;
        memset(t , -1 , sizeof(t));
        //memset(isP, -1 , sizeof(isP));
        return solve(0 , s.length() - 1);
    }
};