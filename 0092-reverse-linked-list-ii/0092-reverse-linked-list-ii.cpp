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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return head;
        if(left == right) return head;
        ListNode* cur = head ;
        ListNode* prev = NULL;
        int pos = 1;
        while(cur != NULL){
            if(pos < left){
                prev = cur;
                cur = cur->next;
                pos++;
                continue;
            }
            ListNode* temp = cur;
            ListNode* prevtemp = NULL;
            int times = right - left + 1;
            while(times--){
                ListNode* nexttemp = temp->next;
                temp->next = prevtemp;
                prevtemp = temp; 
                temp = nexttemp;
            }
            cur->next = temp;
            if(prev == NULL){
                return prevtemp;
            }
            prev->next = prevtemp;
            return head;
        }
        return head;
    }
};