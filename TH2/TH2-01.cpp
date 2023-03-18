#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 12;            // số lượng đỉnh tối đa của đồ thị
int n;                          // số lượng đỉnh thực tế của đồ thị
int graph[MAXN][MAXN];          // ma trận liên kết của đồ thị
bool visited[MAXN];             // danh sách các đỉnh đã đi qua
vector<int> path;               // danh sách các đỉnh đã đi qua theo thứ tự
vector<int> pathShortestLength; // danh sách các đỉnh đã đi qua voi chi phi thap nhat

void readArr()
{
  FILE *f = fopen("tsp_6.txt", "rt");
  fscanf(f, "%d", &n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      fscanf(f, "%d", &graph[i][j]);
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
      cout << graph[i][j] << "\t";
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

// Tính độ dài của đường đi dựa trên đường đi đã cho
int calculatePathLength(const vector<int> &path)
{
  int length = 0;
  for (int i = 1; i < path.size(); i++)
  {
    length += graph[path[i - 1]][path[i]];
  }
  length += graph[path.back()][path[0]];

  return length;
}

// Neu duong di chi phi thap nhat thi gan lai path duong di
int updateMin(int &shortestLength, int &length, const vector<int> &path)
{
  if (shortestLength > length)
  {
    pathShortestLength = path;
    return length;
  }
  return shortestLength;
}

// Hàm đệ quy sử dụng thuật toán quay lui để tìm kiếm đường đi
void tspUtil(int u, int depth, int &shortestLength)
{
  visited[u] = true; // đánh dấu đỉnh u đã được đi qua
  path.push_back(u); // thêm đỉnh u vào danh sách các đỉnh đã đi qua

  // Nếu đã đi qua tất cả các đỉnh
  if (depth == n)
  {
    int length = calculatePathLength(path);                   // tính độ dài của đường đi
    shortestLength = updateMin(shortestLength, length, path); // cập nhật đường đi ngắn nhất
  }
  else
  {
    // Chưa đi qua tất cả các đỉnh, tìm kiếm đỉnh kế tiếp
    for (int v = 0; v < n; v++)
    {
      if (!visited[v])
      {
        tspUtil(v, depth + 1, shortestLength); // tìm kiếm đỉnh kế tiếp
      }
    }
  }

  visited[u] = false; // bỏ đánh dấu đỉnh u đã được đi qua
  path.pop_back();    // loại bỏ đỉnh u khỏi danh sách các đỉnh đã đi qua
}

// Hàm tìm đường đi ngắn nhất sử dụng thuật toán quay lui
int tsp()
{
  int shortestLength = INT_MAX;
  tspUtil(0, 1, shortestLength);
  return shortestLength;
}

int main()
{

  readArr();
  writeArr();
  cout << "Dang tinh toan..." << endl;
  int shortestLength = tsp();
  cout << "Do dai duong di ngan nhat: " << shortestLength << endl;
  cout << "Voi duong di la: ";
  writePathShortestLength();

  return 0;
}
