class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MAX, candidate2  = INT_MAX;
        int count1 = 0 , count2 =0;
        int n = nums.size();
        vector<int> sol;
        for(auto i:nums){
            if(candidate1 == i){
                count1++;
            } else if(candidate2 == i){
                count2++;
            } else if( count1 ==0){
                candidate1 = i;
                count1++;
            } else if(count2 == 0){
                candidate2 =i ;
                count2++;
            } else{
                count1-- ,count2--;
            }
            
        }
        count1 =0 , count2 =0;
        for(auto i:nums){
            if(i == candidate1)
                count1++;
            if(i == candidate2)
                count2++;
        }
        if(count1 > n/3)
            sol.push_back(candidate1);
        if(count2 > n/3 )
            sol.push_back(candidate2);
        return sol;
    }
};