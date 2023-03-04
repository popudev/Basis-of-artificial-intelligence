#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5; // số đỉnh trên đồ thị
int graph[N][N] = {
    {0, 2, 4, 0, 0},
    {2, 0, 0, 3, 0},
    {4, 0, 0, 0, 5},
    {0, 3, 0, 0, 1},
    {0, 0, 5, 1, 0}}; // đồ thị biểu diễn các địa điểm và khoảng cách giữa chúng

void tsp()
{
  vector<int> path;               // lưu trữ đường đi
  vector<bool> visited(N, false); // đánh dấu các đỉnh đã được ghé thăm

  // Bước 1: Chọn một đỉnh bất kỳ làm điểm bắt đầu. Đặt đỉnh này là đỉnh 0.
  int current = 0;
  path.push_back(current);
  visited[current] = true;

  // Bước 2: Tìm đỉnh kế tiếp để đi đến đó bằng cách chọn đỉnh gần nhất mà chưa được ghé thăm.
  for (int i = 1; i < N; i++)
  {
    int next = -1;
    for (int j = 0; j < N; j++)
    {
      if (!visited[j] && (next == -1 || graph[current][j] < graph[current][next]))
      {
        next = j;
      }
    }
    path.push_back(next);
    visited[next] = true;
    current = next;
  }

  // Bước 3: Lặp lại bước 2 cho đến khi tất cả các đỉnh đã được ghé thăm.

  // Bước 4: Khi đã ghé thăm tất cả các đỉnh, trở lại đỉnh bắt đầu và kết thúc hành trình.
  path.push_back(0);

  // In ra đường đi và chi phí tổng cộng.
  cout << "Duong di: ";
  for (int i = 0; i < path.size(); i++)
  {
    cout << path[i] << " ";
  }
  cout << endl;
  int cost = 0;
  for (int i = 0; i < path.size() - 1; i++)
  {
    cost += graph[path[i]][path[i + 1]];
  }
  cout << "Chi phi: " << cost << endl;
}

int main()
{
  tsp();
  return 0;
}