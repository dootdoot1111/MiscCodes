#include<bits/stdc++.h>
using namespace std;

//INCOMPLETE

//recursion
int f(int i,int j,string pattern,string text){
    if(i<0 && j<0) return true; //both strings exhausted
    if(i<0 && j>0) return false; //second string not exhausted
    if(j<0 && i>=0){   //if first string not exhausted
        for(int ii=0;ii<=i;ii++){
            if(pattern[ii]!='*')  //check if all the characters of the first string is *
            return false;
        }
        return true;
    }
    if(pattern[i]==text[j] || pattern[i]=='?'){
        return f(i-1,j-1,pattern,text);     //if both the characters are matching just move back
    }
    if(pattern[i] == '*'){
        return f(i-1,j,pattern,text) || f(i,j-1,pattern,text);  //if we encounter *, first case we ignore *,i.e., we treat it as 0 and move behind; in the second case we stay at * and move back by one in string 2,this eventually will take care of all the cases
    }
    return false;

}




bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   int n=pattern.size();
   int m=text.size();
   return f(n-1,m-1,pattern,text);

}





//memoisation
bool wildcardMatchingUtil(string & S1, string & S2, int i, int j, vector < vector < bool >> & dp) {

  //Base Conditions
  if (i < 0 && j < 0)
    return true;
  if (i < 0 && j >= 0)
    return false;
  if (j < 0 && i >= 0)
    {for (int x = 0; x <= i; x++) {
    if (S1[x] != '*')
      return false;
  }
  return true;}

  if (dp[i][j] != -1) return dp[i][j];

  if (S1[i] == S2[j] || S1[i] == '?')
    return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);

  else {
    if (S1[i] == '*')
      return wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
    else return false;
  }
}




bool wildcardMatching2(string S1, string S2)
{
   // Write your code here.

   int n = S1.size();
  int m = S2.size();

  vector < vector < bool >> dp(n, vector < bool > (m, -1));
  return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
}
