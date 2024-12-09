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

// Chèn phần tử tại vị trí bất kỳ
void insertAtPosition(Node** head, int position, int value) {
    if (position < 0) {
        printf("Lỗi vị trí không hợp lệ.\n");
        return;
    }

    Node* newNode = createNode(value);

    if (position == 0) {  // Chèn vào đầu danh sách
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int index = 0;

    // Tìm vị trí chèn
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    // Nếu vị trí vượt quá độ dài danh sách
    if (temp == NULL || (temp->next == NULL && index < position - 1)) {
        printf("Lỗi vị trí không hợp lệ.\n");
        free(newNode); // Giải phóng bộ nhớ
        return;
    }

    // Chèn phần tử vào danh sách
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
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
    int value, position, choice;

    printf("Nhập các giá trị trong danh sách (nhập -1 để kết thúc):\n");
    while (1) {
        printf("Nhập giá trị: ");
        scanf("%d", &value);
        if (value == -1) break;
        insertLast(&head, value);
    }

    printf("\nDanh sách hiện tại:\n");
    printList(head);

    // Nhập giá trị cần chèn và vị trí chèn
    printf("\nNhập giá trị cần chèn: ");
    scanf("%d", &value);
    printf("Nhập vị trí cần chèn: ");
    scanf("%d", &position);

    // Thực hiện chèn
    insertAtPosition(&head, position, value);

    // In danh sách sau khi chèn
    printf("\nDanh sách sau khi chèn:\n");
    printList(head);

    return 0;
}
