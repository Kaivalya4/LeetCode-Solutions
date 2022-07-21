class Solution {
public:
    
    map<string,int> umap;     //using map for dp
    
    int solve(int idx , string &combi , vector<int>&c , int t , vector<int>&sol , vector<vector<int>> &ans){
		//if answer for current combination combi has  already been fourd.
        if(umap[combi]) 
            return umap[combi] ;
			
		//we found one possible answer
		//1 denotes that answer has been found
		if(t == 0){
            umap[combi] = 1;
            ans.push_back(sol);
            return 1;
        }
		
		//above condition not met and array has been exhausted then 
		//anwer not exsist for current combination combi.
		//2 denotes answer not possible .
        if(idx == c.size()){
            return umap[combi]=2;
        }
		
		//if sum of our elements increasing the target sum then return 2.
        if(t<0)
            return umap[combi]=2;
        
		//Recursion formula => Two cases possible : we will include the current element  or we will not.
		
		//we include the answer
        sol.push_back(c[idx]);
        combi[c[idx]] ++;
        int ans1 = solve(idx+1,combi,c,t-c[idx],sol , ans);
        sol.pop_back();
        combi[c[idx]] --;
		
		//we not include the answer
        int ans2 = solve(idx+1,combi,c,t,sol , ans);
		
		//if either of the case is giving us one valid answer then 1 otherwise 2.
        return umap[combi] = (ans1 == 1 || ans2 == 1 ? 1 : 2);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;   //to store final answer
        vector<int> sol;    //to store current answer
        string combi(51,'0');   //0,1,....50 i.e. size of 50
        solve(0,combi,candidates,target , sol , ans);   //first element is index
        return ans;
    }
};