// Author: Juyoung Moon
// http://boj.kr/1715
// Attempted & solved on: May 13, 2025

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int num;
    cin >> num;
    priority_queue<int> nums;
    for (int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        nums.push(-1 * tmp);
    }
    
    int res = 0;
    while (nums.size() > 1) {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        res += (a + b);
        nums.push(a + b); 
    }

    cout << res * -1;
}