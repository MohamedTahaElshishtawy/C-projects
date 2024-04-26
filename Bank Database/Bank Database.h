#ifndef BANK_DATABASE_H_INCLUDED
#define BANK_DATABASE_H_INCLUDED
typedef struct customer
{
    char name[50];
    double cash ;
    char type[7];
    int id;
}customer_t;

void create_new_customer(void); //done
void edit_customer(int id); //done
void print_customer_data(int id); //done
void transfer_money(int source_id,int destination_id,double money);//done
void delete_customer_data(int id);


#endif
