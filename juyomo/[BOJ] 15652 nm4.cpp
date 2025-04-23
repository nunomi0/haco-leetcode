// https://www.acmicpc.net/problem/15652

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void chooseKfromN(int n, int k, vector<vector<int>>& res, vector<int> curr, int idx) {
    if (curr.size() == k) {
        res.push_back(curr);
        return;
    }

    if (idx > n) {
        return;
    }
    
    chooseKfromN(n, k, res, curr, idx+1);
    curr.push_back(idx);
    chooseKfromN(n, k, res, curr, idx);
    chooseKfromN(n, k, res, curr, idx+1);
}

vector<vector<int>> removeDuplicates(vector<vector<int>> arr) {
    vector<vector<int>> res;
    if (arr.size() == 0) {
        return res;
    }

    res.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i-1]) {
            res.push_back(arr[i]);
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> res;
    chooseKfromN(n, k, res, {}, 1);
    sort(res.begin(), res.end());
    res = removeDuplicates(res);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}