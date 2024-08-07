class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
          int minLenWindow = INT_MAX;
        int currentSum = 0;
        int low = 0;
        int high = 0;

        while(high < nums.size()) {
            currentSum += nums[high];
            high++;

            while(currentSum >= target) {
                int currentWindowSize = high - low;
                minLenWindow = min(minLenWindow, currentWindowSize);

                currentSum -= nums[low];
                low++;
            }
        }

        return minLenWindow == INT_MAX ? 0 : minLenWindow;
    }
};