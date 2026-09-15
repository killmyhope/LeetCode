// 234. Palindrome Linked List [Easy] 
// https://leetcode.com/problems/palindrome-linked-list/ 
// Accepted submission: 1994987020; language: cpp 
// Problem statement (HTML): 
// <p>Given the <code>head</code> of a singly linked list, return <code>true</code><em> if it is a </em><span data-keyword="palindrome-sequence"><em>palindrome</em></span><em> or </em><code>false</code><em> otherwise</em>.</p> 
//  
// <p>&nbsp;</p> 
// <p><strong class="example">Example 1:</strong></p> 
// <img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg" style="width: 422px; height: 62px;" /> 
// <pre> 
// <strong>Input:</strong> head = [1,2,2,1] 
// <strong>Output:</strong> true 
// </pre> 
//  
// <p><strong class="example">Example 2:</strong></p> 
// <img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg" style="width: 182px; height: 62px;" /> 
// <pre> 
// <strong>Input:</strong> head = [1,2] 
// <strong>Output:</strong> false 
// </pre> 
//  
// <p>&nbsp;</p> 
// <p><strong>Constraints:</strong></p> 
//  
// <ul> 
// 	<li>The number of nodes in the list is in the range <code>[1, 10<sup>5</sup>]</code>.</li> 
// 	<li><code>0 &lt;= Node.val &lt;= 9</code></li> 
// </ul> 
//  
// <p>&nbsp;</p> 
// <strong>Follow up:</strong> Could you do it in <code>O(n)</code> time and <code>O(1)</code> space? 

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        while (curr) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        ListNode *left = head;
        ListNode *right = prev;
        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};
