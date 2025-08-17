#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Edge case: if list has 0 or 1 node, just return head
        if (!head || !head->next) return head;

        // Pointers for odd and even lists
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save start of even list

        // Rearrange nodes
        while (even && even->next) {
            odd->next = odd->next->next;   // link odd to next odd
            even->next = even->next->next; // link even to next even

            odd = odd->next;   // move odd forward
            even = even->next; // move even forward
        }

        // Connect odd list with even list
        odd->next = evenHead;

        return head;
    }
};

// Helper function to create linked list from vector
ListNode* createList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Solution sol;

    // Example input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    head = sol.oddEvenList(head);

    cout << "Odd-Even Reordered List: ";
    printList(head);

    return 0;
}
