class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<string> grid(m, string(n, '#'));

       //make the top row free
       for(int c = 0; c < n; c++){
        grid[0][c] = '.';
       }
       //make the last column free
       for(int r=1; r<m; r++){
        grid[r][n-1] = '.';
       }
       return grid;
    }
};