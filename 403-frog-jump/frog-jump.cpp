class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        // first jump must be 1
        if(stones[1] != 1){
            return false;
        }
        //map stone position to its index
        unordered_map<long long, int> mp;

        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }

        // dp[i] stores all possible jump lengths with which we can reach stone i
        vector<unordered_set<long long>> dp(n);

        // starting position
        dp[0].insert(0);

        //traverse every stone
        for(int i=0; i<n; i++){
            // all possible previous jump lengths
            for(long long k : dp[i]){
                // try k-1, k and k+1

                for(long long jump = k-1; jump<=k+1; jump++){
                    if(jump <= 0){
                        continue;
                    }
                    // coalculate next positions
                    long long nextpos = stones[i] + jump;

                    // check if a stone exists there
                    if(mp.find(nextpos) != mp.end()){
                        int nextIndex = mp[nextpos];

                        //store the jup length
                        dp[nextIndex].insert(jump);
                    }
                }
            }
        }
        // check whether last stone is reachable
        return !dp[n-1].empty();
    }
};