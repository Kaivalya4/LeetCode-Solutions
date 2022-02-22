class Solution {
public:
    ///initially R[i] = 1 for all i .  parent[a] = - 1 or a itself
    int par[100001];
     int R[100001];
 int finds ( int a ) {
    if ( par[a] == a )
        return a ;
    return par[a] = finds(par[a]) ;
}
 void unions(int a , int b) ///find(a) , find(b) are passed from calling function
{
     if(R[a] >= R[b])
        {
            R[a] += R[b];
            par[b] = a;
        }
        else{
            R[b] += R[a];
            par[a] = b;
        }
}
    
   static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[2] <b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        for(int i=0;i<n;i++){
            par[i] = i;
            R[i] = 1;
        }
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(firstPerson);
        sort(meetings.begin(),meetings.end(),comp);
        unions(0,firstPerson);
        int m = meetings.size();
        for(int i=0;i<m;)
        {
            int time = meetings[i][2];
            vector<int> ppl;
            while(i<m && meetings[i][2] == time)
            {
                ppl.push_back(meetings[i][0]);
                ppl.push_back(meetings[i][1]);
                int x = finds(meetings[i][0]);
                int y = finds(meetings[i][1]);
                if(x != y){
                    unions(x,y);
                }
                i++;
            }
            for(int j=0;j<ppl.size();j++)
            {
                int x = finds(ppl[j]);
                if(x != finds(0))
                    par[ppl[j]] = ppl[j] , R[ppl[j]] = 1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i != 0 && i != firstPerson)
            {
                if(finds(i) == finds(0))
                    ans.push_back(i);
            }
        }
        return ans;
    }
};