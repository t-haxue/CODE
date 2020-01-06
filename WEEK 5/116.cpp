/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* depth[1005];
    void dfs(Node* u, int d) {
        if (!u) return;
        if (depth[d]) depth[d]->next = u;
        depth[d] = u;
        dfs(u->left, d + 1);
        dfs(u->right, d + 1);
    }
    Node* connect(Node* root) {
        for (auto& p : depth) p = nullptr;
        dfs(root, 0);
        for (auto& p : depth)
            if (p) p->next = nullptr;
        return root;
    }
};
