#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry == 1) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};

// Helper functions
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int num : nums) {
        curr->next = new ListNode(num);
        curr = curr->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Input for l1
    int n1;
    cout << "Enter number of digits for the first number: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter the digits for the first number (from least to most significant): ";
    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }
    ListNode* l1 = createList(nums1);

    // Input for l2
    int n2;
    cout << "Enter number of digits for the second number: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter the digits for the second number (from least to most significant): ";
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }
    ListNode* l2 = createList(nums2);

    // Add numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Output result
    cout << "Result: ";
    printList(result);

    return 0;
}
