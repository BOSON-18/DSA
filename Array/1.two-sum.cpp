/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int low=0,high=nums.size()-1;
        while(low<high){
            int sum=nums[low]+nums[high];

            if(sum==target) return {low,high};
            else if(sum>target)high--;
            else if(sum<target)low++;
        }

        return {-1,-1};


        
    }
};
// @lc code=end

