#include <bits/stdc++.h> // thư viện đại diện cho toàn bộ các thư viện trong C++
using namespace std;

const int N = 31; // hằng số kích thước ma trận

int n, m;                       // biến đếm số đỉnh và số cạnh
int d[N][N];                    // ma trận trọng số
bool vis[N];                    // mảng đánh dấu các đỉnh đã được duyệt
int ans = INT_MAX;              // kết quả
vector<int> path;               // danh sách các đỉnh đã đi qua theo thứ tự
vector<int> pathShortestLength; // danh sách các đỉnh đã đi qua voi chi phi thap nhat

void readArr()
{
  FILE *f = fopen("tsp_30.txt", "rt");
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
      cout << d[i][j] << "\t";
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

// Neu duong di chi phi thap nhat thi gan lai path duong di
int updateMin(int ans, int dist)
{
  if (dist < ans)
  {
    pathShortestLength = path;
    return dist;
  }
  return ans;
}

void dfs(int u, int cnt, int dist)
{ // hàm duyệt đệ quy
  // path.push_back(u);
  if (cnt == n)
  {                                       // nếu đã duyệt hết các đỉnh
    ans = updateMin(ans, dist + d[u][0]); // cập nhật kết quả
    return;
  }

  if (dist >= ans)
  {
    // path.pop_back();
    return; // nếu khoảng cách lớn hơn kết quả đã tìm thấy thì cắt nhánh
  }

  for (int i = 0; i < n; i++)
  { // duyệt tất cả các đỉnh
    if (vis[i])
      continue;
    vis[i] = 1;                      // đánh dấu đỉnh i đã được duyệt
    path.push_back(i);               // nếu đỉnh đã được duyệt rồi thì bỏ qua
    dfs(i, cnt + 1, dist + d[u][i]); // duyệt đỉnh i kế tiếp
    vis[i] = 0;                      // bỏ đánh dấu để duyệt các đỉnh khác
    path.pop_back();
  }
}

void tsp()
{
  vis[0] = 1;
  path.push_back(0);
  dfs(0, 1, 0);
}

int main()
{
  readArr();
  writeArr();
  tsp();

  writePathShortestLength();

  cout << "Chi phi la: " << ans << endl; // in kết quả

  return 0; // kết thúc chương trình
}