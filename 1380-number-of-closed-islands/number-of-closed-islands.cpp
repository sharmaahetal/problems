class Solution {
    int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
public:
    bool dfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1){
            return true;
        }
        grid[r][c] = 1;

        bool closed = r != 0 && r != rows-1 && c != 0 && c != cols-1;

        for(int i=0; i<4; i++){
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            bool ngbrclosed = dfs(grid, nr, nc);
            closed = ngbrclosed && closed;
        }
        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == 0){
                    if(dfs(grid, r, c)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};