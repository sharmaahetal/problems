class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // declare dp table
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024,false)));

        //initialize the starting cell
        dp[0][0][grid[0][0]] = true;

        // traverse every cell
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                //Skip the starting cell --> already initialized

                if(r == 0 && c == 0){
                    continue;
                }
                //process the cell value

                int v = grid[r][c];

                // transition from above --> move down
                if(r > 0){
                    for(int x=0; x<1024; x++){
                        if(dp[r-1][c][x]){
                            dp[r][c][x^v] = true;
                        }
                    }
                }
                //transition from left --> move right
                if(c > 0){
                    for(int x=0; x<1024; x++){
                        if(dp[r][c-1][x]){
                            dp[r][c][x^v] = true;
                        }
                    }
                }
            }
        }
        for(int x=0; x<1024; x++){
            if(dp[m-1][n-1][x]){
                return x;
            }
        }
        return 0;
    }
};