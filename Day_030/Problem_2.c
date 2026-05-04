#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    int carry = 0;
    struct ListNode* result = NULL;
    struct ListNode* tail = NULL;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        struct ListNode* node = createNode(sum % 10);

        if (!result) {
            result = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        carry = sum / 10;
    }

    return reverse(result);
}

void insertEnd(struct ListNode** head, int val) {
    struct ListNode* node = createNode(val);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct ListNode* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next)
            printf(" ");
        head = head->next;
    }
}

int main() {
    int n1, n2, x;
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        insertEnd(&l1, x);
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        insertEnd(&l2, x);
    }

    struct ListNode* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}
