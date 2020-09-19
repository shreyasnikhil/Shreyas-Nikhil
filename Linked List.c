#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert ();
void lastinsert ();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void main ()
{
    int choice =0;
    while(choice != 9)
    {
        printf("\n\n*********MAIN MENU*********\n");
        printf("\nCHOOSE ONE OPTION FROM THE GIVEN LIST ...\n");
        printf("\n===============================================\n");
        printf("\n1.INSTERT IN BEGINNING\n2.INSERT AT LAST\n3.INSERT AT ANY RANDOM LOCATION\n4.DELETE FROM BEGINNING\n5.DELETE FROM LAST\n6.DELETE NODE AT ANY RANDOM LOCATION\n7.SEARCH FOR AN ELEMENT\n8.SHOW\n9.EXIT\n");
        printf("\nENTER YOUR CHOICE : ");
        scanf("\n%d",&choice);
        switch(choice)
        {
            case 1:
            beginsert();
            break;
            case 2:
            lastinsert();
            break;
            case 3:
            randominsert();
            break;
            case 4:
            begin_delete();
            break;
            case 5:
            last_delete();
            break;
            case 6:
            random_delete();
            break;
            case 7:
            search();
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf("\nPLEASE ENTER VALID CHOICE\n");
        }
    }
}
void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node *));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nENTER ELEMENT VALUE : ");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNODE INSERTED\n");
    }

}
void lastinsert()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nENTER ELEMENT VALUE : ");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL)
        {
            ptr -> next = NULL;
            head = ptr;
            printf("\nNODE INSERTED\n");
        }
        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNODE INSERTED\n");

        }
    }
}
void randominsert()
{
    int i,loc,item;
    struct node *ptr, *temp;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nENTER ELEMENT VALUE : ");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nENTER THE LOCATION AFTER WHICH YOU WANT TO INSERT : ");
        scanf("%d",&loc);
        temp=head;
        for(i=0;i<loc;i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\nCAN'T INSERT\n");
                return;
            }

        }
        ptr ->next = temp ->next;
        temp ->next = ptr;
        printf("\nNODE INSERTED\n");
    }
}
void begin_delete()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNODE DELETED FROM THE BEGINNING\n");
    }
}
void last_delete()
{
    struct node *ptr,*ptr1;
    if(head == NULL)
    {
        printf("\nLIST IS EMPTY\n");
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nONLY NODE OF THE LIST DELETED\n");
    }

    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDELETED NODE FROM THE LAST\n");
    }
}
void random_delete()
{
    struct node *ptr,*ptr1;
    int loc,i;
    printf("\nENTER THE LOCATION AFTER WHICH YOU WANT TO DELETE : ");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\nCAN'T DELETE\n");
            return;
        }
    }
    ptr1 ->next = ptr ->next;
    free(ptr);
    printf("\nDELETED NODE %d\n",loc+1);
}
void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEMPTY LIST\n");
    }
    else
    {
        printf("\nENTER ITEM WHICH YOU WANT TO SEARCH : ");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\nITEM FOUND AT LOCATION %d\n",i+1);
                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("\nITEM NOT FOUND\n");
        }
    }

}

void display()
{
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nNOTHING TO PRINT\n");
    }
    else
    {
        printf("\nPRINTING VALLUES\n");
        while (ptr!=NULL)
        {
            printf("\n+--+--+\n");
            printf("|  %d  |",ptr->data);
            printf("\n+--+--+\n");
            printf("   |\n");
            printf("  \\/");
            ptr = ptr -> next;
        }
        printf("\n+--+--+\n");
	    printf("| NULL|");
	    printf("\n+--+--+\n");
    }
}
