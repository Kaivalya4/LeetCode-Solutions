class Solution {
public:
    unordered_map<string,int> umap;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2)== 0){
            return true;
            cout << 1 << endl;
        }
        if(s1.length() == 1)
            return s1.compare(s2) == 0;
        
        if(umap[s1+"+"+s2] !=0)
        {
            if(umap[s1+"+"+s2] == 2)
                return false;
            return true;
        }
            
        int n = s1.length();
        //bool temp = false;
        for(int k=1;k<=n-1;k++)
        {
            /*
            temp = temp || (isScramble(s1.substr(0,k) , s2.substr(0,k)) && isScramble(s1.substr(k,n-k) , s2.substr(k,n-k)) );
            temp = temp || (isScramble(s1.substr(0,k) , s2.substr(n-k,k)) && isScramble(s1.substr(k,n-k) , s1.substr(0,n-k)) ); 
            */
            if(isScramble(s1.substr(0,k) , s2.substr(0,k)) && isScramble(s1.substr(k,n-k) , s2.substr(k,n-k)) )
                return umap[s1+"+"+s2] = 1;
            if(isScramble(s1.substr(0,k) , s2.substr(n-k,k)) && isScramble(s1.substr(k,n-k) ,s2.substr(0,n-k)))
                return umap[s1+"+"+s2] = 1;
        }
        //return temp;
        umap[s1+"+"+s2] = 2;
        return false;
    }
};