/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp= new ListNode();
        ListNode* cur=temp;
        int carry=0;
        while(l1 || l2 || carry!=0){
            int a=l1 ? l1->val:0;
            int b=l2 ? l2->val:0;

            int sum=a+b+carry;
            carry=sum/10;
            sum%=10;
            cur->next=new ListNode(sum);

            cur=cur->next;
            l1=l1?l1->next:0;
            l2=l2?l2->next:0;
        }
        ListNode* ans=temp->next;
        return ans;
    }
};