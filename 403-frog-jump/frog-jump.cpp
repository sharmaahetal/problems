class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if(stones[1] != 1){
            return false;
        }
        unordered_map<long long, int> mp;
        for(int i=0; i<n; i++){
            mp[stones[i]] = i;
        }

        vector<unordered_set<long long>> dp(n);

        dp[0].insert(0);

        for(int i=0; i<n; i++){
            for(long long k : dp[i]){
                for(long long jump = k-1; jump <= k+1; jump++){
                    if(jump <= 0){
                        continue;
                    }
                    long long nextpos = stones[i] + jump;

                    if(mp.find(nextpos) != mp.end()){
                        int nextIndex = mp[nextpos];

                        dp[nextIndex].insert(jump);
                    }
                }
            }
        }
        return !dp[n-1].empty();
    }
};