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

    void reverse(ListNode* head, int times){
        ListNode* cur  = head;
        ListNode* prev = NULL;
        while(times--){
            ListNode* nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* left = head; 
        ListNode* right;
        ListNode* prevleft = NULL;
        ListNode* res = NULL;
        int size = 2;
        while(true){
            right = left ;
            for(int i =0;i<size-1;i++){
                if(right == NULL) break;
                right = right -> next;
            }

            if(right){
                ListNode* nextleft = right -> next;
                reverse(left, size);
                if(prevleft)
                prevleft->next = right;
                prevleft = left;
                if(res == NULL) res = right;

                left = nextleft ;
            }
            else {
                if(prevleft)
                prevleft->next = left;
                if(res == NULL) res = left;
                break;
            }
        }
        return res;
    }
};