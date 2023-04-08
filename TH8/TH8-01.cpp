#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // Khởi tạo bộ sinh số ngẫu nhiên
  random_device rd;
  mt19937 gen(rd());

  int n = 3;

  // Tạo vector chứa các số từ 0 đến n^2 - 1
  vector<int> nums(n * n);
  for (int i = 0; i < n * n; i++)
  {
    nums[i] = i;
  }

  // Trộn ngẫu nhiên các số trong vector
  shuffle(nums.begin(), nums.end(), gen);

  // Tạo file taci.txt và ghi dữ liệu vào
  ofstream outfile("ketthuc.txt");
  if (outfile.is_open())
  {
    // Ghi số n vào dòng đầu tiên
    outfile << n << endl;

    // Ghi các số đã trộn vào file
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        outfile << nums[i * n + j] << " ";
      }
      outfile << endl;
    }

    outfile.close();
  }
  else
  {
    cout << "Khong the mo file!" << endl;
  }

  return 0;
}
