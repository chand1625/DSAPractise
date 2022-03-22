#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
  int stairs;
  int k;
  vector<int> heights;
  vector<int> dp;

public:
  Solution(int stairs, int k, vector<int> &heights) : stairs(stairs), k(k), heights(heights)
  {
    dp.resize(stairs, -1);
  };
  int frogJump(int);
};

int Solution::frogJump(int stair)
{
  if (stair == 0)
    return 0;

  if (dp[stair] != -1)
    return dp[stair];

  int step = INT_MAX;

  for (int i = 1; i <= k; i++)
  {
    if ((stair - i) >= 0)
    {
      step = min(step, frogJump(stair - i) + abs(heights[stair - i] - heights[stair]));
    }
  }

  dp[stair] = step;
  return dp[stair];
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int testCases;
  cin >> testCases;

  for (int i = 0; i < testCases; i++)
  {
    int stairs;
    cin >> stairs;
    vector<int> heights(stairs);
    for (int i = 0; i < stairs; i++)
    {
      cin >> heights[i];
    }
    int k;
    cin >> k;

    Solution s(stairs, k, heights);
    int minEnergy = s.frogJump(stairs - 1);

    cout << "For Heights array : ";
    for (int i : heights)
      cout << i << " ";
    cout << endl;
    cout << "Minimum enegery required for fog to jump from 1 to " << stairs << " within " << k << " steps is : " << minEnergy << endl;
    cout << "----------------------------------------------\n";
  }
}