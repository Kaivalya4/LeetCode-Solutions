class Solution {
public:
    void solve(int left , int right ,string a ,  int &n , int &total , vector<string> &ans){
        if(left + right == total){
            ans.push_back(a);
            return ;
        }
        if(left == right){
            solve(left+1 , right , a +'(' , n , total ,ans);
        }
        else if(left == n){
            solve(left , right + 1  , a+')' , n , total,ans);
        }
        else{
            solve(left , right + 1 , a+')' , n , total,ans);
            solve(left+1 ,  right  , a+'(' , n , total,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int total = 2*n;
        vector<string> ans;
        solve(0,0,"",n,total,ans);
        return ans;
    }
};