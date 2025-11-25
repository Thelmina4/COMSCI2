#include<stdio.h>
#include<stdlib.h>

typedef struct Product Product;

struct Product
{
    char name[50];
    int amount;
    float price;
};


int main()
{
    Product *pProduct;
    int capacity = 3; /* We just initilly allocate enough memory for storing 3 products. If users want more than that, we will reallocate later */
    pProduct = (Product*)calloc(capacity,sizeof(Product)); /*allocate initial memory */
    if(!pProduct) /* Check if the allocation is successful */
    {
        printf("Not enough memory. Exiting...\n");
        free(pProduct);
        pProduct = NULL;
        exit(0);
    }

    int count = 0;     /* count the number of products which are entered by the user at runtime */
    int userSelection = 1;  /* Use to check the user's decision, 1 = continue to enter the product, 0 = otherwise */
    while(userSelection != 0)
    {
        if(userSelection == 0)
        {
            break; /*if user doest want to enter the data, we stop the entering procedure */
        }

        if(count == capacity)   /*if the users already entered and use all allocated memory, we have to reallocate to ask for more memory */
        {
            Product *pTemp;
            capacity += 10;
            pTemp = (Product*)realloc(pProduct, capacity*sizeof(Product));
            if(!pTemp)  /* Check if the re-allocation is successful */
            {
                printf("Unfortunately memory reallocation failed. Exiting...\n");
                free(pProduct);
                pProduct = NULL;
                exit(0);
            }
            pProduct = pTemp;
        }

        printf("Enter the product:\n");
        printf("Product name:\n");
        scanf("%s", (pProduct+count)->name);
        printf("Amount:\n");
        scanf("%d", &(pProduct+count)->amount);
        printf("Price:\n");
        scanf("%f", &(pProduct+count)->price);
        count++;

        printf("Do you want to add more product (1/0)?");
        scanf("%d", &userSelection);
    }

    /* Display the entered data */

    for(int i = 0; i < count; ++i)
    {
        printf("-----------------------");
        printf("Product #%d:\n", i + 1);
        printf("Name: %s\n", (pProduct+i)->name);
        printf("Amount: %d\n", (pProduct+i)->amount);
        printf("Price: %.2f\n", (pProduct+i)->price);
    }

    /*release the memory */
    free(pProduct);
    pProduct = NULL;
    return 0;
}