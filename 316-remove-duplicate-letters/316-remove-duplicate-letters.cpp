class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> q; ///stack
        map<char,int> umap;  ///to count the number of each character
        map<char,bool> present;  //to know wether a character is present in our current ans or not.
        for(auto i:s){
            umap[i]++;
        }
        for(auto i:s){
            if(q.empty()){
                q.push_back(i);
                present[i] = true;
                umap[i]--;
                continue;
            }
            while(q.size() > 0 && i<q.back() && umap[q.back()] && present[i] == false){
                present[q.back()] = false;
                q.pop_back();
                
            }
            if(present[i] == false){
                q.push_back(i);
                umap[i]--;
                present[i] = true;
            }
            else{
                umap[i] --;
            }
        }
        string ans;
        for(auto i:q){
            ans.push_back(i);
        }
        return ans;
    }
};