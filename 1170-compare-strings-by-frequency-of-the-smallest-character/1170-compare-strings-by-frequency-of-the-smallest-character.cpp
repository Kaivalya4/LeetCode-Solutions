class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> q;
        for(int i=0;i<queries.size();i++){
            sort(queries[i].begin(),queries[i].end());
            for(auto k:queries[i])
                cout << k ;
            
            int ans = -1;
            for(int j=0;j<queries[i].size()-1;j++){
                if(queries[i][j] != queries[i][j+1]){
                    ans = j;
                    break;
                }  
            }
            if(ans == -1){
                ans = queries[i].length();
            }
            else{
                ans++;
            }
            cout << ans << " " ;
            q.push_back(ans);
        }
        vector<int> w;
        for(int i=0;i<words.size();i++){
            sort(words[i].begin(),words[i].end());
            int ans = -1;
            for(int j=0;j<words[i].size()-1;j++){
                if(words[i][j] != words[i][j+1]){
                    ans = j;
                    break;
                }  
            }
            if(ans == -1){
                ans = words[i].length();
            }
            else{
                ans++;
            }
            w.push_back(ans);
        }
        vector<int> ans;
        sort(w.rbegin(),w.rend());
        for(int i=0;i<q.size();i++){
            int  j=0;
            while(j<w.size()){
                if(q[i]>=w[j])
                    break;
                j++;
            }
                ans.push_back(j);
        }
        return ans;
    }
};