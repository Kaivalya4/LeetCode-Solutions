class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> vec;
        for(auto i:queries){
            int x = i[0];
            int y = i[1];
            int r = i[2];
            int ctr =0;
            for(auto j:points){
                int x1 = j[0];
                int y1 = j[1];
                if( (x1-x)*(x1-x) + (y1-y)*(y1-y) <= r*r)
                    ctr++;
            }
            vec.push_back(ctr);
        }
        return vec;
    }
};