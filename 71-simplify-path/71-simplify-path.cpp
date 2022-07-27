class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> s;
        for(int i=0;i<path.size();){
            if(path[i] == '/'){
                while(i<n && path[i] == '/' ){
                    i++;
                }
            }
            else{
                string str;
                while(i<n && path[i] != '/' ){
                    str.push_back(path[i++]);
                }
                if(str == ".."){
                    if(s.empty() == false){
                        s.pop_back();
                    }
                }
                else if(str != "."){
                    s.push_back(str);
                }
            }
        }
        string ans;
        ans.push_back('/');
        for(auto i:s){
            ans += i;
            ans.push_back('/');
        }
        if(ans.size() >1  )
            ans.pop_back();
        return ans;
    }
};