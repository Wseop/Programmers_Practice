// https://programmers.co.kr/learn/courses/30/lessons/17680?language=cpp

// vector의 iterator를 활용하여 해결
// iterator로 원하는 위치의 element를 erase
// iterator로 원하는 위치에 insert

#include <string>
#include <vector>

using namespace std;

bool IsHit(vector<string>& cache, string city, vector<string>::iterator& iter) {
    for (iter = cache.begin(); iter != cache.end(); iter++) {
        if (*iter == city) return true;
    }
    return false;
}

// 1. 캐시 Hit
//      1-1. 캐시의 가장 앞이면 변동 없음
//      1-2. 그 외의 경우, erase 후 맨 앞에 insert
// 2. 캐시 Miss
//      2-2. 캐시가 Full일 경우 맨 뒤의 element를 제거
//      2-3. 맨 앞에 insert
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    // 캐시 크기가 0이면 매번 +5 해야함
    if (cacheSize == 0) {
        return cities.size() * 5;
    }
    // 전부 소문자로 변경
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].size(); j++) {
            char& c = cities[i][j];
            if (c >= 'A' && c <= 'Z') c += ('a' - 'A');
        }
    }
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        vector<string>::iterator iter;
        
        if (IsHit(cache, city, iter)) {
            if (iter != cache.begin()) {
                cache.erase(iter);
                cache.insert(cache.begin(), city);
            }
            answer += 1;
        } else {
            if (cache.size() == cacheSize) {
                cache.pop_back();
            }
            cache.insert(cache.begin(), city);
            answer += 5;
        }
    }
    
    return answer;
}