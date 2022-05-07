/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        for(int i=1;i<=1000;i++){
            int start = 1;
            int end = 1000;
            while(start +1 <end){
                int mid = (start + end)/2;
                int value = customfunction.f(i,mid);
                if(value == z){
                    ans.push_back({i,mid});
                    break;
                }
                else if(value > z){
                    end = mid -1;
                }
                else{
                    start = mid+1;
                }
            }
            if(customfunction.f(i,start) == z){
                ans.push_back({i,start});
            }
            if(customfunction.f(i,end) == z && start != end)
                ans.push_back({i,end});
        }
        return ans;
    }
};