/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n%2 == 0)
            return ans;
        if(n == 1)
            return {new TreeNode()};
        
        for(int i=1;i<=n-1;i+=2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            
            for(auto x:left){
                for(auto y:right){
                    TreeNode* newnode = new TreeNode();
                    newnode -> val = 0;
                    newnode -> left =x;
                    newnode -> right = y;
                    ans.push_back(newnode);
                }
            }
        }
        return ans;
    }
};