class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool r = false , c = false;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0] == 0)
                c = true;
        }
        for(int j=0;j<m;j++){
            if(matrix[0][j] == 0)
                r = true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0)
                    matrix[i][0] =0 , matrix[0][j] = 0;
            }
        }
        
        /*for(auto i:matrix){
            for(auto j:i)
                cout << j <<  ' ';
            cout << endl;
        }
        cout << endl;
        */
        for(int i=1;i<n;i++){
            if(matrix[i][0] == 0)
            {
                for(int j=0;j<m;j++)
                    matrix[i][j] = 0;
            }
        }
        
        /*for(auto i:matrix){
            for(auto j:i)
                cout << j <<  ' ';
            cout << endl;
        }
        cout << endl;
        */
        for(int j=1;j<m;j++){
            if(matrix[0][j] == 0){
                for(int i=0;i<n;i++)
                    matrix[i][j] = 0;
            }
        }
        
       /* for(auto i:matrix){
            for(auto j:i)
                cout << j <<  ' ';
            cout << endl;
        }
        cout << endl;
        */
        
        if(r){
            for(int j=0;j<m;j++)
                matrix[0][j] = 0;
        }
        if(c){
            for(int i=0;i<n;i++)
                matrix[i][0] = 0;
        }
    }
};