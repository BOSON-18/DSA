/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;
        // vector<int> ans;

        // for (int i = 0; i < asteroids.size(); i++) {
        //     int curr = asteroids[i];

           

        //     // while (!st.empty()) {
        //     //     if (curr * st.top() > 0) {
        //     //         st.push(curr);
        //     //         break;
        //     //     } else {
        //     //         if (abs(st.top()) < abs(curr)) {
        //     //             st.pop();
        //     //             if (st.empty()) {
        //     //                 st.push(curr);
        //     //                 break;
        //     //             }
        //     //         } else if (abs(st.top()) == abs(curr)) {
        //     //             st.pop();
        //     //             break;
        //     //         } else {
        //     //             break;
        //     //         }
        //     //     }
        //     // }

        //     while(!st.empty() && st.top()>0 && curr<0){
        //         if(abs(st.top())<abs(curr)){
        //             st.pop();
        //         }
        //         else if (abs(st.top())==abs(curr)){
        //             st.pop();
        //             break;
        //         }else{
        //             break;
        //         }
        //     }
            

        //      if (st.empty()) {
        //         st.push(curr);
              
        //     }
        // }

    for (int curr : asteroids) {
            bool destroyed = false;
            while (!st.empty() && curr < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(curr)) {
                    st.pop();  // Top asteroid is destroyed
                } else if (abs(st.top()) == abs(curr)) {
                    st.pop();  // Both asteroids are destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                st.push(curr);
            }
        }
        // while (!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }

        // reverse(ans.begin(), ans.end());

          vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
// @lc code=end

