#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m[20];
int arr[20];

void recur(int cur, int idx, string &s, vector<int> &course){
    
    // course에 해당되는 길이가 있으면 맵에 저장
    for (int i = 0; i<course.size(); i++){
        if (cur==course[i]){
            string tmp = "";
            for (int j = 0; j<cur; j++){
                tmp+=s[arr[j]];
            }
            cout << tmp << '\n';
            m[cur][tmp]++;
            break;
        }
    }
    // 더 긴 조합이 필요 없는 경우 리턴
    if (cur==course[course.size()-1]) return;
    
    // 원소의 중복 없는 조합
    for (int i = idx; i<s.length(); i++){
        arr[cur]=i;
        recur(cur+1, i+1, s, course);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    // order마다 가능한 조합 수 탐색
    for (int i = 0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        recur(0, 0, orders[i], course);
    }
    
    // 정답 문자열 리턴
    vector<string> answer;
    for (int i = 0; i < course.size(); i++) {

        // 1. 최댓값 먼저 계산
        int mx = 0;
        for (const auto& [key, value] : m[course[i]]) {
            if (value >= 2) {
                mx = max(mx, value);
            }
        }

        // 2. 최댓값과 동일한 조합만 추가
        for (const auto& [key, value] : m[course[i]]) {
            if (value == mx && value >= 2) {
                answer.push_back(key);
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
