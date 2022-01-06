class TreeAncestor {
public:
    int logs[50001];
    int st[32][50001] ;
    void logvalue(int n)
    {
        logs[1] =0;
        for(int i=2;i<=n;i++)
            logs[i] = logs[i/2] +1;
    }
    TreeAncestor(int n, vector<int>& parent) {
        logvalue(n);
        memset(st,-1,sizeof(st));
        for(int i=0;i<n;i++)
            st[0][i] = parent[i];
        for(int i=1;i<=logs[n] ;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(st[i-1][j] != -1)
                {
                    int par = st[i-1][j];
                    st[i][j] = st[i-1][par];
                }
            }
        }
        /**
        for(int i=0;i<=logs[n];i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << st[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
    
    int getKthAncestor(int node, int k) {
        
        while(k>0)
        {
            //cout << st[logs[k]][node] << endl;
            if(st[logs[k]][node] == -1)
                return -1;
            node = st[logs[k]][node];
            k -= (1<<logs[k]);
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */