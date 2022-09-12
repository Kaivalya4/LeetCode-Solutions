class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0;i<n;i++){
            int t = i;
            bool mark = true;
            for(int j=0;j<m;j++){
                if(haystack[t] != needle[j]){
                    mark = false;
                    break;
                }
                t++;
            }
            if(mark){
                return i;
            }
        }
        return -1;
    }
};