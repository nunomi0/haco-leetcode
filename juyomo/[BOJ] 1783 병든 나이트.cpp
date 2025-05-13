// Author: Juyoung Moon
// http://boj.kr/1783
// Attempted & solved on: May 13, 2025

#include <iostream>
using namespace std;

int count(int h, int w) {
    if (w == 1 || h == 1 || w == 2 && h < 3) { return 1; }
    else if (w == 2) { return 2; }
    else if (w == 3 && h == 2) { return 2; }
    else if (w == 3 && h >= 3) { return 3; }
    else if (w == 4 && h == 2) { return 2; }
    else if (w == 4 && h == 3) { return 4; }

    // w is 5+
    if (h == 2 && w <= 6) { return 3; }
    if (h == 2) { return 4; }
    
    // h is 3+
    if (w <= 6) { return 4; }
    return w - 2;
}

int main() {
    int h, w;
    cin >> h >> w;
    cout << count(h, w) << endl;
}