class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        for(auto i:tokens){
            string x  = i;
            if(i == "+" || i == "-" || i == "*" || i == "/")
            {
                long long second = stk.top();
                stk.pop();
                long long first = stk.top();
                stk.pop();
                if(i == "+")
                    stk.push(first+second);
                else if(i == "-")
                    stk.push(first-second);
                else if(i == "*")
                    stk.push(first*second);
                else  if(i == "/")
                    stk.push(first/second);
                continue;
            }
            long long temp = 0;
            reverse(x.begin() , x.end());
            bool neg = (x.back() == '-' ? true : false);
            if(neg)
                x.pop_back();
            while(x.size()>0){
                temp = temp * 10 + x.back() - '0';
                x.pop_back();
            }
            if(neg)
                temp =-temp;
            stk.push(temp);
        }
        return stk.top();
    }
};