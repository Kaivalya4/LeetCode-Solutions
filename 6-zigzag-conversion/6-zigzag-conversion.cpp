    
                    
           
        
   
class Solution {
public:
     string convert(string s, int numRows) {
        if(numRows == 1 || numRows == s.length())
            return s;
        vector<vector<char>> vec(numRows,vector<char>(s.length(),'1')) ; 
        int i=0 , j=0;
        int itr =0;
        int n = s.length();
         while(true){
            while(itr <n && i<numRows){
                vec[i++][j] = s[itr++];
            }
            if(itr == n)
                break;
            i = numRows-2;
            j++;
            while(i>=0 && itr<n){
                
                vec[i--][j++] = s[itr++];
            }
             
            if(itr == n)
                break;
             i= 1;
        }
         
        string ans;
         for(auto i:vec){
             for(auto j:i){
                
                if(j != '1')
                    ans.push_back(j);
            }
        }
         return ans;
     }
};