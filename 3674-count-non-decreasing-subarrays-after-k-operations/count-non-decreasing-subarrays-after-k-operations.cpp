class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<pair<int, int>> dq;

        long long cost = 0;
        long long ans = 0;

        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            int num = nums[i];
            int cnt = 1;

            // Merge groups whose values are smaller than nums[i]
            while (!dq.empty() && dq.back().first < num) {

                auto [val, c] = dq.back();
                dq.pop_back();

                cost += 1LL * (num - val) * c;

                cnt += c;
            }

            dq.push_back({num, cnt});

            // Remove elements from the right until cost <= k
            while (cost > k) {

                auto [val, c] = dq.front();
                dq.pop_front();

                cost -= val - nums[j];
                j--;

                if (c > 1) {
                    dq.push_front({val, c - 1});
                }
            }

            // Count valid subarrays starting at i
            ans += j - i + 1;
        }

        return ans;
    }
};

// conditions =>
// we can apply upto k operations on each subarray
// each operation can increase element by one
// we need to make our subarray non-decreasing .

// observations =>
// we can traverse forward 
// at each index we can check if this element is greater than the last one or not if it is then no need to increment
// if its lesser then we must use operations 
// okay but at some point of time when we are at some index i and we need to apply operations to make current element biggger and IT EXCEEDS 'K'

// THAT MEANS IN [0, i] ALL ELEMENTS CAN'T BE CONSIDERED FOR OUR SUBARRAY
// WE WILL HAVE TO ELIMINATE SOME ELEMENTS , AND THOSE ELEMENTS OFCOURSE WILL BE FROM START BECAUSE WE WANT MAXIMUM NO OF ARRAYS WHICH WILL END AT OUR INDEX i
// we will start removing elements till we get to TOTAL OPERATIONS <= k

// BUT THERE IS ONE HUUUUGGGEEEE PROBLEM HERE
// IF ELEMENTS ARE LESSER THAN OUR ----> MAX([0,i]) then its fine we can directly remove them by subtracting their contribution in our TOTAL OPERATIONS


// BUT BUT BUT NOT SO EASY MY FRIEND , THERE IS STILL ONE TRICK

// IF THE ELEMENT WE ARE REMOVING FROM START IS MAX([0,i]) (MORE PRECISELY THE LAST OCCURENCE OF MAX), THEN WE WILL HAVE NEW_MAX IN OUR REMAINING PART , AND OUR TOTAL_OPERATIONS CALCULATIONS (WHICH WAS BY OLD MAX) WILL BE RUINED ALSO WE WONT BE ABLE TO CALCULATE NEW TOTAL OPERATIONS.(BECAUSE FOR THAT WE WILL HAVE TO AGAIN TRAVERSE THE REMAINING ELEMENTS WHICH WILL GIVE TLE )

// so the method is actually trversing backwards instead of forward
// suppose  ......i ...... max ...... elements( turned into max )
// when we go  <-------------- this direction and even if we had to remove max, then we directly calculate total remaining operations
// BY => 
// total_operations - (contribution of each element in reaching till max)


// algorithm =>
// we use deque to store {element, (count of afterward elements converted into current element)}
// now even if we need to reduce operations , we can do it by removing elements from last and reducing their contribution by checking in "deque" in which we have stored the groups with their respective maxima's.