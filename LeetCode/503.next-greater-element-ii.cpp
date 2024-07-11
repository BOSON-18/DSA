/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> st;
        vector<int> result(nums.size(),-1);

        for(int i=2*nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%nums.size()]){
                st.pop();
            }
            
            if(!st.empty()) result[i%nums.size()]=st.top();

            st.push(nums[i%nums.size()]);
        }
        return result;
    }
};
// @lc code=end

