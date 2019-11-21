class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        int n = matrix.size();
        int m = matrix[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0, nx = 0, ny = 0;
        vector<int> ans;
        bool** vis = new bool*[n];
        for (int i = 0; i < n; ++i) vis[i] = new bool[m];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                vis[i][j] = false;
        for (int i = 0; i < n * m; ++i) {
            ans.push_back(matrix[nx][ny]);
            vis[nx][ny] = true;
            int xx = nx + dx[dir];
            int yy = ny + dy[dir];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vis[xx][yy]) {
                nx = xx;
                ny = yy;
            }
            else {
                dir = (dir + 1) % 4;
                nx += dx[dir];
                ny += dy[dir];
            }
        }
        return ans;
    }
};
