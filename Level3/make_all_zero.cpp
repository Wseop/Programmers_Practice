// https://programmers.co.kr/learn/courses/30/lessons/76503?language=cpp

#include <string>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

multimap<int, int> adj;

// DFS (Recursive)
// 리프노드에서 탈출하여 연산 시 int 범위를 벗어나는 case가 발생할 수 있음에 주의...
// 리프노드와 연결된 노드는 부모 뿐이므로 visited 배열을 쓰지 않고 부모인지 체크만 해주면 됨
void recur_search_tree(vector<long long>& a, int node, int parent, long long& answer) {
    auto range = adj.equal_range(node);

    for (auto itr_adj_node = range.first; itr_adj_node != range.second; itr_adj_node++) {
        int node_child = itr_adj_node->second;

        if (node_child == parent) continue;
        recur_search_tree(a, node_child, node, answer);
        answer += abs(a[node_child]);
        a[node] += a[node_child];
        a[node_child] = 0;
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    vector<long long> long_a(a.size(), 0);

    for (int i = 0; i < long_a.size(); i++) {
        long_a[i] = a[i];
    }
    for (vector<int> e : edges) {
        adj.insert({e[0], e[1]});
        adj.insert({e[1], e[0]});
    }
    recur_search_tree(long_a, 0, 0, answer);    
    if (long_a[0] != 0) answer = -1;

    return answer;
}