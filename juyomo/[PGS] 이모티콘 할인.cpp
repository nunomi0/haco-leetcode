// Author: Juyoung Moon
// https://school.programmers.co.kr/learn/courses/30/lessons/150368

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Result {
    public:
    int numSubscribers;
    int sales;
    
    Result() {
        numSubscribers = 0;
        sales = 0;
    }
    
    Result(int n, int s) {
        numSubscribers = n;
        sales = s;
    }
    
    bool betterThan(Result compareTo) {
        if (this->numSubscribers > compareTo.numSubscribers) {
            return true;
        } else if (this->numSubscribers < compareTo.numSubscribers) {
            return false;
        }
        return this->sales > compareTo.sales;
    }
};

Result getRes(const vector<vector<int>>& users, vector<int> emoticons, const vector<int>& discounts) {
    for (int i = 0; i < emoticons.size(); i++) {
        emoticons[i] = emoticons[i] * (100 - discounts[i]) / 100;
    }
    
    Result r(0, 0);
    for (int u = 0; u < users.size(); u++) {
        int costThatUserSpends = 0;
        int userBuysOver = users[u][0];
        int userMaxSpending = users[u][1];
        
        for (int e = 0; e < emoticons.size(); e++) {
            if (discounts[e] >= userBuysOver) {
                costThatUserSpends += emoticons[e];
            }
        }
        
        if (costThatUserSpends >= userMaxSpending) {
            r.numSubscribers++;
        } else {
            r.sales += costThatUserSpends;
        }
    }
    return r;
}

void increment(vector<int>& discounts) {
    for (int i = discounts.size() - 1; i >= 0; i--) {
        if (discounts[i] != 40) {
            discounts[i] += 10;
            return;
        } else {
            discounts[i] = 10;
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    int numUsers = users.size();
    int numEmots = emoticons.size();
    /*
    users
    buy if discount geq than || if spent more than
    
    emoticons
    how much each emoticon costs
    */
    vector<int> discounts(numEmots, 10);
    int counter = 0; 
    Result optimalR;
    while (counter < pow(4, numEmots)) {
        Result r = getRes(users, emoticons, discounts);
        if (r.betterThan(optimalR)) {
            optimalR = r;
        }
        increment(discounts);
        counter++;
    }
    
    return { optimalR.numSubscribers, optimalR.sales };
}
