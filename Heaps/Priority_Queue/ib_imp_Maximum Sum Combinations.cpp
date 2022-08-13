#include<bits/stdc++.h>
using namespace std;

// Brute force(insert all possible sum of the elements of the array into a max heap and take out the top C elements)
// max heap.
// Time Complexity: O(N^2)
// Auxiliary Space : O(N^2)
vector<int> solve(vector<int> &A, vector<int> &B, int C) {

    int n=A.size();
    vector<int>ans;

    priority_queue<int> pq;

    // insert all the possible combinations
    // in max heap.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pq.push(A[i] + B[j]);

    // pop first N elements from max heap
    // and display them.
    int count = 0;
    while (count < C) {
        ans.push_back(pq.top());
        pq.pop();
        count++;
    }
    return ans;

}    



//1) sort the array 2) use pq to store and figure out the max of the sum of the next indices 3)maintain a set to store the indices to make sure we dont take the same indices again
//O(nlog(n)) using pq
vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> ans;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    priority_queue<pair<int,pair<int,int> > > pq;
    set<pair<int,int>> s;

    pq.push({A[A.size()-1]+B[B.size()-1],{A.size()-1,B.size()-1}});
    s.insert({A.size()-1,B.size()-1});

    while(C>0){
        pair<int,pair<int,int> > temp= pq.top();
        pq.pop();
        int sum=temp.first;
        int i=temp.second.first;
        int j=temp.second.second;
        ans.push_back(sum);

        sum=A[i-1]+B[j];
        if(s.find({i-1,j})==s.end()){
            pq.push({sum,{i-1,j}});
            s.insert({i-1,j});
        }
        sum=A[i]+B[j-1];
        if(s.find({i,j-1})==s.end()){
            pq.push({sum,{i,j-1}});
            s.insert({i,j-1});
        }
        C--;
    }
    return ans;

}
