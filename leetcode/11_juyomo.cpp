// https://leetcode.com/problems/container-with-most-water/
 
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int l = 0;
            int r = height.size() - 1;
            int maxVol = 0;
    
            while (r > l) {
                int currVol = (r - l) * min(height[l], height[r]);
                if (currVol > maxVol) {
                    maxVol = currVol;
                }
    
                if (height[l] > height[r]) {
                    r--;
                } else {
                    l++;
                    // what if they are equal
                }
            }
            return maxVol;
        }
    };