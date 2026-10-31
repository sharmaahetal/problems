class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        // Paths entering a cell from the left (moving right)
        vector<vector<long long>> right(m, vector<long long>(n, 0));

        // Paths entering a cell from above (moving down)
        vector<vector<long long>> down(m, vector<long long>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                long long ways;

                // Starting position
                if (i == 0 && j == 0) {
                    ways = 1;
                }
                else {
                    ways = (right[i][j] + down[i][j]) % MOD;
                }

                // Destination reached
                if (i == m - 1 && j == n - 1) {
                    return ways;
                }

                if (grid[i][j] == 0) {

                    // Empty cell: can move in both directions

                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + ways) % MOD;
                    }

                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + ways) % MOD;
                    }

                }
                else {

                    // Mirror cell: direction gets changed

                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + right[i][j]) % MOD;
                    }

                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + down[i][j]) % MOD;
                    }
                }
            }
        }

        return 0;
    }
};