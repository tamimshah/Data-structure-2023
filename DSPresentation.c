#include<stdio.h>
#include<stdlib.h>

struct Node
    {
        int flag;
        int data;
        struct Node*next;
    };
typedef struct Node NODE;

int main()
{
    NODE *head, *first, *temp;
    first = 0;
    for(int i = 0; i<5; i++)
    {
        head = (NODE *)malloc(sizeof(NODE));
        printf("memory we get: %d\n", head);
        printf("Insert element at Position %d: ",i+1);
        scanf("%d", &head->data);
        if (first != 0)
        {
            temp->next = head;
            temp = head;
            temp->flag = 0;
        }
        else
        {
            first = temp = head;
            first->flag = 1;
        }
    }
    temp->next = first;

    NODE *p1 = first;
    printf("\n status of the linked list is: \n");
    printf("[%d] \t", p1);
    do{
        printf("[%d] [%d] [%d]\t", p1->flag,p1->data,p1->next);
        p1 = p1->next;
    }while (p1->flag != 1);

    NODE *ptr1 = first;
    NODE *ptr2 = first->next;
    for(int j = 0; j < 2-1; j++)
       {
          ptr1 = ptr1->next;
          ptr2 = ptr2->next;
       }
    ptr1->next = ptr2->next;
    free(ptr2);

    NODE *p2 = first;
    printf("\n status of the linked list after deleting 3rd Element is: \n");
    printf("[%d] \t", p2);
    do{
        printf("[%d] [%d] [%d]\t", p2->flag,p2->data,p2->next);
        p2 = p2->next;
    }while (p2->flag != 1);

    return 0;
}
