#include<bits/stdc++.h>
using namespace std;


//returning the k largest elements of a vector using pq
vector<int> solve(vector<int> &A, int B) {
   priority_queue<int> pq (A.begin(),A.end());
    vector<int> ans;
    while(B>0){
        int temp=pq.top();
        ans.push_back(temp);
        pq.pop();
        B--;
    }
    return ans;
}
