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

void delete_list (Sinh_Vien **head, int position){
    if (*head == NULL){return;}

    Sinh_Vien *p = *head;
    int k = 0;
    while (p->next->next != 0 && k != position - 2)
    {
        p = p->next;
        k++;
    }
    Sinh_Vien *i = p->next->next;
    //free(p->next);
    p->next = i;

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

    delete_list (&head, 5);

    Sinh_Vien *ptr = head;
    while (ptr != NULL){
        printf("ID: %d     NAME: %s     vitri: %p        next: %p\n", ptr->id, ptr->name, ptr, ptr->next);
        ptr = ptr->next;
    }
    return 0;    
}