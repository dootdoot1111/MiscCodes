#include<bits/stdc++.h>
using namespace std;

//whenever koi array mein baar baar elements ko change kar rhe ho and you want to store it a particular fashion, use heaps

//here heap use karke max available price maintain karo, add it to you profit, modify the price and again push it into the heap.
int solve(vector<int> &A, int B) {
    priority_queue<int> pq(A.begin(),A.end());  //creating a max heap

    int profit=0;

    for(int i=B;i>0;i--){
        int temp=pq.top();          //max element in the heap
        profit+=temp;
        pq.pop();
        pq.push(temp-1);            //insert the modified element
    }
    return profit;
}
