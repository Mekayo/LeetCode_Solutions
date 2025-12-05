// LeetCode #92: Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list
#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;

        ListNode* ele_at=new ListNode(0);
        ele_at->next=head;
        ListNode* prev =ele_at;

        // reach to the left
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        ListNode* cur=prev->next;

        for(int j=0;j<right-left;j++){
            ListNode* temp=cur->next;
            cur->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
        }
        return ele_at->next;
    }
};