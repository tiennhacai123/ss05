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

// Hàm duyệt và in danh sách từ cuối về đầu
void printReverse(Node* head) {
    if (head == NULL) {
        printf("Danh sách rỗng.\n");
        return;
    }

    // Di chuyển tới phần tử cuối cùng
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Duyệt ngược lại và in giá trị
    printf("Danh sách ngược: NULL");
    while (temp != NULL) {
        printf(" <-- --> %d", temp->data);
        temp = temp->prev;
    }
    printf(" <-- --> NULL\n");
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

    printf("\nDanh sách theo thứ tự ngược:\n");
    printReverse(head);

    return 0;
}
