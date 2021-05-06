// https://programmers.co.kr/learn/courses/30/lessons/42892?language=cpp

// 이진트리 구현
// 예시와 같이 특정 y축에 노드가 없는 경우가 있을 수 있으므로 구현 편의를 위해 노드들을 vector에 넣음
// node들을 y값 내림차순 우선, x값 오름차순으로 정렬
// root노드를 기준으로 다음 노드부터 insert 진행, root에서부터 자기 자기를 찾아 내려가도록 한다고 생각하면 편함

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x, y, index;
    struct Node* left;
    struct Node* right;
};

bool Compare(Node& a, Node& b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

void InsertNode(Node* parent, Node* child) {
    if (parent->x > child->x) {
        if (parent->left == NULL) parent->left = child;
        else InsertNode(parent->left, child);
    } else {
        if (parent->right == NULL) parent->right = child;
        else InsertNode(parent->right, child);
    }
}

void Inorder(Node* root, vector<int>& result_in) {
    if (root != NULL) {
        result_in.push_back(root->index);
        Inorder(root->left, result_in);
        Inorder(root->right, result_in);
    }
}

void PostOrder(Node* root, vector<int>& result_post) {
    if (root != NULL) {
        PostOrder(root->left, result_post);
        PostOrder(root->right, result_post);
        result_post.push_back(root->index);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> nodes;

    for (int i = 0; i < nodeinfo.size(); i++) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        
        nodes.push_back({x, y, i + 1});
    }
    sort(nodes.begin(), nodes.end(), Compare);

    for (int i = 1; i < nodes.size(); i++) {
        InsertNode(&nodes[0], &nodes[i]);
    }

    vector<int> result_in;
    vector<int> result_post;
    Inorder(&nodes[0], result_in);
    PostOrder(&nodes[0], result_post);
    answer.push_back(result_in);
    answer.push_back(result_post);

    return answer;
}