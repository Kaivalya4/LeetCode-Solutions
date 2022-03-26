class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> vec;
        int out[n];
        int in[n] ;
        for(int i=0;i<n;i++)
            out[i] = in[i] = 0;
        for(int i=0;i<edges.size();i++)
        {
            out[edges[i][0]]++;
            in[edges[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(out[i] >0 && in[i] == 0)
                vec.push_back(i);
        }
        return vec;
    }
};