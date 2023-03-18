#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function to find the maximum degree of a vertex in the graph
int maxDegree(vector<vector<int>> &graph)
{
  int max_degree = 0;
  for (int i = 0; i < graph.size(); i++)
  {
    int degree = 0;
    for (int j = 0; j < graph[i].size(); j++)
    {
      if (graph[i][j] == 1)
      {
        degree++;
      }
    }
    max_degree = max(max_degree, degree);
  }
  return max_degree;
}

// function to find the minimum unused color for a vertex
int getUnusedColor(vector<vector<int>> &graph, vector<int> &color, int vertex)
{
  // create a vector to hold the used colors for the neighbors of the vertex
  vector<bool> used(maxDegree(graph) + 1, false);
  // mark the used colors
  for (int i = 0; i < graph.size(); i++)
  {
    if (graph[vertex][i] == 1 && color[i] != -1)
    {
      used[color[i]] = true;
    }
  }
  // find the minimum unused color
  for (int i = 0; i <= maxDegree(graph); i++)
  {
    if (!used[i])
    {
      return i;
    }
  }
}

// function to color the graph using the greedy algorithm
void greedyColoring(vector<vector<int>> &graph, vector<int> &color)
{
  // initialize all vertices to be uncolored
  for (int i = 0; i < graph.size(); i++)
  {
    color[i] = -1;
  }
  // color the vertices one by one
  for (int i = 0; i < graph.size(); i++)
  {
    color[i] = getUnusedColor(graph, color, i);
  }
}

int main()
{
  // create a sample graph as an adjacency matrix
  vector<vector<int>> graph = {
      {0, 1, 1, 0},
      {1, 0, 1, 1},
      {1, 1, 0, 1},
      {0, 1, 1, 0}};
  // color the graph using the greedy algorithm
  vector<int> color(graph.size());
  greedyColoring(graph, color);
  // print the colors of the vertices
  for (int i = 0; i < graph.size(); i++)
  {
    cout << "Vertex " << i << " is colored with " << color[i] << endl;
  }
  return 0;
}