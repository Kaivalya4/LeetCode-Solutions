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
    vector<char> src ;
    vector<char> sink;
    int sr , si;
    int ctr = 0;
    void dfs(TreeNode* root , vector<char> &s )
    {
        if(root == NULL || ctr == 2)
            return;
        if(root -> val == sr)
        {
            ctr++;
            src = s;
        }
        if(root -> val == si){
            sink = s;
            ctr++;
        }
        if(ctr == 2)
            return ;
        s.push_back('L');
        dfs( root -> left , s);
        s.pop_back();
        s.push_back('R');
        dfs(root -> right , s );
        s.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<char> s;
        sr = startValue;
        si = destValue;
        dfs(root , s );
        int  i=0 , j=0;
        while(true){
            if(i== src.size() || j == sink.size())
                break;
            if(src[i] != sink[j])
                break;
            i++ , j++;
        }
        string ans;
        for(int k=i;k<src.size();k++)
            ans.push_back('U');
        for(int k=j;k<sink.size();k++)
            ans.push_back(sink[k]);
        return ans;
    }
};