class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newinter) {
        inter.push_back(newinter);
        sort(inter.begin() , inter.end());
        vector<vector<int>> vec;
        for(int i=0;i<inter.size() ;i++){
            int x = inter[i][0];
            int y = inter[i][1];
            
            if(i==0){
                vec.push_back({x,y});
            } else {
                int x1 = vec.back()[0];
                int y1 = vec.back()[1];
                
                if(x == x1){
                    vec.back() = {x,y};
                }
                else if(x >= x1 && y <= y1){
                    continue;
                }
                else if(x >= x1 && x <= y1){
                    vec.back()[1] = max(y,y1);
                }
                else if( x > x1 && x > y1){
                    vec.push_back({x,y});
                }
            }
            
        }
        return vec;
    }
};