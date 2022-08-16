#include<bits/stdc++.h>
using namespace std;

//yeh waala dekhna hai dhang se:
//   Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
void dfs(int u, int par,vector<int> graph[],vector<int> &cnt_node){
    cnt_node[u]++;
    for(int child:graph[u]){
        if(child==par)
        continue;
        dfs(child,u,graph,cnt_node);
        cnt_node[u]+=cnt_node[child];
    }
}
int solve(int N, vector<vector<int> > &B) {
vector<int> graph[N+1];
vector<int> cnt_nodes(N+1,0);
for(auto edge:B){
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
}
dfs(1,0,graph,cnt_nodes);
int ans=0;
for(int i=2;i<=N;i++){
    int part1 =cnt_nodes[i];
    int part2 =cnt_nodes[1]-part1;
    if(part1%2==0 && part2%2==0)
    ans++;
}
return ans;
}
