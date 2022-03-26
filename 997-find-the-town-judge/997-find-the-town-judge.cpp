class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> umap;
        map<int,bool> umap1;
        for(int i=0;i<trust.size();i++){
            umap1[trust[i][0]] = true;
            umap[trust[i][1]]++;
        }
        int ans = -1;
        for(int i=1;i<=n;i++)
        {
            if(!umap1[i] && umap[i] == n-1){
                ans =i ;
            }
        }
        return ans;
    }
};