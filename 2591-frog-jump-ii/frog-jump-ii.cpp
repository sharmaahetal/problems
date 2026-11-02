class Solution {
public:
    int maxJump(vector<int>& stones) {

        int n = stones.size();

        int ans = stones[1] - stones[0];

        for(int i = 0; i < n - 2; i++) {

            int diff = stones[i+2] - stones[i];

            ans = max(ans, diff);
        }

        return ans;
    }
};