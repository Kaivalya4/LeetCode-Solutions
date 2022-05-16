class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ctr =0;
        for(auto i:arr1){
            bool mark = false;
            for(auto j:arr2){
                if(abs(i-j)<=d){
                    mark = true;
                    break;
                }
            }
            if(!mark)
                ctr++;
        }
        return ctr;
    }
};