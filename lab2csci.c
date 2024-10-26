#include <stdio.h>
#include <stdbool.h>

/* Order numbers */
#define ESPRESSO 1/*define the order numbers for Espresso*/
#define CAPPUCCINO 2/*define the order numbers for Cappuccino*/
#define MOCHA 3/*define the order numbers for Mocha*/

/* Admin password */
#define ADMIN_PASSWORD 20050607/*define the ademin password to access*/

/* Coffee Beans (grams) */
#define ESPRESSO_BEAN 8/*define the beans of Espresso*/
#define CAPPUCCINO_BEAN 8/*define the beans of Cappuccino*/
#define MOCHA_BEAN 8 /*define the beans of Mocha*/

/* Water (milliliters) */
#define ESPRESSO_WATER 30/*define the water of Espresso*/
#define CAPPUCCINO_WATER 30/*define the water of Cappuccino*/
#define MOCHA_WATER 30/*define the water of Mocha*/

/* Milk (milliliters) */
#define CAPPUCCINO_MILK 70/*define the milk of Cappucino*/
#define MOCHA_MILK 160/*define the milk of Mocha*/

/* Chocolate Syrup (milliliters) */
#define ESPRESSO_CHOCOLATE 0/*define the Chocolate Syrup of Espresso*/
#define CAPPUCCINO_CHOCOLATE 0/*define the Chocolate Syrup of Cappuccino*/
#define MOCHA_CHOCOLATE 30/*define the Chocolate Syrup of Mocha*/

/* Price (AED) */
float espresso_price = 3.5;/*it is global value so that we can change it in following coding*/
float cappuccino_price = 4.5;/*it is global value so that we can change it in following coding*/
float mocha_price = 5.5;/*it is global value so that we can change it in following coding*/

/* Total materials */
float beans = 300.0;/*it is global value so that it will be updated in following coding*/
float water = 400.0;/*it is global value so that it will be updated in following coding*/
float milk = 500.0;/*it is global value so that it will be updated in following coding*/
float chocolate = 600.0;/*it is global value so that it will be updated in following coding*/

float total_amount = 0.0;/*it is global value so that it will be updated in following coding*/

/* Low threshold */
#define BEAN_LOW_THRESHOLD 10
#define WATER_LOW_THRESHOLD 50
#define MILK_LOW_THRESHOLD 70
#define CHOCOLATE_LOW_THRESHOLD 25
/*function prototype*/
void order_coffee();
void admin();
void display_total_amount();
void display_ingredient_totals();
void change_price();
/*this is centrol function, whith contrls Order_coffee() and damin()*/
int main() {
    printf("Order coffee (1) | Admin mode (2) | End the application execution (3)\n");
    int option;
    while (1) {/*while loop will keep running until users input "exist"*/
        printf("Enter your option (digits): ");
        scanf("%d", &option);
        
        if (option == 1) {
            order_coffee();/* Calls function to order coffee*/
        } else if (option == 2) {
            admin();/* Calls function to admin*/
        } else if (option == 3) {
            puts("Exiting the application.");
            break;/*Exits the program*/
        } else {
            puts("Invalid option. Please try again.");
        }
    }
    return 0;/*Returns zero to indicate successful execution*/
}
/*function definition for order_coffee*/
void order_coffee() {
    while (1) {
        int choice;
        printf("Espresso 3.5 AED (1); Cappuccino 4.5 AED (2); Mocha 5.5 AED (3)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        float price = 0;
        float beans_needed = 0, water_needed = 0, milk_needed = 0, chocolate_needed = 0;
        
        switch (choice) {/*‘switch’ will execute the code in the case corresponding to the option value.*/
            case 1:
                price = espresso_price;/*update the price for how much you spend*/
                beans_needed = ESPRESSO_BEAN;/*update how many beans will be used.*/
                water_needed = ESPRESSO_WATER;/*update how much water will be used.*/
                chocolate_needed = ESPRESSO_CHOCOLATE;/*update how much chocolate will be used.*/
                break;/*Exits the switch statement*/
            case 2:
                price = cappuccino_price;/*update the price for how much you spend*/
                beans_needed = CAPPUCCINO_BEAN;/*update how many beans will be used.*/
                water_needed = CAPPUCCINO_WATER;/*update how much water will be used.*/
                milk_needed = CAPPUCCINO_MILK;/*update how much milk will be used.*/
                chocolate_needed = CAPPUCCINO_CHOCOLATE;/*update how much chocolate will be used.*/
                break;/*Exits the switch statement*/
            case 3:
                price = mocha_price;/*update the price for how much you spend*/
                beans_needed = MOCHA_BEAN;/*update how many beans will be used.*/
                water_needed = MOCHA_WATER;/*update how much water will be used.*/
                milk_needed = MOCHA_MILK;/*update how much milk will be used.*/
                chocolate_needed = MOCHA_CHOCOLATE;/*update how much chocolate will be used.*/
                break;/*Exits the switch statement*/
            default:
                puts("Invalid option. Please come back.");
                continue;/*It allows the user to re-enter their choices immediately after entering an invalid option.*/
        }

        printf("You selected: %d, Price: %.2f AED\n", choice, price);
        /*check if ingredients are not enough.*/
        if (beans < beans_needed || water < water_needed || milk < milk_needed || chocolate < chocolate_needed) {
            printf("Not enough ingredients. Please contact staff.\n");
            continue;/*Causes the program to skip any remaining code in the current iteration of the loop and jump back to the beginning of the loop*/
        }

        beans -= beans_needed;/*Deducts the required amount of coffee beans from the total available.*/
        water -= water_needed;/*Deducts the required amount of water from the total available.*/
        milk -= milk_needed;/*Deducts the required amount of milk from the total available.*/
        chocolate -= chocolate_needed;/*Deducts the required amount of chocolate from the total available.*/

        float payment = 0;
        while (payment < price) {/*'whil'loop will keep running untill payment>=price*/
            float coin;
            printf("Enter your coins (1 AED or 0.5 AED): ");
            scanf("%f", &coin);  
            
            payment += coin;/*update payment*/
            if (payment < price) {
                printf("You still need to insert %.2f AED\n", price - payment);
            }
        }

        printf("Payment accepted. Your order is ready!\n");
        total_amount += price;/*update total_amount*/
        printf("Your payment of %.2f AED has been added to total sales.\n", price);
        break; /*exsit this loop*/
    }
}
/*function definition */
void admin() {
    int password;
    printf("Please input admin password:\n");
    printf("Enter the password: ");
    scanf("%d", &password);
    
    if (password != ADMIN_PASSWORD) {/*Check if the entered password matches the predefined admin password*/
        printf("The password is incorrect.\n");
        return;
    }
/*Start an infinite loop for admin options*/
    while (1) {
        printf("1. Display ingredient quantities and total sales amount\n");
        printf("2. Replenish ingredients\n");
        printf("3. Change coffee price\n");
        printf("4. Exit\n");
        printf("5. Reset total sales amount\n");
        
        int option;/*Declare a variable to store the user's choice*/
        printf("Enter your option: ");
        scanf("%d", &option);/*Read the user's choice*/
        
        switch (option) {
            case 1:
                display_ingredient_totals();/*/ Call the function to display ingredient totals and sales*/
                break;
            case 2:/*Exit the switch statement*/
                puts("Replenishing ingredients is not implemented yet.");
                break;/*Exit the switch statement*/
            case 3:
                change_price();/* Call the function to change coffee prices*/
                break;/*Exit the switch statement*/
            case 4:
                puts("Exiting admin mode.");
                return;/*Exit the admin function*/
            case 5:
                total_amount = 0.0;/*Reset the total sales amount to zero*/
                printf("Total sales amount has been reset to zero.\n");
                break;/*Exit the admin function*/
            default:
                puts("Invalid option. Please try again.");
                break;/*Exit the admin function*/
        }
    }
}

void display_ingredient_totals() {
    printf("Ingredient quantities:\n");
    printf("Beans: %.2f grams\n", beans);/*Display the current amount of beans*/
    printf("Water: %.2f mL\n", water);/*Display the current amount of water*/
    printf("Milk: %.2f mL\n", milk);/*Display the current amount of milk*/
    printf("Chocolate: %.2f mL\n", chocolate);/*Display the current amount of chocolate*/
    printf("Total amount from sales: %.2f AED\n", total_amount);/*Display the total sales amount*/
}

void change_price() {
    int coffee_choice;
    float new_price;
    printf("Which coffee's price do you want to change? Espresso (1) Cappuccino (2) Mocha (3)\n");
    printf("Enter coffee number: ");
    scanf("%d", &coffee_choice);
    
    switch (coffee_choice) {
        case 1:
            printf("Enter new price for Espresso: ");/*Prompt for the new price*/
            scanf("%f", &new_price);/* Read the new price*/
            espresso_price = new_price;/*Update the espresso price with the new value*/
            break;/* Exit the switch statement*/
        case 2:
            printf("Enter new price for Cappuccino: ");/*Prompt for the new price*/
            scanf("%f", &new_price);/* Read the new price*/
            cappuccino_price = new_price;/*Update the espresso price with the new value*/
            break;/* Exit the switch statement*/
        case 3:
            printf("Enter new price for Mocha: ");/*Prompt for the new price*/
            scanf("%f", &new_price);/* Read the new price*/
            mocha_price = new_price;/*Update the espresso price with the new value*/
            break;/* Exit the switch statement*/
        default:
            puts("Not a valid choice.");
            break;/* Exit the switch statement*/
    }
}
