class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        int n = nums.size() ;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(umap[target-nums[i]])
            {
                ans.push_back(umap[target-nums[i]] - 1);
                ans.push_back(i);
                break;
            }
            umap[nums[i]] = i+1;
        }
        return ans;
    }
};