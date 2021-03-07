// https://programmers.co.kr/learn/courses/30/lessons/42884?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// route 범위내에 exit가 존재하면 true, 없으면 false를 return
bool isOverlap(vector<int> route, int exit) {
    if (exit >= route[0] && exit <= route[1]) {
        return true;
    } else {
        return false;
    }
}

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int num_cars = routes.size();
    int i = 1;
    int exit;
    // 진출시간이 빠른 순으로 정렬
    sort(routes.begin(), routes.end(), compare);
    exit = routes[0][1];
    while (i < num_cars) {
        // 진출시간이 overlap되는 경우는 모두 한 번에 처리 가능
        if (isOverlap(routes[i], exit)) {
            i++;
        } else {    // overlap되지 않는 경우 새 camera 설치 필요
            exit = routes[i][1];
            answer++;
        } 
    }
    
    return answer;
}