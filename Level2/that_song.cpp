// https://programmers.co.kr/learn/courses/30/lessons/17683?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

// #이 붙은 음은 소문자로 변경 (ex. C# -> c)
string ConvertMelody(string melody) {
    int diff = 'a' - 'A';
    string result = "";
    int index = 0;
    
    while (index < melody.size()) {
        if ((index + 1) != melody.size() && melody[index + 1] == '#') {
            result += (melody[index] + diff);
            index += 2;
        } else {
            result += melody[index++];
        }
    }
    return result;
}

// musicinfo를 parsing하여 아래 vector에 저장
// parsed_info[0] = 시작시간, [1] = 종료시간, [2] = 노래제목, [3] = 멜로디정보
void ParseInfo(string info, vector<string>& parsed_info) {
    string parsed_str = "";
    
    for (int i = 0; i < info.size(); i++) {
        if (info[i] == ',') {
            parsed_info.push_back(parsed_str);
            parsed_str = "";
        } else {
            parsed_str += info[i];
        }
    }
    parsed_info.push_back(parsed_str);
}

// 멜로디 비교를 쉽게 하기 위해 #이 붙은 음은 소문자로 변경
// 멜로디 비교는 string의 substr을 사용
// multimap을 사용하여 중복 답안 처리 - max_play_time을 key로 하는 값 중 가장 첫 번째 값을 반환
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    multimap<int, string> answers;
    int max_play_time = 0;
    
    m = ConvertMelody(m);
    for (int i = 0; i < musicinfos.size(); i++) {
        vector<string> parsed_info;
        int play_time = 0;
        string played_melody = "";
        int melody_index = 0;
        
        // parsing musicinfos & #이 붙은 음 변환
        ParseInfo(musicinfos[i], parsed_info);
        parsed_info[3] = ConvertMelody(parsed_info[3]);
        
        // play time 계산
        play_time = (stoi(parsed_info[1].substr(0, 2)) - stoi(parsed_info[0].substr(0, 2))) * 60;
        play_time += stoi(parsed_info[1].substr(3, 2)) - stoi(parsed_info[0].substr(3, 2));
        // 재생시간동안 재생된 멜로디를 구함
        for (int t = 0; t < play_time; t++) {
            played_melody += parsed_info[3][melody_index++];
            melody_index %= parsed_info[3].size();
        }
        if (played_melody.size() < m.size()) continue;
        // 두 멜로디 비교하여 update
        for (int j = 0; j <= played_melody.size() - m.size(); j++) {
            if (played_melody.substr(j, m.size()) == m) {
                answers.insert({play_time, parsed_info[2]});
                max_play_time = max_play_time < play_time ? max_play_time = play_time : max_play_time = max_play_time;
            }
        }
    }
    if (answers.size() == 0) answer = "(None)";
    else answer = answers.equal_range(max_play_time).first->second;
    return answer;
}