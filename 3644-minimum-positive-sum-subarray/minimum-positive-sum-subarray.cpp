class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int ans = INT_MAX;
        //choose starting index
        for(int i=0; i<n; i++){
            int sum = 0;

            //choose ending index
            for(int j=i; j<n; j++){
                //calculate running sum
                sum += nums[j];

                //calculate subarray length
                int len = j-i+1;

                //check all conditions
                if(len >= l && len <= r && sum > 0){
                    ans = min(ans, sum);
                }
            }
        }
        //no valid positive sum found
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};