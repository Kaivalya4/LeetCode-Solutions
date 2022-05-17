class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        long long start = -1e9 , end = 1e9;
        long long ans = INT_MAX ;
        while(start + 1 < end) 
        {
            long long mid = (start + end)/2;
            long long glbans = 0;
            for(int i=0;i<n;i++)
            {
                /*long long l = 0 , r = n-1;
                long long ans =INT_MAX;
                while(l+1<r){
                    long long mid1 = (l+r)/2;
                    if(matrix[i][mid1] >=mid){
                        ans = min(mid1,ans);
                        r = mid1-1;
                    }
                    else{
                        l = mid1+1;
                    }
                }
                if(matrix[i][l] >=mid)
                    ans = min(ans,l);
                if(matrix[i][r] >=mid)
                    ans = min(ans,r);
                glbans += ans;*/
                long long ptr = upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
                    cout << mid << " " << ptr << endl;
                    glbans += ptr;
            }
            
            if(glbans >=k){
                ans = min(ans,mid);
                end = mid-1;
            }
            else
                start = mid+1;
        }
            long long glbans = 0;
            for(int i=0;i<n;i++)
            {
                /*long long l = 0 , r = n-1;
                long long ans =INT_MAX;
                while(l+1<r){
                    long long mid1 = (l+r)/2;
                    if(matrix[i][mid1] >=start){
                        ans = min(mid1,ans);
                        r = mid1-1;
                    }
                    else{
                        l = mid1+1;
                    }
                }
                if(matrix[i][l] >=start)
                    ans = min(ans,l);
                if(matrix[i][r] >=start)
                    ans = min(ans,r);
                glbans += ans;*/
                long long ptr = upper_bound(matrix[i].begin(),matrix[i].end(),start) - matrix[i].begin();
                    glbans += ptr;
            }
            if(glbans >= k )
                ans = min(ans, start);
        
            glbans = 0;
            for(int i=0;i<n;i++)
            {
                /*long long l = 0 , r = n-1;
                long long ans =INT_MAX;
                while(l+1<r){
                    long long mid1 = (l+r)/2;
                    if(matrix[i][mid1] >end){
                        ans = min(mid1,ans);
                        r = mid1-1;
                    }
                    else{
                        l = mid1+1;
                    }
                }
                if(matrix[i][l] >=end)
                    ans = min(ans,l);
                if(matrix[i][r] >=end)
                    ans = min(ans,r);
                glbans += ans;*/
                 long long ptr = upper_bound(matrix[i].begin(),matrix[i].end(),end) - matrix[i].begin();
                    glbans += ptr;
                    cout << ptr << endl;
            }
            
            if(glbans >= k)
                ans = min(ans,end);
        return ans;
    }
};