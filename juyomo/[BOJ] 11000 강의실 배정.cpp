// Author: Juyoung Moon
// http://boj.kr/11000
// Attempted & solved on: May 13, 2025
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first > b.first) {
        return false;
    } else if (a.second < b.second) {
        return true;
    }
    return false;
}

int main() {
    int num;
    cin >> num;
    vector<pair<int, int>> alt;

    for (int i = 0; i < num; i++) {
        int st, ed;
        cin >> st >> ed;
        times[i] = make_pair(st, ed);
        alt.push_back(make_pair(st, +1));
        alt.push_back(make_pair(ed, -1));
    }
    
    sort(alt.begin(), alt.end(), compare);

    int counter = 0;
    int maxC = 0;
    for (int i = 0; i < alt.size(); i++) {
        counter += alt[i].second;
        if (counter > maxC) {
            maxC = counter;
        }
    }
    
    cout << maxC << endl;
}