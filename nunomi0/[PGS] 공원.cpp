#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.rbegin(), mats.rend());
    int answer = -1;
    
    for (int i = 0; i<park.size(); i++){
        for (int j = 0; j<park[0].size(); j++){
            for (int k = 0; k<mats.size(); k++){
                int check=1;
                for (int ii = 0; ii<mats[k]; ii++){
                    for (int jj = 0; jj<mats[k]; jj++){
                        if (i+ii<park.size() && j+jj<park[0].size()){
                            if (park[i+ii][j+jj]=="-1") continue;
                            check=0;
                            break;
                        }
                        else {
                            check=0;
                            break;
                        }
                    }
                }
                if (check) {
                    answer=max(answer,mats[k]);
                    break;
                }
            }
        }
    }
    
    return answer;
}
