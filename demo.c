#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next; // con trỏ trỏ đến nút kế tiếp
    struct Node* prev; // con trỏ trỏ đến nút trước nó
}Node;

Node* createNode(int value){
    // cấp phát bộ nhớ động
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    // tạo nút mới thì 2 nút đầu cuối của nó trỏ đến NULL
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// them phan tu vao dau danh sach - truyền vào nút đầu tiên là head và dữ liệu của nút mới
void insertHead(Node** head, int value){
    //  tao node moi
    Node* newNode = createNode(value);
    newNode->next = *head;
    if(*head != NULL){
        (*head)->prev = newNode; 
    }
    *head = newNode;
}

// duyet danh sach
void printList(Node* head){
    Node* temp = head;
    printf("NULL");
    while(temp != NULL){
        printf("<--->%d", temp->data);
        temp = temp->next;
    }
    printf("<--->NULL");
}
// thêm phần tử vào cuối danh sách
void insertEnd(Node** head, int value){
    Node* newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    // tìm phần tư cuối
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    }
// them phan tu vao vi tri bat ki
void insertRandom(Node** head, int position, int value) {
    if (position <= 0) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }
    
    // Nếu chèn ở đầu danh sách
    if (position == 0) {
        insertHead(head, value);
        return;
    }

    // Tạo nút mới
    Node* newNode = createNode(value);
    Node* temp = *head;
    int currentPos = 0;

    // Duyệt danh sách để tìm vị trí cần chèn
    while (temp->next != NULL && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }

    // Kiểm tra nếu vị trí lớn hơn chiều dài danh sách
    if (temp == NULL) {
        printf("Vị trí vượt quá số lượng phần tử\n");
        return;
    }
    // Chèn nút mới giữa temp và temp->next
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

int main(){
    Node* head = NULL;
    int value;
    int position;
    do{
        printf("\n==============MENU============");
        printf("\n1. Thêm 1 phần tử vào đầu danh sách");
        printf("\n2. Hiển thị danh sách");
        printf("\n3. Thêm phần tử vào cuối danh sách");
        printf("\n4. Thềm phần tử vào vị trí bất kì ");
        printf("\n5. THoat");
        printf("\n Mời bạn chọn");
        int choice;
        scanf("%d",&choice);
        switch (choice){
            case 1:
            printf("Mời bạn nhâp giá trị");
            scanf("%d",&value);
            insertHead(&head,value);
            break;
            case 2: 
            printList(head);
            break;
            case 3:
            printf("Mời bạn nhâp giá trị");
            scanf("%d",&value);
            insertEnd(&head,value);
            break;
            case 4:
            printf("Mời bạn nhập vị trí cần thêm");
            scanf("%d",&position);
            printf("Mời bạn nhâp giá trị");
            scanf("%d",&value);
            insertRandom(&head,position,value);
            break;
            case 5:
            exit(0);
            default: 
            printf("\n Vui long nhap lai");
        }
    }while(1==1);
    return 0;
}