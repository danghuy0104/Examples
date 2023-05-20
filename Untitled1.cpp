#include <iostream>
using namespace std;

// �?nh nghia m?t node trong danh s�ch li�n k?t
struct Node {
    int data;
    Node* next;
};

// H�m d? ch�n m?t node m?i v�o cu?i danh s�ch li�n k?t
void appendNode(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
    return;
}

// H�m d? ch�n m?t node m?i v�o danh s�ch li�n k?t sao cho c�c ph?n t? ch?n v� l? dan xen nhau
void insertNode(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* current_node = *head_ref;
    Node* prev_node = NULL;

    // T�m node ch?n/cu?i danh s�ch (n?u c�) d? ch�n node m?i v�o
    while (current_node != NULL && current_node->data % 2 != 0) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    // Ch�n node m?i v�o gi?a prev_node v� current_node
    new_node->next = current_node;
    if (prev_node == NULL) {
        *head_ref = new_node;
    } else {
        prev_node->next = new_node;
    }
}

// H�m d? in danh s�ch li�n k?t
// testing
// testing_1
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 3);
    appendNode(&head, 5);
    appendNode(&head, 7);
    appendNode(&head, 9);

    insertNode(&head, 4);
    insertNode(&head, 6);
    insertNode(&head, 2);

    printList(head);

    return 0;
}

