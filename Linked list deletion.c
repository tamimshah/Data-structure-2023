#include <stdio.h> //Id. 222-35-1141
#include <stdlib.h> //Md. Tahmid Shah Tamim
struct Node {
    int data;
    struct Node* next;
};
struct Node* delete_first(struct Node* head) {
    if (head == NULL) {
        printf("Error: Linked list is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
struct Node* delete_nth(struct Node* head, int n) {
    if (head == NULL) {
        printf("Error: Linked list is empty.\n");
        return NULL;
    }
    if (n == 1) {
        return delete_first(head);
    }
    struct Node* curr = head;
    for (int i = 1; i < n - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL || curr->next == NULL) {
        printf("Error: Invalid position.\n");
        return head;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return head;
}

struct Node* delete_last(struct Node* head) {
    if (head == NULL) {
        printf("Error: Linked list is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return head;
}

void print_list(struct Node* head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->next->data = 6;
    head->next->next->next->next->next->next = NULL;


    printf("Original ");
    print_list(head);


    head = delete_first(head);
    head = delete_nth(head,2);
    head = delete_last(head);

    printf("Modified ");
    print_list(head);

    return 0;
}
