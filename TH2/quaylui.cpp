#include <bits/stdc++.h> // thư viện đại diện cho toàn bộ các thư viện trong C++
using namespace std;

const int N = 15; // hằng số kích thước ma trận

int n, m;                       // biến đếm số đỉnh và số cạnh
int d[N][N];                    // ma trận trọng số
int vis[N];                     // mảng đánh dấu các đỉnh đã được duyệt
int path[N];                    // lưu trữ đường đi tạm thời
int ans = INT_MAX;              // kết quả
vector<int> pathShortestLength; // danh sách các đỉnh đã đi qua voi chi phi thap nhat

void readArr()
{
    FILE *f = fopen("tsp_6.txt", "rt");
    fscanf(f, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &d[i][j]);
        }
    }

    fclose(f);
}

void writeArr()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%8d", d[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void writePathShortestLength()
{
    for (int i = 0; i < pathShortestLength.size(); i++)
    {
        cout << pathShortestLength[i] << " --> ";
    }
    cout << pathShortestLength[0] << endl;
}

void dfs(int u, int cnt, int dist)
{ // hàm duyệt đệ quy
    if (cnt == n)
    {                                   // nếu đã duyệt hết các đỉnh
        ans = min(ans, dist + d[u][1]); // cập nhật kết quả
        return;
    }

    for (int i = 0; i < n; i++)
    { // duyệt tất cả các đỉnh
        if (vis[i])
            continue;                    // nếu đỉnh đã được duyệt rồi thì bỏ qua
        path[cnt] = i;                   // lưu trữ đỉnh vào đường đi tạm thời
        vis[i] = 1;                      // đánh dấu đỉnh i đã được duyệt
        dfs(i, cnt + 1, dist + d[u][i]); // duyệt đỉnh i kế tiếp
        vis[i] = 0;                      // bỏ đánh dấu để duyệt các đỉnh khác
    }
}

int main()
{
    readArr();
    writeArr();

    vis[1] = 1;   // bắt đầu từ đỉnh 1
    path[0] = 1;  // lưu trữ đỉnh 1 vào đường đi
    dfs(1, 1, 0); // duyệt đỉnh 1

    cout << ans << endl; // in kết quả

    return 0; // kết thúc chương trình
}