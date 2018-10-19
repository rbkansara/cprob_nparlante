/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node * BuildList();
void push (struct node **headRef, int newdata);
int Length(struct node* head);

int Count(struct node *head, int searchfor);
int GetNth(struct node* head, int index);
void DeleteList(struct node** headRef);
int Pop(struct node** headRef);
void InsertNth(struct node** headRef, int index, int data);

void countTest();
void GetNthTest();
void deleteListTest();
void PopTest();
void InsertNthTest();

//Utility Functions
struct node * BuildList()
{
    struct node* head = NULL;
    push(&head,3);
    //push(&head,2);
    push(&head,1);
    //push(&head,4);
    
    return(head);
}
void push (struct node **headRef, int newdata)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    //newNode->next = (struct node*)malloc(sizeof(node));
    
    newNode->value = (int)newdata;
    newNode->next = (*headRef);
    (*headRef) = newNode;
    //free(newNode);
}

int Length(struct node* head)
{
    int count = 0;
    struct node* current = head;
    
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

int main()
{
    //printf("Hello World \n");
    countTest();  //Problem1
    GetNthTest(); //Problem2
    deleteListTest(); //Problem3
    PopTest();    // Problem4
    InsertNthTest();  //Problem5
    
    return 0;
}

/*Problem1 Count */
void countTest()
{
    struct node* MyList;
    int count;
    
    MyList = BuildList();
    count = Count(MyList,2);
    printf("Count = %d \n", count);
    free(MyList);
}

int Count(struct node* head, int searchfor)
{
    int countOcc = 0;
    
    while(head->next!=NULL)
    {
        if(head->value == searchfor)
            countOcc++;
        head = head->next;
    }
    return countOcc;
}

/* Problem2 : GetNth */
void GetNthTest()
{
    struct node* MyList1;
    
    MyList1 = BuildList();
    int lastNode = GetNth(MyList1,2);
    printf("Nth Index value = %d \n", lastNode);
    free(MyList1);
}

int GetNth(struct node* head, int index)
{
    for(int i=0; i<index; i++)
    {
        head = head->next;
    }
    
    return head->value;
}

/*Problem3 : DeleteList*/
void deleteListTest()
{
    struct node* MyList = BuildList();
    DeleteList(&MyList);
    printf("List pointer: %d \n",MyList);
    free(MyList);
}

void DeleteList(struct node** headRef)
{
    struct node* current = *headRef;
    struct node* nextNode;
    
    while(current !=NULL)
    {
        nextNode = current->next;
        free(current);
        current=nextNode;
    }
    *headRef=NULL;
}

/*Problem4 : Pop*/
void PopTest()
{
    struct node* head = BuildList();
    int a = Pop(&head);
    int len = Length(head);
    printf("Pop data : %d \n",a);
    printf("Length of List: %d \n",len);
}
int Pop(struct node** headRef)
{
    struct node* current = *headRef;
    
    *headRef = current->next;
    int a = current->value;
    free(current);
    
    return a;
}

/*Problem5 : InsertNth*/
void InsertNthTest()
{
    struct node* head = NULL;
    InsertNth(&head, 0, 13);
    InsertNth(&head, 1, 42);
    InsertNth(&head, 1, 5);
    
    while(head!=NULL) {
        printf("%d->",head->value);
        head=head->next;
    }
    printf("NULL\n");
    DeleteList(&head);
}
void InsertNth(struct node** headRef, int index, int data)
{
    struct node* head = *headRef;
    int i;
    
    if(index==0)
        push(headRef,data);
    else {
        for (i=0; i<index-1; i++)
        {
            //assert(head!=NULL);
            head = head->next;
        }
        //assert(head!=NULL);
        push(&(head->next), data);
    }
}

/*Problem6 : SortedInsert*/
void sortedInsertTest()
{
    struct node* head = BuildList();
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->value=2;
    
    SortedInsert(&headRef, newNode);
    
    
}
void SortedInsert(struct node** headRef, struct node* newNode)
{
    
}
