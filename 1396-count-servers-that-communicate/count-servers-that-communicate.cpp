class Solution {
public:
    //Approach : Two-Pass Row and Column Counting 

    //Time Complexity = O(m * n) =>
    /* The first pass visits all m × n cells and updates the row and column counts for each server.
    * The second pass visits all m × n cells again and checks each server using those counts.
    * Each visit takes constant time. Two passes give O(2 × m × n) = O(m × n).
    */

    //Space Complexity = O(m + n) =>
    /* rowCount stores m entries, one per row.
    * colCount stores n entries, one per column.
    * The loop variables and answer counter take O(1) space. The input grid is excluded from extra space.
    */


    int countServers(vector<vector<int>>& grid) {
        
        //1.) Initialize grid dimensions
        int m = grid.size(); //row size
        int n = grid[0].size(); //column size

        //2.) Create two count arrays
        vector<int> rowCount(m, 0); //filled with m zeros
        vector<int> colCount(n, 0); //filled with n zeros

        //3.) Traverse the grid to count total servers
        for(int r = 0; r < m; r++){

            for(int c = 0; c < n; c++){

                if(grid[r][c] == 1){
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }

        //4.) Traverse the grid again to count communicating servers
        int ans = 0;

        for(int r = 0; r < m; r++){

            for(int c = 0; c < n; c++){

                if(grid[r][c] == 1 && (rowCount[r] > 1 || colCount[c] > 1)){
                    
                    ans++;
                }
            }
        }

        //5.) Finally Return the ans
        return ans;

    }
};