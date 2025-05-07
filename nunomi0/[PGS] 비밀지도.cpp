#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;


string cal(int num){
    string s = "";
    for (int i = 0; i<n; i++) s+=" ";
    
    int tmp = 1;
    for (int i = 1; i<n; i++) tmp*=2;
    for (int i = 0; i<n; i++){
        if (num/tmp>0){
            num%=tmp;
            s[i]='#';
        }
        tmp/=2;
    }
    return s;
}

vector<string> solution(int n_, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    n=n_;
        
    for (int i = 0; i<n; i++){
        string s = "";
        for (int j = 0; j<n; j++) s+=" ";
        answer.push_back(s);
    }
        
    for (int i = 0; i<n; i++){
        string s;
        
        s = cal(arr1[i]);
        for (int j = 0; j<n; j++) if (s[j]=='#') answer[i][j]='#';
        
        s = cal(arr2[i]);
        for (int j = 0; j<n; j++) if (s[j]=='#') answer[i][j]='#';
    }
    
    return answer;
}
