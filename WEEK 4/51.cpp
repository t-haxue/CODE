class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    unordered_set<int> c, p, m;
    int n;
    void dfs(int i) {
        if (i == n) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (c.find(j) == c.end() &&
                p.find(i + j) == p.end() &&
                m.find(i - j) == m.end()) {
                    board[i][j] = 'Q';
                    c.insert(j);
                    p.insert(i + j);
                    m.insert(i - j);
                    dfs(i + 1);
                    c.erase(j);
                    p.erase(i + j);
                    m.erase(i - j);
                    board[i][j] = '.';
                }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        string line;
        for (int i = 0; i < n; ++i) line.push_back('.');
        for (int i = 0; i < n; ++i)
            board.push_back(line);
        dfs(0);
        return ans;
    }
};
