// Author: Juyoung Moon
// https://school.programmers.co.kr/learn/courses/30/lessons/42860
// Attempted & solved: May 7, 2025

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int sum = 0;
    for (char c : name) {
        int a = abs(c - 'A');
        int b = 26 - a;
        int curr = min(a, b);
        sum += curr;
    }
    if (sum == 0) {
        return 0;
    }
    
    // find max subarray that is continguous A
    int maxA = 0;
    int maxAEndIdx = 0;
    int currA = 0;
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == 'A') {
            currA++;
        } else {
            if (currA > maxA) {
                maxA = currA;
                maxAEndIdx = i - 1;
            }
            currA = 0;
        }
    }
    
    if (currA > maxA) {
        maxA = currA;
        maxAEndIdx = name.size() - 1;
        currA = 0;
    }
    
    // no As
    if (maxA == 0) {
        sum += name.size() - 1;
        return sum;
    }
    
    // how long are the consecutive As at the end of the string
    int lastA = 0;
    for (int j = name.size() - 1; j >= 0; j--) {
        if (name[j] == 'A') {
            lastA++;
        } else {
            break;
        }
    }
    
    // how long are the substrings before and after maxASubstr
    int maxAStartIdx = maxAEndIdx - maxA + 1;
    int after = name.size() - maxAEndIdx - 1;
    int before = maxAStartIdx - 1;
    
    // which method is best?
    int alt1 = after + before + min(after, before);
    int alt2 = name.size() - 1 - lastA; // go right
    sum += min(alt1, alt2);
    
    return sum;
}
