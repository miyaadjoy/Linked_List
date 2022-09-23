#include <stdio.h>
#include <stdlib.h>
struct list
{
    struct list* next;
    int data;
};
typedef struct list node;

//head and tail node is declared

node* head = NULL;
node* tail = NULL;
node* createNode()
{
    node* anode;
    anode = (node *) malloc(sizeof (node));
    anode->next = NULL;
    return anode;

}

void createList(int data)
{
    //a new node is created
    node* new_node = createNode();
    new_node->data = data;



    //if the list has no element yet
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }

        //if the list have element(s)
    else
    {
        tail->next = new_node;
        tail = new_node;
    }




}
void printList()
{
    printf("The list: \n");
    node* q;
    q = head;

    while(q)
    {
        printf("%d\t",q->data);
        q = q->next;
    }
    printf("\n");

}
void enterValue(int b_value, int data)
{

    node* new_node = createNode();
    new_node->data = data;
    node* p = head;
    while(p)
    {
        if(p->data == b_value)
        {
            break;
        }

        p = p->next;
    }
    if(p == NULL)
        printf("Invalid value given!\n");
    else
    {
        if(p->next == NULL)
            tail = new_node;
        new_node->next = p->next;
        p->next = new_node;
    }

}

void deleteValue(int value)
{
    node* p = head;
    node* q;
    int position = 0;

    while(p)
    {

        if(value == p->data)
        {
            position++;
            break;
        }
        q = p;
        p = p->next;
    }
    if(p != NULL)
    {
        if(position == 1)
        {
            head = head->next;

        }
        else q->next = q->next->next;

    }
    else printf("The value is not found: \n");

}

void reverseList()
{

    node* p;
    node* q;
    node* r;
    p = head;
    r = head;
    q = NULL;

    while (r)
    {
        q = p;
        p = r;
        r = p->next;
        p->next = q;
    }
    node* temp;
    temp = head;
    head = tail;
    tail = temp;
    tail->next = NULL;
}
int main()
{

    main:
    printf("\t\t\t\t\t\t\tmain menu: \n");
    printf("\t\t\t\t\t\t*****************************\n\n\n");
    printf("[1] \tCreate a new Linked List\n");
    printf("[2] \tEnter a new value after a specific value: \n");
    printf("[3] \tDelete a specific value: \n");
    printf("[4] \tReverse a Linked List\n");
    printf("[5] \tPrint the Linked List\n");
    printf("[0] \tGo to main menu\n");
    int n;
    int data;
    int choice;
    int value;
    int bvalue;
    int dvalue;


    printf("\n");

    printf("Enter your choice: \n");
    scanf("%d",&n);

    switch(n)
    {
        case 0:
            goto main;


        case 1:
            //creating a list

            printf("Enter the values (-1 to exit): \n");
            while(1)
            {
                scanf("%d",&data);
                if(data == -1)
                    break;

                createList(data);
            }

            printf("do you want to exit or goto main menu: \n");
            printf("press [0] exit or [1] main menu \n");
            scanf("%d",&choice);
            if(choice == 0)
                break;
            else goto main;



        case 2:
            printf("Enter the value to add after: \n");
            scanf("%d",&bvalue);
            printf("Enter the value to add: \n");
            scanf("%d",&value);
            enterValue(bvalue, value);

            printf("do you want to exit or goto main menu: \n");
            printf("press [0] exit or [1] main menu \n");
            scanf("%d",&choice);
            if(choice == 0)
                break;
            else goto main;



        case 3:
            printf("Enter a value to delete: \n");
            scanf("%d",&dvalue);
            deleteValue(dvalue);

            printf("do you want to exit or goto main menu: \n");
            printf("press [0] exit or [1] main menu \n");
            scanf("%d",&choice);
            if(choice == 0)
                break;
            else goto main;




        case 4:

            reverseList();

            printf("do you want to exit or goto main menu: \n");
            printf("press [0] exit or [1] main menu \n");
            scanf("%d",&choice);
            if(choice == 0)
                break;
            else goto main;



        case 5:
            printList();
            printf("do you want to exit or goto main menu: \n");
            printf("press [0] exit or [1] main menu \n");
            scanf("%d",&choice);
            if(choice == 0)
                break;
            else goto main;


        default:break;

    }


}