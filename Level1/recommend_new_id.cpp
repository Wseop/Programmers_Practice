// https://programmers.co.kr/learn/courses/30/lessons/72410?language=cpp

#include <string>
#include <vector>

using namespace std;

// 4 ~ 7단계의 경우 front(), back()을 사용하면 더 간단하게 구현 가능
string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] += 'a' - 'A';
        }
    }
    // 2단계
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] >= 'a' && new_id[i] <= 'z') continue;
        else if (new_id[i] >= '0' && new_id[i] <= '9') continue;
        else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') continue;
        else new_id.erase(i--, 1);
    }
    // 3단계
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '.') {
            int erase_count = 0;
            for (int j = i + 1; j < new_id.size(); j++) {
                if (new_id[j] == '.') erase_count++;
                else break;
            }
            new_id.erase(i, erase_count);
        }
    }
    // 4단계
    if (new_id[0] == '.') new_id.erase(0, 1);
    if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);
    // 5단계
    if (new_id.size() == 0) new_id = 'a';
    // 6단계
    if (new_id.size() >= 16) new_id.erase(new_id.begin() + 15, new_id.end());
    if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);
    // 7단계
    while (new_id.size() <= 2) new_id += (new_id.back());
    // if (new_id.size() <= 2) {
    //     char last = new_id[new_id.size() - 1];
    //     while (new_id.size() < 3) {
    //         new_id.append(1, last);
    //     }
    // }

    answer = new_id;
    return answer;
}