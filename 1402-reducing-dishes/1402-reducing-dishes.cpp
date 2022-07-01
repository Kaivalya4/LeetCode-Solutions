class Solution {
public:
    map<pair<string,int>,bool> yes;
    map<pair<string,int>,int> umap;
    int solve(string& s , int val , int counter , int time , vector<int> &satis){
        if(counter == satis.size())
            return 0;
        if(yes[make_pair(s,val)]){
            return umap[make_pair(s,val)];
        }
        int n = satis.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1')
                continue;
            ans  =  max( ans , solve(s , val ,  counter +1 , time,satis));
            s[i] = '1';
            ans = max(ans , satis[i]*(time) + solve(s, val + satis[i]*time ,  counter+1 , time+1,satis));
            s[i] ='0';
        }
        yes[make_pair(s,val)] = true;
        return umap[make_pair(s,val)] = ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int sum =0 ;
        int prefix = 0;
        int ans = 0;
        int n = satisfaction.size();
        for(int i=n-1;i>=0;i--){
            if(sum + prefix + satisfaction[i] >= sum){
                sum = sum + prefix + satisfaction[i];
                prefix += satisfaction[i];
                cout << sum << endl;
                ans = max(ans, sum);
            }
            else{
                break;
            }
        }
        return ans;
    }
};