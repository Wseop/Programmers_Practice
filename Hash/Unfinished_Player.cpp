// https://programmers.co.kr/learn/courses/30/lessons/42576?language=cpp

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multimap<char, string> hash_table;
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    //fill hash_table <first letter, name>
    for (vector<string>::iterator i = participant.begin(); i != participant.end(); i++) {
        hash_table.insert(pair<char, string>((*i)[0], *i));
    }
    //remove completer from hash_table
    for (vector<string>::iterator completer = completion.begin(); completer != completion.end(); completer++) {
        multimap<char, string>::iterator list = hash_table.find((*completer)[0]);
        
        while (true) {
            if (list->second.compare(*completer) == 0) {
                hash_table.erase(list);
                break;
            } else {
                list++;
            }
        }
    }
    answer = hash_table.begin()->second;
    return answer;
}