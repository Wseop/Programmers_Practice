// https://programmers.co.kr/learn/courses/30/lessons/17678?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬, 구현
// 주어진 timetable을 분단위로 변환 후 정렬
// 마지막 버스 전까지, 버스출발 시간 이전에 모인 크루들을 순서대로 태움
// 마지막 버스인 경우 
// 1. 남은 사람을 모두 태워도 자리가 남으면 -> 해당 버스의 출발 시간에 도착하면 됨
// 2. 가득 찰때까지 태워도 줄이 남아있으면 -> 마지막에 탑승한 사람보다 1분 일찍 도착하면 됨
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> time_m;
    int index_time = 0;
    int bus_time = 540;
    int last_count = 0;
    int hour, minute;

    // timetable 분단위로 변환 후 정렬
    for (string time : timetable) {
        hour = stoi(time.substr(0, 2));
        minute = stoi(time.substr(3, 2));
        time_m.push_back((hour * 60) + minute);
    }
    sort(time_m.begin(), time_m.end());

    // 마지막 버스 전까지 버스출발 시간 이전에 모인 크루들을 순서대로 태움
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (time_m[index_time] <= bus_time) index_time++;
            else break;
        }
        bus_time += t;
    }
    // 마지막 버스인 경우 처리
    for (last_count = 0; last_count < m; last_count++) {
        if (index_time >= time_m.size()) break;
        if (time_m[index_time] <= bus_time) index_time++;
        else break;
    }
    if (last_count == m) {
        bus_time = time_m[index_time - 1] - 1;
    }
    hour = bus_time / 60;
    minute = bus_time % 60;
    if (hour < 10) answer += "0";
    answer += to_string(hour);
    answer += ":";
    if (minute < 10) answer += "0";
    answer += to_string(minute);

    return answer;
}