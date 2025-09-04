

class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k == 1) return head;

        Node dummy(0);
        dummy.next = head;
        Node* prevGroupEnd = &dummy;

        while (true) {
            Node* kth = prevGroupEnd;
            // Find kth node (if not found, still reverse what's left)
            for (int i = 0; i < k && kth->next; i++) {
                kth = kth->next;
            }

            if (!kth) break; // No more nodes

            Node* groupStart = prevGroupEnd->next;
            Node* nextGroupStart = kth->next;

            // Reverse this group
            Node* prev = nextGroupStart;
            Node* curr = groupStart;
            while (curr != nextGroupStart) {
                Node* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Connect reversed group
            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart;

            // If less than k nodes left, still reverse (handled by loop)
            if (!prevGroupEnd->next) break;
        }

        return dummy.next;
    }
};
