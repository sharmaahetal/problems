class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int x : nums){
            freq[x]++;
        }
        vector<vector<int>> buckets(n+1);

        for(auto it=freq.begin(); it != freq.end(); it++){
            buckets[it->second].push_back(it->first);
        }
        vector<int> res;

        for(int i=n; i>=0; i--){
            for(int num : buckets[i]){
                res.push_back(num);

                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};