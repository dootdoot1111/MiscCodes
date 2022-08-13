#include<bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 

//merge k linked list- push saare LL ke saare elements into a min heap of pair<int,ListNode*>, apne aap values ke basis pe sort ho jayega, phir keep popping and linking the element using the ListNOde* which we haad stored
ListNode* mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> min_h;
    for (int i = 0; i < A.size(); i++)
    {   ListNode* temp=A[i];
        while(temp!=NULL){
            min_h.push({temp->val,temp});
            temp=temp->next;
        }
    }
    ListNode* head=min_h.top().second;
    ListNode* ans=min_h.top().second;
    min_h.pop();
    while(min_h.size()>0){
        ListNode* temp=min_h.top().second;
        min_h.pop();
        head->next=temp;
        head=head->next;
    }
    return ans;
}
