#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Tạo một nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Không đủ bộ nhớ.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Thêm một nút vào cuối danh sách
void insertLast(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Xóa phần tử cuối cùng
void deleteLast(Node** head) {
    if (*head == NULL) {
        printf("Danh sách rỗng, không thể xóa.\n");
        return;
    }

    // Nếu danh sách chỉ có một phần tử
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Di chuyển tới phần tử cuối cùng
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Xóa phần tử cuối
    temp->prev->next = NULL;
    free(temp);
}

// In danh sách liên kết đôi
void printList(Node* head) {
    printf("Danh sách: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

// Hàm main để kiểm tra
int main() {
    Node* head = NULL;
    int value;

    printf("Nhập các giá trị trong danh sách (nhập -1 để kết thúc):\n");
    while (1) {
        printf("Nhập giá trị: ");
        scanf("%d", &value);
        if (value == -1) break;
        insertLast(&head, value);
    }

    printf("\nDanh sách hiện tại:\n");
    printList(head);

    // Xóa phần tử cuối cùng
    printf("\nXóa phần tử cuối cùng:\n");
    deleteLast(&head);

    // In danh sách sau khi xóa
    printf("\nDanh sách sau khi xóa phần tử cuối cùng:\n");
    printList(head);

    return 0;
}
