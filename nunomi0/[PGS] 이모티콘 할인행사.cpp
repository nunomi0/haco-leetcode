#include <string>
#include <vector>

using namespace std;

// 이모티콘 할인율 -> 케이스마다 각각 다름 -> 재귀 완탐

int arr[10], total_plus=0, total_cost=0;

void recur(int cur, vector<vector<int>> &users, vector<int> &emoticons){
    if (cur==emoticons.size()){
        int cur_plus=0;
        int cur_cost=0;
        
        for (int i = 0; i<users.size(); i++){
            int count=0;
            
            for (int j = 0; j<emoticons.size(); j++){
                if (users[i][0]<=arr[j])
                    count+=emoticons[j]*(100-arr[j])/100;
            }
            
            if (users[i][1]<=count) cur_plus++;
            else cur_cost+=count;
        }
                
        if (total_plus==cur_plus) {
            total_cost=max(total_cost,cur_cost);
        }
        else if (total_plus<cur_plus){
            total_plus=cur_plus;
            total_cost=cur_cost;
        }
        return;
    }
    
    for (int i = 10; i<=40; i+=10){
        arr[cur]=i;
        recur(cur+1,users,emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    recur(0,users,emoticons);
    
    answer.push_back(total_plus);
    answer.push_back(total_cost);
    return answer;
}
