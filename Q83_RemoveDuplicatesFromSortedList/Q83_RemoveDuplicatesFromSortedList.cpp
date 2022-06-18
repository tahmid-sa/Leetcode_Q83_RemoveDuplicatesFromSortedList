#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return head;
    }

    for (ListNode* tmpI = head, *tmpJ = head->next; tmpJ != nullptr; tmpJ = tmpJ->next) {
        if (tmpI->val != tmpJ->val) {
            tmpI = tmpI->next;
        }
        else if (tmpI->val == tmpJ->val) {
            tmpI->next = tmpJ->next;
        }
    }


    for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
        cout << tmp->val << endl;
    }

    return head;
}

int main()
{
    ListNode n1 = ListNode(3);
    ListNode n2 = ListNode(3, &n1);
    ListNode n3 = ListNode(2, &n2);
    ListNode n4 = ListNode(1, &n3);
    ListNode n5 = ListNode(1, &n4);

    deleteDuplicates(&n5);

    return 0;
}