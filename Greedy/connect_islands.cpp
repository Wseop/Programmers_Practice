#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> root;
    
    // Union-Find�� ���� root �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        root.push_back(i);
    }
    // cost�� �������� �������� ����
    sort(costs.begin(), costs.end(), cmp);
    // Kruskal Algorithm
    // ���� cost���� ����
    for (int i = 0; i < costs.size(); i++) {
        int island_a = costs[i][0];
        int island_b = costs[i][1];
        int root_before, root_after;
        // root�� �ٸ��� ����, root�� ���� ������
        if (root[island_a] != root[island_b]) {
            if (root[island_a] < root[island_b]) {
                root_before = root[island_b];
                root_after = root[island_a];
            } else {
                root_before = root[island_a];
                root_after = root[island_b];
            }
            // root���� ����� ���� ����� �ٸ� ������ root���� ��� ����
            for (int i = 0; i < n; i++) {
                if (root[i] == root_before) {
                    root[i] = root_after;
                }
            }
            answer += costs[i][2];
        }
    }
    
    return answer;
}