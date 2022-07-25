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
    TreeNode* solve(int &idx , int d, string &s){
        
        TreeNode* head = new TreeNode();
        if(idx >= s.length())
            return NULL;
        int idx1 = idx;
        int ctr1=0 ;
        while(s[idx1] =='-'){
            ctr1++;
            idx1++;
        }
        if(ctr1 < d){
            return NULL;
        }
        long long num = 0;
        while(s[idx1] >= '0' && s[idx1] <='9' && idx1 <s.length()){
            num = num *10ll + s[idx1] - '0';
            idx1++;
        }
        head -> val = num;
        idx = idx1;
        head -> left = solve(idx , d+1 , s);
        if(head -> left == NULL)
            return head;
        head-> right = solve(idx,d+1,s);
        return head;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        return solve(idx,0,traversal);
    }
};