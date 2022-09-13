class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        int n = num.size();
        string ans ;
        int  i = 0;
        for(i=0;i<n && k;i++){
            if(i == 0){
                ans.push_back(num[i]);
                stk.push(num[i]);
                continue;
            }
            while(stk.size() > 0 && num[i] < stk.top() && k){
                stk.pop();
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
            stk.push(num[i]);
          
        }
        
        for(int j=i;j<n;j++){
            ans.push_back(num[j]);
        }
        while(k>0){
            ans.pop_back();
            k--;
        }
        if(ans.size() == 0)
            return "0";
        reverse(ans.begin() , ans.end());
        while(ans.back() == '0' && ans.size()>1){
            ans.pop_back();
        }
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};