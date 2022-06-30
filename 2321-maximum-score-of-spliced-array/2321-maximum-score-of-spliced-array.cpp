class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long sum1 = 0 ,sum2 =0;
        for(auto i:nums1)
            sum1 += i;
        for(auto i:nums2)
            sum2 += i;
        long long suma = 0 , maxia = nums2[0] - nums1[0];
        long long sumb = 0  , maxib = nums1[0] - nums2[0];
        
        for(int i=0;i<n;i++){
            suma += nums2[i] - nums1[i];
            maxia = max(suma , maxia);
            if(suma<0){
                suma = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            sumb += nums1[i] - nums2[i];
            maxib = max(maxib, sumb);
            if(sumb<0){
                sumb=0;
            }
        }
        
        return max(sum1+maxia , sum2+maxib);
    }
};