// https://programmers.co.kr/learn/courses/30/lessons/17676?language=cpp

#include <string>
#include <vector>

using namespace std;

// 1. 입력 데이터 처리
// 주어진 로그에서 필요한 부분은 완료시간과 처리시간
// 계산이 쉽도록 모두 초단위로 데이터 가공
// 2. 비교
// 비교 대상이 되는 작업의 '시작시간'이 기준 시간내에 있으면 counting하면 됨
// 또한, 오름차순으로 정렬되어 있으므로 현재 로그의 '시작시간 + 1s' or '완료시간 + 1s'에 대해서만 비교하면 됨
int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<double, double>> times;     // <시작시간, 완료시간>
    
    for (string log : lines) {
        string h = log.substr(11, 2);
        string m = log.substr(14, 2);
        string s = log.substr(17, 2);
        string ms = log.substr(20, 3);
        string t_process = log.substr(24, log.size() - 25);
        
        double complete_time = stod(h)*3600 + stod(m)*60 + stod(s) + stod(ms)*0.001;
        double start_time = complete_time - stod(t_process) + 0.001;
        times.push_back({start_time, complete_time});
    }
    for (int i = 0; i < times.size(); i++) {
        double start = times[i].first;
        double end = times[i].second;
        int count = 1;
        
        for (int j = i + 1; j < times.size(); j++) {
            if ((times[j].first <= start + 1) || (times[j].first < end + 1)) count++;
        }
        answer = answer < count ? count : answer;
    }
    
    return answer;
}