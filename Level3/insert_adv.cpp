// https://programmers.co.kr/learn/courses/30/lessons/72414?language=cpp#fn1

#include <string>
#include <vector>

using namespace std;

const int MAX = (99 * 3600) + (59 * 60) + 59 + 1;

int ConvertTimeToSecond(string time) {
    int second = 0;

    second = second + (stoi(time.substr(0, 2)) * 3600);
    second = second + (stoi(time.substr(3, 2)) * 60);
    second = second + stoi(time.substr(6, 2));

    return second;
}

string ConvertSecondToString(int second) {
    string hh = "", mm = "", ss = "";

    hh = to_string(second / 3600);
    if (hh.size() == 1) hh.insert(0, "0");
    second %= 3600;
    mm = to_string(second / 60);
    if (mm.size() == 1) mm.insert(0, "0");
    ss = to_string(second % 60);
    if (ss.size() == 1) ss.insert(0, "0");

    return hh + ":" + mm + ":" + ss;
}

// play 시간을 초 단위로 계산 (ex. 3 ~ 5초 재생이면 3 ~ 4, 4 ~ 5 각각 1씩 재생된 것)
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<int> accm_play_time(MAX, 0);
    int t_play = ConvertTimeToSecond(play_time);
    int t_adv = ConvertTimeToSecond(adv_time);
    unsigned long long t_accm = 0;
    int t_start_adv = 0;

    for (int i = 0; i < logs.size(); i++) {
        int start = ConvertTimeToSecond(logs[i].substr(0, 8));
        int end = ConvertTimeToSecond(logs[i].substr(9, 8));

        for (int j = start; j < end; j++) {
            accm_play_time[j]++;
        }
    }
    for (int i = 0; i <= (t_play - t_adv); i++) {
        unsigned long long t_tmp = 0;

        for (int j = 0; j < t_adv; j++) {
            t_tmp += accm_play_time[i + j];
        }
        if (t_accm < t_tmp) {
            t_accm = t_tmp;
            t_start_adv = i;
        }
    }
    answer = ConvertSecondToString(t_start_adv);

    return answer;
}