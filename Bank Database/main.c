#include <stdio.h>
#include <stdlib.h>
#include "Bank Database.h"

int cnt = 0;
customer_t arr[3];
int main()
{
    char choice;
    int id_check;
    int id_from;
    int id_to;
    double money_transfer;
    while(1)
    {


        printf("please select one of the following options :\n\n1-create anew customer (press 1 to select this option)\n2-edit customer (press 2 to select this option )\n3-print customer data (press 3 to select this option)\n4-cash transfer from customer to another (press 4 t select this option)\n5-delete customer (press 5 to select this option)\n6-exit (press 6 to select this option)\n\nplease enter your choice:");
        fflush(stdin);
        scanf("%c",&choice);
        printf("\n\n");
        switch(choice)
        {
        case '1' :
            if(cnt>3)
            {
                printf("the maximum number of customers is 2 so you can't add anymore\n");
                break ;
            }
            create_new_customer();
            break ;

        case '2' :
            printf("please enter the id of the customer who you need to change its data :");
            scanf("%d",&id_check);
            edit_customer(id_check) ;
            break ;

        case '3' :
            printf("please enter the id of the customer who you need to print its data :");
            scanf("%d",&id_check);
            print_customer_data(id_check) ;
            break;

        case '4' :
            printf("please enter the id of the customer who the money will transfer from his cash  :");
            scanf("%i",&id_from);
            printf("please enter the id of the customer who the money will transfer to his cash  :");
            scanf("%i",&id_to);

L2:
            printf("please enter the money which will be transfered  :");
            scanf("%lf",&money_transfer);
            if(money_transfer<=0)
            {
                printf("the money transfered should be positive number and greater than zero please try again\n");
                goto L2 ;
            }
            transfer_money(id_from,id_to,money_transfer);
            break;

        case '5' :
            printf("please enter the id of the customer who you need to delete its data :");
            scanf("%d",&id_check);
            delete_customer_data(id_check);
            break;

        case '6' :
            exit(0);

        default:
            printf("wrong choice\n\n");
        }

    }
    return 0;
}


