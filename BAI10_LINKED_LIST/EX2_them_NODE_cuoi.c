#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sinh_Vien
{
    int id;
    char name[20];
    struct Sinh_Vien *next;  
} Sinh_Vien;

Sinh_Vien *createNode (int id, char arr[]){
    Sinh_Vien *ptr = (Sinh_Vien*)malloc(sizeof(Sinh_Vien));
    ptr->id = id;
    strcpy(ptr->name, arr);
    ptr->next = NULL;
    return ptr;
}
    // C1: tạo hàm với kiểu dữ liệu Sinh_Vien và khi gọi hàm thì khai báo 1 còn trỏ thuộc kiểu Sinh_Vien để gọi hàm 
/*Sinh_Vien *push_back(Sinh_Vien **head, int ID, char arr[]){
    Sinh_Vien *new_Node = createNode(ID, arr);
    if (* head== NULL){
        *head = new_Node;
        return new_Node;
    };
    Sinh_Vien *p = *head;
    while (p->next != NULL){
        p = p->next;        
    } 
    p->next = new_Node;
    new_Node->next = NULL;
    return new_Node;
}*/

    // C2: tạo hàm hiểu void, và khi gọi làm chỉ cần gọi lại hàm ko cần gán biến
void push_back (Sinh_Vien **head, int ID, char arr[]){
    Sinh_Vien *new_Node = createNode(ID, arr);
    if (*head == NULL){
        *head = new_Node;
            }
    Sinh_Vien *p = *head;
    while (p->next !=NULL){
        p = p->next;
    }
    p->next = new_Node;
    new_Node->next = NULL;
   
}


int main(){
    
    Sinh_Vien *head = createNode(22145490, "ho bao ton");
    Sinh_Vien *second = createNode(22145482, "le huu tinh");
    Sinh_Vien *third = createNode(22145492, "nguyen quoc trieu");
    Sinh_Vien *fourth = createNode(22145432, "le huy phat");

        head->next = second;
    second->next = third;
    third->next = fourth; 

    //Sinh_Vien *add = push_back(&head, 22145436, "nay vu"); // gọi hàm theo C1

    push_back (&head, 22145436, "nay vu"); // gọi hàm theo c2

    Sinh_Vien *ptr = head;
    while (ptr!=NULL){
        printf("ID: %d     NAME: %s     vitri NODE: %p        next: %p\n", ptr->id, ptr->name, ptr, ptr->next);
        ptr = ptr->next;
    }
    return 0;    
}