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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // O(n^2)
        // ListNode dummy;
        // ListNode* h_ans = &dummy;

        // for (ListNode* i = head; i != nullptr; i = i -> next)
        // {
        //     bool flag = true;
        //     int sum = 0;
        //     for (ListNode* j = i; j != nullptr; j = j -> next) // Check whether i will create a zero sum consecutive sequence
        //     {
        //         sum += j -> val;
        //         if (sum == 0)
        //         {
        //             flag = false;
        //             i = j;
        //             break;
        //         }
        //     }

        //     if (flag)  // If it can't create a zero sum consecutive sequence, add it to ans
        //     {
        //         h_ans -> next = i;
        //         h_ans = h_ans -> next;
        //     }
        // }
        // h_ans -> next = nullptr; // Remove remaining nodes
        // return dummy.next;

        // O(N^2)
        // ListNode* dummy = new ListNode(0, head);

        // for (ListNode* start = dummy; start != nullptr; start = start->next)
        // {
        //     int sum = 0;
        //     for (ListNode* end = start->next; end != nullptr; end = end->next)
        //     {
        //         sum += end->val;
        //         if (sum == 0)
        //             start->next = end->next;
        //     }
        // }
        // return dummy->next;

        // O(n)
        // ListNode* dummy = new ListNode(0, head);
        // unordered_map<int, ListNode*> prefix_sum_to_node;
        
        // prefix_sum_to_node[0] = dummy;
        // int prefix_sum = 0;
        // for (ListNode* i = head; i != nullptr; i = i->next)
        // {
        //     prefix_sum += i->val;
        //     prefix_sum_to_node[prefix_sum] = i;
        // }

        // prefix_sum = 0;
        // for (ListNode* i = dummy; i != nullptr; i = i->next)
        // {
        //     prefix_sum += i->val;
        //     i->next = prefix_sum_to_node[prefix_sum]->next;
        // }
        // return dummy->next;

        // O(N) but with hashtable overhead
        ListNode* dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> prefix_sum_to_node;
        int prefix_sum = 0;
        for (ListNode* i = dummy; i != nullptr; i = i->next)
        {
            prefix_sum += i->val;
            if (prefix_sum_to_node.find(prefix_sum) != prefix_sum_to_node.end())
            {
                int p = prefix_sum;
                for (ListNode* j = prefix_sum_to_node[prefix_sum]->next; j != i; j = j->next) // Remove zero sum from hashmap
                {
                    p += j->val;
                    prefix_sum_to_node.erase(p);
                }
                prefix_sum_to_node[prefix_sum]->next = i->next;
            }
            else
                prefix_sum_to_node[prefix_sum] = i;
        }
        return dummy->next;
    }
};