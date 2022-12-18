#include "library.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Member
1. นายธเนศ จอมพูล 65070501025
2. นางสาวอริยาภรณ์ สุดเสถียรธานนท์ 65070501060
3. นายอาณกร งานสุจริต 65070501089*/

/*โชว์เมนูการทำงานทั้งหมดของโปรแกรม และ return check; ไปให้ int main() */
char getSelectMenu() {
  printf("Menu\n");
  printf("1 - Add book\n");
  printf("2 - Remove book\n");
  printf("3 - Edit book\n");
  printf("4 - Show all book\n");
  printf("5 - Search book\n");
  printf("6 - Borrow book\n");
  printf("7 - Return book\n");
  printf("8 - Exit\n");
  char buffer[50];
  int check;
  printf("> ");
  fgets(buffer, 9, stdin);
  sscanf(buffer, "%d", &check);
  printf("\n");
  return check;
}

int main() {
  int amount = 0;
  readN_flie(&amount);
  DATEBOOK_T *readbook = (DATEBOOK_T *)calloc(amount, sizeof(DATEBOOK_T));
  int *ArrayBook = (int *)calloc(amount, sizeof(int));
  readArray(ArrayBook);
  testread_flie(readbook, ArrayBook);
  int menu;
  /*เช็ค menu กับ ค่าที่ user input เข้ามา*/
  while (menu != 8) {
    if (menu == 1) {
      add_book(readbook, &amount, ArrayBook, sizeof(DATEBOOK_T));
      printf("please Run Code again ;-;\n");
      return 0;
    } else if (menu == 2) {
      del_book(readbook, &amount,ArrayBook);
      printf("please Run Code again ;-;\n");
      return 0;
    } else if (menu == 3) {
      edit_book(readbook, amount, ArrayBook);
    } else if (menu == 4) {
      show_book(readbook, amount, ArrayBook);
    } else if (menu == 5) {
      search_book(readbook, amount, ArrayBook);
    } else if (menu == 6) {
      borrow_book(readbook, ArrayBook, amount);
    } else if (menu == 7) {
      return_book(readbook, ArrayBook, amount);
    }
    printf("\n");

    menu = getSelectMenu();
  }
  printf("Thank you");
  free(ArrayBook);
  free(readbook);
  return 0;
}