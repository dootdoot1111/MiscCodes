#include<bits/stdc++.h>
using namespace std;
//iterate over the array and keep inserting B elements at a time in a set, keep storing the count of the set after inserting B elements; tc-O(n^2)
//TLE on hard solution, not preferred


vector<int> dNums(vector<int> &A, int B) {
    
    vector<int> ans;
    if(A.size()==1){
    ans.push_back(1);
    return ans;}
    
    if(B>A.size())
    return ans;
    
    int s=A.size();
    for(int i=0;i<s-B+1;i++){
        set<int> s;
        for(int j=i;j<i+B;j++){
            s.insert(A[j]);
        }
        ans.push_back(s.size());
    }
    return ans;
}

//O(n); sliding window using maps
vector<int> dNums(vector<int> &A, int B){
    int n=A.size();
    vector<int> ans;
    if(B>n)                      //if window size> size of the array, not possible
    return ans;  

    unordered_map<int,int> m;
    for(int i=0;i<B;i++){
        m[A[i]]++;                    //first insert all the B starting elements
    }
    ans.push_back(m.size());

    for(int i=1;i<n-B+1;i++){
        int temp=A[i-1];
        m[temp]--;                          //removing the starting element of the previous subarray, to keep sliding the window of size B over the vector
        if(m[temp]==0)                      //remove first,insert B+1th element and store the map's size
        m.erase(temp);
        m[A[n+B-1]]++;            //inserting the B+1th element
        ans.push_back(m.size());
    }
    return ans;
}