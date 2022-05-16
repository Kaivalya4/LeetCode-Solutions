class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 0 , ends = n-1;
        while(start + 1<ends){
            int mid = (start+ ends)/2;
            if(arr[mid] >arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
                start = mid+1;
            }
            else
                ends = mid-1;
        }
        if(arr[start]<arr[ends])
            return ends;
        return start;
    }
};