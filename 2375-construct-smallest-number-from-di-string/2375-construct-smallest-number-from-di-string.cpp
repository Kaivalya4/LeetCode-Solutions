class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> stk;
        stk.push(1);
        int ctr = 2;
        int n = pattern.size();
        for(int i=0;i<n;i++){
            if(pattern[i] == 'I')
                stk.push(ctr);
            else{
                int ptr = i;
                stack<int> stk2;
                while(stk.size()>0 && pattern[ptr] == 'D'){
                    stk2.push(stk.top());
                    stk.pop();
                    ptr--;
                }
                stk.push(ctr);
                while(!stk2.empty() )
                {
                    stk.push(stk2.top());
                    stk2.pop();
                }
            }    
            ctr++;
        }
        string ans;
        while(stk.empty() == false){
            ans.push_back(stk.top() + '0');
            stk.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};