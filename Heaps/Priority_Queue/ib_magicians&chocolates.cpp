#include<bits/stdc++.h>
using namespace std;

//array after every operation change ho rha hai toh use pq; mod ka bakchodi
int nchoc(int A, vector<int> &B) {
    priority_queue<int> pq(B.begin(), B.end());
    int ans=0;
    while(A>0){
        int temp=pq.top();
        ans=ans%1000000007+temp%1000000007;
        ans=ans%1000000007;
        pq.pop();
        pq.push(temp/2);
        A--;
    }
    return ans;
}
