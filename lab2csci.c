#include <stdio.h>
#include <stdbool.h>

/* Order numbers */
#define ESPRESSO 1
#define CAPPUCCINO 2
#define MOCHA 3

/* Admin password */
#define ADMIN_PASSWORD 20050607

/* Coffee Beans (grams) */
#define ESPRESSO_BEAN 8
#define CAPPUCCINO_BEAN 8
#define MOCHA_BEAN 8

/* Water (milliliters) */
#define ESPRESSO_WATER 30
#define CAPPUCCINO_WATER 30
#define MOCHA_WATER 30

/* Milk (milliliters) */
#define CAPPUCCINO_MILK 70
#define MOCHA_MILK 160

/* Chocolate Syrup (milliliters) */
#define ESPRESSO_CHOCOLATE 0
#define CAPPUCCINO_CHOCOLATE 0
#define MOCHA_CHOCOLATE 30

/* Price (AED) */
float espresso_price = 3.5;
float cappuccino_price = 4.5;
float mocha_price = 5.5;

/* Total materials */
float beans = 300.0;
float water = 400.0;
float milk = 500.0;
float chocolate = 600.0;

float total_amount = 0.0;

/* Low threshold */
#define BEAN_LOW_THRESHOLD 10
#define WATER_LOW_THRESHOLD 50
#define MILK_LOW_THRESHOLD 70
#define CHOCOLATE_LOW_THRESHOLD 25

void order_coffee();
void admin();
void display_total_amount();
void display_ingredient_totals();
void change_price();

int main(void) {
    printf("Order coffee (1) | Admin mode (2) | End the application execution (3)\n");
    int option;
    while (1) {
        printf("Enter your option (digits): ");
        scanf("%d", &option);
        /* Order coffee */
        if (option == 1) {
            order_coffee();
        } else if (option == 2) {
            admin();
        } else if (option == 3) {
            puts("Exiting the application.");
            break;  /*break can let us exist this loop*/
        } else {
            puts("Invalid option. Please try again.");
        }
    }
    return 0;
}
/*update ingredients and updata total_selling*/
void order_coffee() {
    while (1) {
        int choice;
        printf("Espresso 3.5 AED (1); Cappuccino 4.5 AED (2); Mocha 5.5 AED (3)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        float price = 0;
        float beans_needed = 0, water_needed = 0, milk_needed = 0, chocolate_needed = 0;
        
        switch (choice) {
            case 1:
                price = espresso_price;/*update price*/
                beans_needed = ESPRESSO_BEAN;/*update how many beans that are already used.*/
                water_needed = ESPRESSO_WATER;/*update how much water that  was already used.*/
                chocolate_needed = ESPRESSO_CHOCOLATE;/*update how much chocolate that was already used.*/
                break;/*stop this loop*/
            case 2:
                price = cappuccino_price;/*update price*/
                beans_needed = CAPPUCCINO_BEAN;/*update how many beans that are already used.*/
                water_needed = CAPPUCCINO_WATER;/*update how much water that  was already used.*/
                milk_needed = CAPPUCCINO_MILK;/*update how much milk that was already used.*/
                chocolate_needed = CAPPUCCINO_CHOCOLATE;/*update how much chocolate that was already used.*/
                break;/*stop this loop*/
            case 3:
                price = mocha_price;/*update price*/
                beans_needed = MOCHA_BEAN;/*update how many beans that are already used.*/
                water_needed = MOCHA_WATER;/*update how much water that  was already used.*/
                milk_needed = MOCHA_MILK;/*update how much milk that was already used.*/
                chocolate_needed = MOCHA_CHOCOLATE;/*update how much chocolate that was already used.*/
                break;/*stop this loop*/
            default:
                puts("Invalid option. Please come back.");
                continue;  /*return back this loop*/
        }

        printf("You selected: %d, Price: %.2f AED\n", choice, price);
        
        /*check if ingredients are enough.if any things are not enough, it will alarm.*/
        if (beans < beans_needed || water < water_needed || milk < milk_needed || chocolate < chocolate_needed) {
            printf("Not enough ingredients. Please contact staff.\n");
            continue; /*return back this loop.*/
        }

        /*update ingredients*/
        beans -= beans_needed;
        water -= water_needed;
        milk -= milk_needed;
        chocolate -= chocolate_needed;

        /*how to pay*/
        float payment = 0;
        while (payment < price) {
            float coin;
            printf("Enter your coins (1 AED or 0.5 AED): ");
            scanf("%f", &coin);  

            payment += coin;
            if (payment < price) {
                printf("You still need to insert %.2f AED\n", price - payment);
            }
        }

        printf("Payment accepted. Your order is ready!\n");
        break; 
    }
    }



void admin() {
    int password;
    printf("Please input admin password:\n");
    printf("Enter the password: ");
    scanf("%d", &password);
    
    if (password != ADMIN_PASSWORD) {/*the password is not correct.*/
        printf("The password is incorrect.\n");
        return;/*return back this loop.*/
    }
   /*show the main page to choose*/
    while (1) {
        printf("1. Display ingredient quantities and total sales amount\n");
        printf("2. Replenish ingredients\n");
        printf("3. Change coffee price\n");
        printf("4. Exit\n");
        int option;/*choose one of functions*/
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                display_ingredient_totals();
                break;
            case 2:
                /*if you didn't to order coffee at first.this line will not show.*/
                puts("Replenishing ingredients is not implemented yet.");
                break;
            case 3:
                change_price();
                break;
            case 4:
                puts("Exiting admin mode.");
                return; /*exist */
            default:
                puts("Invalid option. Please try again.");
                break;
        }
    }
}
