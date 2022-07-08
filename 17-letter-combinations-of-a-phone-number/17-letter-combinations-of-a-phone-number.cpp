class Solution {
public:
    map<char,vector<char>> umap;
    void solve(int idx , string &digits , string&temp, vector<string> &sol){
        if(idx == digits.length()){
            sol.push_back(temp);
            return ;
        }
        
        for(auto i:umap[digits[idx]]){
            temp.push_back(i);
            solve(idx+1,digits,temp,sol);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> sol;
        if(digits.length() == 0)
            return sol;
        int ctr =0;
        for(char c='2' ; c<='9' ; c++){
            if(c=='7' || c=='9'){
                umap[c].push_back('a'+ (ctr++));
            umap[c].push_back('a'+ (ctr++));
            umap[c].push_back('a'+ (ctr++));
                umap[c].push_back('a'+ (ctr++));
                continue;
            }
            umap[c].push_back('a'+ (ctr++));
            umap[c].push_back('a'+ (ctr++));
            umap[c].push_back('a'+ (ctr++));
            
        }
        string temp;
        solve(0,digits,temp,sol);
        return sol;
    }
};