class Solution {
public:
    int mod = 1000000007;
    int numberOfWays(string corridor) {
        int n = corridor.size();
        string x;
        int cnt = 0;
        bool start = false;
        for(int i=0;i<n;i++)
        {
            if(corridor[i] == 'S')
                cnt++;
            if(corridor[i] == 'P' && start == false)
            {
                x.push_back(corridor[i]);
            }
            else if(corridor[i] == 'S' && start == true)
            {
                x.push_back('S');
                start = false;
            }
            else if(corridor[i] == 'S' && start == false)
            {
                start = true;
            }
        }
        if(cnt ==0 || cnt%2 == 1)
            return 0;
        int left =0;
        while(x[left] != 'S')
        {
            left++;
        }
        int right = x.size() -1;
        while(x[right] != 'S')
            right--;
        long long answer =1;
        long long count = 0;
        for(int i=left ;i<=right;i++)
        {
            if(x[i] == 'S'){
                answer *= (count+1);
                answer = answer % mod;
                count=0;
                continue;
            }
            count++;
        }
        return answer;
    }
};