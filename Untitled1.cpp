#include <iostream>
using namespace std;

// Ð?nh nghia m?t node trong danh sách liên k?t
struct Node {
    int data;
    Node* next;
};

// Hàm d? chèn m?t node m?i vào cu?i danh sách liên k?t
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

// Hàm d? chèn m?t node m?i vào danh sách liên k?t sao cho các ph?n t? ch?n và l? dan xen nhau
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

    // Tìm node ch?n/cu?i danh sách (n?u có) d? chèn node m?i vào
    while (current_node != NULL && current_node->data % 2 != 0) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    // Chèn node m?i vào gi?a prev_node và current_node
    new_node->next = current_node;
    if (prev_node == NULL) {
        *head_ref = new_node;
    } else {
        prev_node->next = new_node;
    }
}

// Hàm d? in danh sách liên k?t
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

