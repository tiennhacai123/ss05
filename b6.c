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

// Tìm và thay thế giá trị trong danh sách liên kết đôi
void replaceValue(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    int found = 0;

    // Duyệt qua danh sách
    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue; // Thay thế giá trị
            found = 1;
        }
        temp = temp->next;
    }

    // Kiểm tra nếu không tìm thấy giá trị
    if (!found) {
        printf("Không tìm thấy giá trị %d trong danh sách.\n", oldValue);
    }
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
    int value, oldValue, newValue;

    printf("Nhập các giá trị trong danh sách (nhập -1 để kết thúc):\n");
    while (1) {
        printf("Nhập giá trị: ");
        scanf("%d", &value);
        if (value == -1) break;
        insertLast(&head, value);
    }

    printf("\nDanh sách hiện tại:\n");
    printList(head);

    // Nhập giá trị cần thay thế và giá trị mới
    printf("\nNhập giá trị cần thay thế: ");
    scanf("%d", &oldValue);
    printf("Nhập giá trị thay thế: ");
    scanf("%d", &newValue);

    // Thay thế giá trị trong danh sách
    replaceValue(head, oldValue, newValue);

    // In danh sách sau khi thay thế
    printf("\nDanh sách sau khi thay thế:\n");
    printList(head);

    return 0;
}
