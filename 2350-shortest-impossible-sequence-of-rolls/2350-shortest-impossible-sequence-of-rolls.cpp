class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ctr =0;
        set<int> s;
        for(auto i:rolls){
            s.insert(i);
            if(s.size() == k){
                s.clear();
                ctr++;
            }
        }
        return ctr +1;
    }
};