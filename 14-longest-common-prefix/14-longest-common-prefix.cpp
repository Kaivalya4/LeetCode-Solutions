class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ="";
        int n =strs.size() ;
        int mins = INT_MAX;
        for(int i=0;i<n;i++)
            mins = min(mins , (int)strs[i].length());
        for(int j=0;j<mins;j++)
        {
            char letter = strs[0][j];
            for(int i=1;i<n;i++)
            {
                if(strs[i].length() != 0 && strs[i].length() - 1 >=j)
                {
                    if(strs[i][j] != letter)
                        return ans;
                }
                else{
                    cout << i << endl;
                    return ans;
                }
            }
            ans.push_back(letter);
        }
        return ans;
    }
};