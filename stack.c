#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int element;
    struct stack *next;
}*top;

void push(int);
void pop();
void display();

void main()
{
    int num1,num2,choice;
    printf("\tMENU\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
    while(choice!=4)
    {
       printf("\nEnter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        {
            printf("\nEnter the element:");
            scanf("%d",&num1);
            push(num1);
            break;
        }
       case 2:
        {
            pop();
            break;
        }
       case 3:
        {
            display();
            break;
        }
       case 4:
        {
            break;
        }
       default:
        {
            printf("Invalid choice");
            break;
        }
       }
    }
}
void push(int value)
{
    struct stack *ptr;
    ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->element=value;
    ptr->next=top;
    top=ptr;
}
void pop()
{
    int num2;
    if(top==NULL)
    {
        printf("\nStack is empty");
    }
    else{
        num2=top->element;
        top=top->next;
        printf("\nRemoved element is %d",num2);
    }
}
void display()
{
    struct stack *ptr1=NULL;
    ptr1=top;

    printf("\nThe elements are");

    while(ptr1!=NULL)
    {
        printf("%d ", ptr1->element);
        ptr1=ptr1->next;
    }
}
