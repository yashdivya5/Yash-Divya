#include<stdio.h>
#include<string.h>
int main() {
   int choice, price;
   char o[100];
   printf("Enter 1 for Dell Vostro 13\nEnter 2 for HP Pavilion\nEnter 3 for Macbook Pro\nEnter 4 for Asus Zenbook\n");
   scanf("%d", &choice);
   switch (choice) {
      case 1:
         price = 130000;
         printf("The price of Dell Vostro 13 is %d\n", price);
         break;
      case 2:
         price = 96000;
         printf("The price of HP Pavilion is %d\n", price);
         break;
      case 3:
         price = 100000;
         printf("The price of Macbook Pro is %d\n", price);
         break;
      case 4:
         price = 230000;
         printf("The price of Asus Zenbook is %d\n", price);
         break;
      default:
         printf("Sorry! Laptop not available\n");
         return 0;
   }
   printf("Do you want a Graphics Card? (yes/no)\n");
   scanf("%s", o);
   if (strcmp(o, "yes") == 0) {
      price += 5000;
   }
   printf("Do you want a Hard Disk? (yes/no)\n");
   scanf("%s", o);
   if (strcmp(o, "yes") == 0) {
      price += 5000;
   }
   printf("Do you want Accessories? (yes/no)\n");
   scanf("%s", o);
   if (strcmp(o, "yes") == 0) {
      price += 2000;
   }
   printf("Total Price: Rs %d/-\n", price);
   return 0;
}
