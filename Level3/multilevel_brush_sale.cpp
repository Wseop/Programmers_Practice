// https://programmers.co.kr/learn/courses/30/lessons/77486?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

// 판매원을 key, 추천인을 value로 하는 map
// 판매원을 key, 총 수익을 value로 하는 map 활용
// 추천인이 없거나 추천인에게 줄 금액이 0원이 될 때까지 수익금 분배 진행
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, string> enroll_info;
    map<string, int> total;

    for (int i = 0; i < enroll.size(); i++) {
        enroll_info.insert({enroll[i], referral[i]});
        total.insert({enroll[i], 0});
    }
    for (int i = 0; i < seller.size(); i++) {
        string name = seller[i];
        int sale = amount[i] * 100;
        int me, refer;

        while ((name != "-") && (sale != 0)) {
            if ((sale / 10) < 1) {
                refer = 0;
                me = sale;
            } else {
                refer = sale / 10;
                me = sale - refer;
            }
            total[name] += me;
            name = enroll_info[name];
            sale = refer;
        }
    }
    for (string name : enroll) {
        answer.push_back(total[name]);
    }

    return answer;
}