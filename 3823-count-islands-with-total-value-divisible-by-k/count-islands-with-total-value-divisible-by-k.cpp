class Solution {
    int dirs[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
public:
    long long dfs(vector<vector<int>> &grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0){
            return 0;
        }
        long long sum = grid[r][c];
        grid[r][c] = 0;

        for(int i=0 ; i<4; i++){
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            sum += dfs(grid, nr, nc);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        for(int r = 0; r < rows ; r++){
            for(int c = 0; c < cols ; c++){
                if(grid[r][c] > 0){
                    long long totalsum = dfs(grid, r, c);

                    if(totalsum % k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};