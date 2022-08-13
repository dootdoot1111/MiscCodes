#include<bits/stdc++.h>
using namespace std;


//heap can have duplicates, heap mein saare sorted arrays ke saare elements push kardo and then upar se pop kar karke store it in a ans vector
vector<int> solve(vector<vector<int> > &A) {
    vector<int> ans;
    priority_queue<int,vector<int>, greater<int>> min_h;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
        min_h.push(A[i][j]);
    }
}
    while(min_h.size()!=0){
        ans.push_back(min_h.top());
        min_h.pop();
    }
    return ans;
}
