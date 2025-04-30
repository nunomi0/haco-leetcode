// Author: Juyoung Moon
// Attempted & solved on Wed, Apr 30.
// https://school.programmers.co.kr/learn/courses/30/lessons/17681

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string numToStr(int n, int expectedSize) {
    string res = "";
    while ( n > 0 ) {
        if (n % 2 == 1) {
            res = "#" + res;
        } else {
            res = " " + res;
        }
        n /= 2;
    }
    
    while (res.size() < expectedSize) {
        res = " " + res;
    }
    return res;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        int num1 = arr1[i];
        int num2 = arr2[i];
        int res = num1 | num2;
        cout << res << endl;
        answer.push_back(numToStr(res, n));
    }
    return answer;
}
