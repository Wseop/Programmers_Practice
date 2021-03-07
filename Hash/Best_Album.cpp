// https://programmers.co.kr/learn/courses/30/lessons/42579?language=cpp

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    set<string> genre;
    multimap<int, string> totalPlays;
    
    //get genre list
    for (int i = 0; i < genres.size(); i++) {
        genre.insert(genres[i]);
    }
    //get totalPlays per genre
    for (set<string>::iterator iter = genre.begin(); iter != genre.end(); iter++) {
        string g = *iter;
        int totalP = 0;
        
        for (int i = 0; i < genres.size(); i++) {
            if (genres[i] == g) {
                totalP += plays[i];
            }
        }
        totalPlays.insert(make_pair(totalP, g));
    }
    for (multimap<int, string>::reverse_iterator iter = totalPlays.rbegin(); iter != totalPlays.rend(); iter++) {
        string g = iter->second;
        int first = 0, second = 0;
        int first_plays = 0, second_plays = 0;
        int seq = 0;
        
        //장르 내 1순위
        for (int i = 0; i < genres.size(); i++) {
            if (genres[i] == g) {
                seq++;
                if (plays[i] > first_plays) {
                    first_plays = plays[i];
                    first = i;
                }
            }
        }
        //장르 내 2순위
        if (seq > 1) {
            for (int i = 0; i < genres.size(); i++) {
                if (genres[i] == g) {
                    if (plays[i] > second_plays && i != first) {
                        second_plays = plays[i];
                        second = i;
                    }
                }
            }
        }
        answer.push_back(first);
        if (seq > 1) {
            answer.push_back(second);
        }
    }
    
    return answer;
}