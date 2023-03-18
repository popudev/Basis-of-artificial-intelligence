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
  FILE *f = fopen("tsp_12.txt", "rt");
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
