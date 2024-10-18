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
/*define what each part of the program does*/
void order_coffee();
void admin();
void display_total_amount();
void display_ingredient_totals();
void change_price();
/*he central control loop for the program, allowing users to interact with the coffee ordering system or administrative mode. */
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
        scanf("%d", &choice);/*store your choice*/
        /*define original numbers for after updating */
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
        beans -= beans_needed;/*when you finish order a cup of coffee, the beans will be updated.*/
        water -= water_needed;/*when you finish order a cup of coffee, the water will be updated.*/
        milk -= milk_needed;/*when you finish order a cup of coffee, the milk will be updated.*/
        chocolate -= chocolate_needed;/*when you finish order a cup of coffee, the chocolate will be updated.*/

        /*how to pay*/
        float payment = 0;/*define an original number for after updating.*/
        while (payment < price) {
            float coin;
            printf("Enter your coins (1 AED or 0.5 AED): ");
            scanf("%f", &coin);  
        /*let user insert a coint again and agian untill payment=coin*/
            payment += coin;
            if (payment < price) {
                printf("You still need to insert %.2f AED\n", price - payment);
            }
        }

        printf("Payment accepted. Your order is ready!\n");
        beans -= beans_needed;/*when you finish order a cup of coffee, the beans will be updated.*/
        water -= water_needed;/*when you finish order a cup of coffee, the water will be updated.*/
        milk -= milk_needed;/*when you finish order a cup of coffee, the milk will be updated.*/
        chocolate -= chocolate_needed;/*when you finish order a cup of coffee, the chocolate will be updated.*/
        total_amount += price;/*update the total_amount for the next loop.*/
        printf("Your payment of %.2f AED has been added to total sales.\n", price);
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
        /*allows the admin to perform various tasks based on their input.*/
        switch (option) {/*corresponds to a different action*/
            case 1:
                display_ingredient_totals();
                break;
            case 2:
                /*if ingredients are enough it will be showed.*/
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
/**/
void display_ingredient_totals() {
    printf("Ingredient quantities:\n");
    printf("Beans: %.2f grams\n", beans);
    printf("Water: %.2f mL\n", water);
    printf("Milk: %.2f mL\n", milk);
    printf("Chocolate: %.2f mL\n", chocolate);
    printf("Total amount from sales: %.2f AED\n", total_amount);
    
}

void change_price() {
    int coffee_choice;
    float new_price;
    printf("Which coffee's price do you want to change? Espresso (1) Cappuccino (2) Mocha (3)\n");
    printf("Enter coffee number: ");
    scanf("%d", &coffee_choice);
    
    switch (coffee_choice) {
        case 1:
            printf("Enter new price for Espresso: ");
            scanf("%f", &new_price);
            espresso_price = new_price;/*update a new price.*/
            break;
        case 2:
            printf("Enter new price for Cappuccino: ");
            scanf("%f", &new_price);
            cappuccino_price = new_price;/*update a new price.*/
            break;
        case 3:
            printf("Enter new price for Mocha: ");
            scanf("%f", &new_price);
            mocha_price = new_price;/*update a new price.*/
            break;
        default:
            puts("Not a valid choice.");
            break;
    }
}
