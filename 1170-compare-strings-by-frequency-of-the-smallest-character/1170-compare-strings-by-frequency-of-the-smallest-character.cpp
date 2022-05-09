class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fcount(11,0);
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
            fcount[ans]++;
        }
        for(int i=1;i<fcount.size();i++)
            fcount[i] += fcount[i-1];
        
        vector<int> ans1;
        for(int i=0;i<queries.size();i++){
            sort(queries[i].begin(),queries[i].end());
            
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
            ans1.push_back(fcount[10] - fcount[ans]);
        }
        
        
        return ans1;
    }
};