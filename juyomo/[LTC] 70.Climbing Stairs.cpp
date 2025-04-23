// Author: Juyoung Moon
// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int fib1 = 1;
        int fib2 = 1;

        for (int i = 1; i < n; i++) {
            int tmp = fib2;

            fib2 = fib1 + fib2;
            fib1 = tmp;
        }
        
        return fib2;
    }
};
