#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int countIslands(vector<string> &grid) {
    int m = (int)grid.size();
    if (m == 0) return 0;
    int n = (int)grid[0].size();
    int ans = 0;
    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                ++ans;
                queue<pair<int,int>> q;
                q.push({i, j});
                grid[i][j] = '0';
                while (!q.empty()) {
                    auto [r, c] = q.front(); q.pop();
                    for (auto &d : dirs) {
                        int nr = r + d[0], nc = c + d[1];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                            grid[nr][nc] = '0';
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }
    return ans;
}

//加入main()函数之后，为ACM模式，只有类的封装为力扣模式
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    // 多组测试直到 EOF
    while ( (cin >> m >> n) ) {
        vector<string> grid(m);
        // 读取每一行；若存在空格或额外符号（如 ' , [ ]），会自动忽略非 0/1 字符
        for (int i = 0; i < m; ++i) {
            string row, tok;
            // 累积到长度为 n
            while ((int)row.size() < n && (cin >> tok)) {
                for (char ch : tok) if (ch == '0' || ch == '1') row.push_back(ch);
                if ((int)row.size() >= n) break;
            }
            if ((int)row.size() != n) {
                // 若输入不规范，可在此处处理错误；这里简单截断/填充
                row.resize(n, '0');
            }
            grid[i] = row;
        }
        cout << countIslands(grid) << "\n";
    }
    return 0;
}
