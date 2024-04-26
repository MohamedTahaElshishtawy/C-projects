#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Bank Database.h"

extern int cnt;
extern customer_t arr[3];

void create_new_customer()
{
    customer_t new_customer;

    printf("please enter the name of customer number %d:",cnt+1);
    fflush(stdin);
    gets(new_customer.name);

L2:
    printf("please enter the cash of customer number %d:",cnt+1);
    scanf("%lf",&new_customer.cash);
    if(new_customer.cash<=0)
    {
        printf("the cash should be positive number and greater than zero please try again\n");
        goto L2 ;
    }

    printf("please enter the type of customer number %d <debit or credit>:",cnt+1);
    fflush(stdin);
    gets(new_customer.type);

    printf("please enter the id of the customer number %d:",cnt+1);
    scanf("%d",&new_customer.id);


    arr[cnt] = new_customer;
    cnt++;
}

void print_customer_data(int id)
{
    int i = 0;
    while(i<=cnt)
    {
        if(id == arr[i].id)
        {
            printf("the name of customer number%d is :%s\n",i+1,arr[i].name);
            printf("the cash of customer number%d is :%lf\n",i+1,arr[i].cash);
            printf("the type id of customer number%d is :%s\n",i+1,arr[i].type);
            printf("the id of customer number%d is :%d\n",i+1,arr[i].id);
            break;
        }
        i++;
    }
}


void edit_customer(int id)
{
    int i = 0;
    while(i<=cnt)
    {
        if(id == arr[i].id)
        {
            printf("please enter the new name of customer number %d:",i+1);
            fflush(stdin);
            gets(arr[i].name);


            printf("please enter the new cash of customer number %d:",i+1);
            scanf("%lf",&arr[i].cash);

            printf("please enter the new type of customer number %d <debit or credit>:",i+1);
            fflush(stdin);
            gets(arr[i].type);

            printf("please enter the new id of the customer number %d:",i+1);
            scanf("%d",&arr[i].id);
        }
        i++;
    }
}

void transfer_money(int source_id,int destination_id,double money)
{

    for(int i = 0 ; i <= cnt ; i++)
    {
        char flag = 0;
        for(int j = 0 ; j <= cnt ; j++)
        {
            if(source_id == arr[i].id && destination_id == arr[j].id)
            {
                arr[i].cash = arr[i].cash-money;
                arr[j].cash = arr[j].cash+money;
                flag = 1;
            }
        }
        if(flag == 1)
        {
            flag=0;
            break;
        }
    }
}

void delete_customer_data(int id)
{
  int i;
  int index;
  for (i = 0; i < cnt; i++)
  {
    if (arr[i].id == id)
    {
      index = i;
      for (i = index; i < cnt ; i++)
      {
        arr[i] = arr[i + 1];       // shifting the customers
      }
    }
  }
  arr[cnt].cash = -1;          // -1 indicate this is empty place for new customer
  arr[cnt].id = -1;            // -1 indicate this is empty place for new customer
  strcpy(arr[cnt].name, "-1"); // -1 indicate this is empty place for new customer
  strcpy(arr[cnt].type, "-1"); // -1 indicate this is empty place for new customer
  cnt--;
}





