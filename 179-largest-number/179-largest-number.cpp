class Solution {
public:
    static bool comp(string &a , string &b){
        if(a+b<=b+a){
            return false;
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        string ans;
        for(auto i:nums){
            string s;
            int x = i;
            if(x == 0){
                vec.push_back("0");
                continue;
            }
            while(x){
                s.push_back(x%10+'0');
                x /= 10;
            }
            reverse(s.begin() , s.end());
            vec.push_back(s);
        }
        
        for(auto i:vec)
            cout << i <<  " " ;
        cout << endl;

        sort(vec.begin() , vec.end() , comp);
        for(auto i:vec){
            ans += i;
        }
        if(ans.front() == '0'){
            return "0";
        }
        return ans;
    }
};