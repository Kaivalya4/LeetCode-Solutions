class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int N = a.size();
        ///for every cycle
       for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) { //from(i,i) to (i,n-1-i) i.e top right corner of each cycle
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];  ///top left 
            a[i][j] = a[N - 1 - j][i]; //bottom left 
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j]; //bottom right
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i]; //top right
            a[j][N - 1 - i] = temp;
        }
    }
    }
};