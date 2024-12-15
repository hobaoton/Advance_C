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

int main(){
    
    Sinh_Vien *head = createNode(22145490, "ho bao ton");
    Sinh_Vien *second = createNode(22145482, "le huu tinh");
    Sinh_Vien *third = createNode(22145492, "nguyen quoc trieu");
    Sinh_Vien *fourth = createNode(22145432, "le huy phat");

    Sinh_Vien *ptr = head;
    head->next = second;
    second->next = third;
    third->next = fourth;

    while (ptr->next!=NULL){
        printf("ID: %d     NAME: %s     vitri: %p        next: %p\n", ptr->id, ptr->name, ptr, ptr->next);
        ptr = ptr->next;
    }
    return 0;    
}