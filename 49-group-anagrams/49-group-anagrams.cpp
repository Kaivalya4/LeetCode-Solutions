class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec;
        map<string,vector<string>> umap;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            umap[s].push_back(strs[i]);
        }
        for(auto &i:umap){
            vec.push_back(move(i.second));
        }
        return vec;
    }
};