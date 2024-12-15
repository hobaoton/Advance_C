#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

bool empty(Sinh_Vien **head) {
    if (*head == NULL) {
        printf("danh sach rong\n");
        return true;
    } else {
        printf("danh sach co gia tri\n");
        return false;
    }
}


int main(){
    
    Sinh_Vien *head = createNode(22145490, "ho bao ton");
    Sinh_Vien *second = createNode(22145482, "le huu tinh");
    Sinh_Vien *third = createNode(22145492, "nguyen quoc trieu");
    Sinh_Vien *fourth = createNode(22145432, "le huy phat");
    Sinh_Vien *fifth = createNode(22145468, "nguyen duc anh");
    Sinh_Vien *sixth = createNode(22145726, "nguyen huu tri");
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth; 

   empty(&head);

    Sinh_Vien *ptr = head;
    while (ptr != NULL){
        printf("ID: %d     NAME: %s     vitri: %p        next: %p\n", ptr->id, ptr->name, ptr, ptr->next);
        ptr = ptr->next;
    }
    return 0;    
}