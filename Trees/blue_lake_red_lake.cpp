
#include <bits/stdc++.h>
using namespace std;
void fnc(vector<vector<int>> &matrix,int i,int j,int prev,vector<vector<int>> ocean){
    if(i==0 || j==0 || i>matrix.size() || j>matrix.size())
    return;
    
    if(ocean[i][j]==1)
    return;
    
    if(matrix[i][j]<prev)
    return;
    
    ocean[i][j]=1;
    
    fnc(matrix,i+1,j,matrix[i][j],ocean);
    fnc(matrix,i-1,j,matrix[i][j],ocean);
    fnc(matrix,i,j+1,matrix[i][j],ocean);
    fnc(matrix,i,j-1,matrix[i][j],ocean);
}


int solve(vector<vector<int> > &A) {
    int count=0;
    if(A.size()<1)
    return 0;
    
    vector<vector<int>> ans;
    
    
    vector<vector<int>> blue(A.size(),vector<int>(A[0].size(),0));
    
    vector<vector<int>> red(A.size(),vector<int>(A[0].size(),0));
    
     for(int col=0;col<A[0].size();col++)
        {
            fnc(A,0,col,INT_MIN,blue);
            fnc(A,A.size()-1,col,INT_MIN,red);
            
        }
        
        for(int row = 0;row<A.size();row++)
        {
             fnc(A,row,0,INT_MIN,blue);
            fnc(A,row,A[0].size()-1,INT_MIN,red);
        }
    
     for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<A[0].size();j++)
            {
                if(blue[i][j]==1 && red[i][j]==1)
                {
                    count++;
                }
            }
        }
        
        return count;
    
}
