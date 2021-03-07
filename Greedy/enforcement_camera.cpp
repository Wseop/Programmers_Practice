// https://programmers.co.kr/learn/courses/30/lessons/42884?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// route �������� exit�� �����ϸ� true, ������ false�� return
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
    // ����ð��� ���� ������ ����
    sort(routes.begin(), routes.end(), compare);
    exit = routes[0][1];
    while (i < num_cars) {
        // ����ð��� overlap�Ǵ� ���� ��� �� ���� ó�� ����
        if (isOverlap(routes[i], exit)) {
            i++;
        } else {    // overlap���� �ʴ� ��� �� camera ��ġ �ʿ�
            exit = routes[i][1];
            answer++;
        } 
    }
    
    return answer;
}