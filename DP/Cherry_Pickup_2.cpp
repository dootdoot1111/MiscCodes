#include <bits/stdc++.h>
using namespace std;
//single robot ke liye works fine, par do robot the, toh either use tabulation and trace back the path of first robot and then pass it when you make the call for the second robot
int helper(int i,int j,vector<vector<int>> &grid){
        //base case
        int n=grid.size();
        if(i>=n)
        return 0;

        if(j<0 || j>n-1)
        return 0;

        int notpick=0+helper(i+1,j-1,grid)+helper(i+1,j,grid)+helper(i+1,j+1,grid);

        int pick=grid[i][j]+helper(i+1,j-1,grid)+helper(i+1,j,grid)+helper(i+1,j+1,grid);
        return max(pick,notpick);
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        return helper(0,0,grid);
    }


    //dono ko liye ek hi recursion call use kara, since woh humaesha ek sath same row pe honge toh only one i is enough,3-D DP
     int maxChocoUtil(int i, int j1, int j2, int n, int m, vector < vector < int >> 
& grid, vector < vector < vector < int >>> & dp) {
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e9;

  if (i == n - 1) {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = INT_MIN;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      int ans;
      if (j1 == j2)
        ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
      else
        ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n,
        m, grid, dp);
      maxi = max(maxi, ans);
    }
  }
  return dp[i][j1][j2] = maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector < vector < vector < int >>> dp(n, vector < vector < int >> (m, vector < int
  > (m, -1)));

  return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
    }