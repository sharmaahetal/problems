class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int left = 0;
        int right = height.size()-1;

        while(left < right){
            int l = min(height[left], height[right]);
            int b = right - left;

            int currwater = l * b;

            maxwater = max(currwater, maxwater);

            height[left] < height[right] ? left++ : right--;
        }
        return maxwater;
    }
};