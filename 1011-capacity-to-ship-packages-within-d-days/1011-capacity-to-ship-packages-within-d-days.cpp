class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN , sum = 0;
        for(auto i:weights){
            sum += i;
            maxi = max(maxi , i);
        }
        int start = maxi , end = sum;
        int ans = sum;
        int n = weights.size();
        while(start +1 <end){
            int mid = (start+end)/2;
            int ctr = 0;
            int temp = INT_MIN;
            int temps = 0;
            for(int i=0;i<weights.size();i++){
                if(i == n-1){
                    if(temps + weights[i] > mid)
                    {
                        ctr += 2;
                        temp = max(temp , temps);
                        temp = max(temp , weights[i]);
                    }
                    else{
                        ctr ++;
                        temp = max(temp , temps+weights[i]);
                    }
                }
                else if(temps + weights[i] >mid){
                    temp = max(temp , temps);
                    temps = weights[i];
                    ctr++;
                }
                else{
                    temps += weights[i];
                }
            }
            if(ctr > days){
                start = mid+1;
            }
            else{
                end = mid-1;
                ans = min(ans,temp);
            }
        }
        cout << start << " " << end << endl; 
        int ctr = 0;
            int temp = INT_MIN;
            int temps = 0;
            for(int i=0;i<weights.size();i++){
                if(i == n-1){
                    if(temps + weights[i] > start)
                    {
                        ctr += 2;
                        temp = max(temp , temps);
                        temp = max(temp , weights[i]);
                    }
                    else{
                        ctr ++;
                        temp = max(temp , temps+ weights[i]);
                    }
                    
                }
                else if(temps + weights[i] >start){
                    temp = max(temp , temps);
                    temps = weights[i];
                    ctr++;
                }
                else{
                    temps += weights[i];
                }
            }
        if(ctr <= days){
            ans = min(ans , temp);
        }
        ctr = 0;
            temp = INT_MIN;
            temps = 0;
            for(int i=0;i<weights.size();i++){
                if(i == n-1){
                    if(temps + weights[i] > end)
                    {
                        ctr += 2;
                        temp = max(temp , temps);
                        temp = max(temp , weights[i]);
                    }
                    else{
                        ctr ++;
                        temp = max(temp , temps+weights[i]);
                    }
                }
                else if(temps + weights[i] >end){
                    temp = max(temp , temps);
                    temps = weights[i];
                    ctr++;
                }
                else{
                    temps += weights[i];
                }
            }
        if(ctr <= days){
            ans = min(ans , temp);
        }
        return ans;
    }
};