#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct node *link;
}*newnode,*head,*temp,*delt;

void create()
{
    head = (struct list*)malloc(sizeof(struct list));
    head->link = NULL;

}

void insbeg(int info)
{
    if(head->link == NULL)
    {
        newnode = (struct list*)malloc(sizeof(struct list));
        newnode->data = info;
        newnode->link = NULL;

        head->link = newnode;
    }
    else
    {
        newnode = (struct list*)malloc(sizeof(struct list));
        newnode->data = info;
        newnode->link = head->link;
        head->link = newnode;
    }
}

void insend(int info)
{
    newnode = (struct list*)malloc(sizeof(struct list));
    newnode->data = info;
    newnode->link = NULL;

    temp = head;
    while(temp->link != NULL)
        temp = temp->link;

    temp->link = newnode;
}

void insert(int i,int info)
{
    int h=0;

    newnode = (struct list*)malloc(sizeof(struct list));
    newnode->data = info;
    newnode->link = NULL;

    temp = head;
    while(h < i-1)
    {
        temp = temp->link;
        h++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void del(int i)
{
    int h=0;

    temp = head;
    while(h < i-1)
    {
        temp = temp->link;
        h++;
    }

    delt = temp->link;
    temp->link = delt->link;
    free(delt);
}

void display()
{
    temp = head;
    printf("\n");
    while(temp->link != NULL)
    {
        temp = temp->link;
        printf("%d\t",temp->data);
    }
}

int main()
{
    int ch,ch1,i,data;
    create();
    printf("MENU\n1.Insertion\n2.Delete at i\n3.Display\n4.Exit\n");
    do{
        printf("\nEnter your option:\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\n1.Insert at beg\n2.Insert at end\n3.Insert at i\n");
            scanf("%d",&ch1);

            if(ch1 == 1){
                printf("Enter data\n");
                scanf("%d",&data);
                insbeg(data);
                break;
            }
            else if(ch1 == 2){
                printf("Enter data\n");
                scanf("%d",&data);
                insend(data);
                break;
            }
            else if(ch1 == 3){
                printf("Enter i\n");
                scanf("%d",&i);
                printf("Enter data\n");
                scanf("%d",&data);
                insert(i,data);
                break;
            }
            else{
                printf("Invalid option\n");
                break;
            }
        case 2:
            printf("Enter i:\n");
            scanf("%d",&i);
            del(i);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid option\n");
            break;
        }
    }while(ch != 4);

    return 0;
}
