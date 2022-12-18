# Final Project CPE100 (1/65) :computer:
### **Member**
1. นายธเนศ จอมพูล 65070501025
2. นางสาวอริยาภรณ์ สุดเสถียรธานนท์ 65070501060
3. นายอาณกร งานสุจริต 65070501089

### **Introduction**
โปรเจคนี้เป็นการเขียนโปรแกรมเพื่อส่งเป็น Final Project ในรายวิชา CPE100 (1/65)

โปรแกรมนี้เป็นโปรแกรมสําหรับจัดการฐานข้อมูลหนังสือในห้องสมุดที่มีฟังก์ชันการทํางานดังนี้
1. สามารถเพิ่ม-ลบหนังสือในห้องสมุดได้ 
2. สามารถแก้ไขรายละเอียดของหนังสือ (ชื่อหนังสือ, ชื่อผู้แต่ง, ปีที่พิมพ์) ได้ 
3. สามารถค้นหาหนังสือจากชื่อหนังสือและ/หรือชื่อผู้แต่งได้ 
4. มีระบบการยืม-คืนหนังสือ โดยไม่จํากัดจํานวนครั้งในการยืม-คืนของหนังสือแต่ละเล่ม 
5. จัดเก็บข้อมูลลงไฟล์โดยอัตโนมัติโดยเมื่อเปิด-ปิดโปรแกรมใหม่รายละเอียดหนังสือและรายการยืมคืนทั้งหมด
จะต้องยังคงอยู่ 

### **เมื่อทดลองใช้โปรแกรมจะมีหน้าต่างดังนี้ขึ้นมา**
```
Menu
1 - Add book
2 - Remove book
3 - Edit book
4 - Show all book
5 - Search book
6 - Borrow book
7 - Return book
8 - Exit
>
```
ในช่องของ
```
> มีไว้เพื่อใส่ตัวเลขเมนูที่ต้องการจะให้โปรแกรมทำงาน
```
```
Menu
1 - Add book
2 - Remove book
3 - Edit book
4 - Show all book
5 - Search book
6 - Borrow book
7 - Return book
8 - Exit
> 1
```
เป็นการสั่งให้โปรแกรมทำหน้าที่เพิ่มหนังสือที่ต้องการเพิ่ม

```
Menu
1 - Add book
2 - Remove book
3 - Edit book
4 - Show all book
5 - Search book
6 - Borrow book
7 - Return book
8 - Exit
> 2
```
เป็นการสั่งให้โปรแกรมทำหน้าที่ลบหนังสือที่ต้องการลบ

```
Menu
1 - Add book
2 - Remove book
3 - Edit book
4 - Show all book
5 - Search book
6 - Borrow book
7 - Return book
8 - Exit
> 3
```
เป็นการสั่งให้โปรแกรมทำหน้าที่ปรับแต่งข้อมูลหนังสือเล่มที่ต้องการ

```
Menu
1 - Add book
2 - Remove book
3 - Edit book
4 - Show all book
5 - Search book
6 - Borrow book
7 - Return book
8 - Exit
> 4
```
เป็นการสั่งให้โปรแกรมทำหน้าที่แสดงหนังสือและข้อมูลหนังสือทั้งหมดที่มีอยู่ในระบบ

```
Menu
1 - Add book
2 - Remove book
3 - Edit book
4 - Show all book
5 - Search book
6 - Borrow book
7 - Return book
8 - Exit
> 5
```
เป็นการสั่งให้โปรแกรมทำหน้าที่ค้นหาหนังสือเล่มที่ต้องการจากชื่อหนังสือและผู้แต่ง

```
Menu
1 - Add book
2 - Remove book
3 - Edit book
4 - Show all book
5 - Search book
6 - Borrow book
7 - Return book
8 - Exit
> 6
```
เป็นการสั่งให้โปรแกรมทำหน้าที่ทำการยืมหนังสือที่ผู้ใช้ต้องการ

```
Menu
1 - Add book
2 - Remove book
3 - Edit book
4 - Show all book
5 - Search book
6 - Borrow book
7 - Return book
8 - Exit
> 7
```
เป็นการสั่งให้โปรแกรมทำหน้าที่ทำการคืนหนังสือที่ผู้ใช้ต้องการ

```
Menu
1 - Add book
2 - Remove book
3 - Edit book
4 - Show all book
5 - Search book
6 - Borrow book
7 - Return book
8 - Exit
> 8
```
เป็นการสั่งให้ปิดโปรแกรม
### **Directory**

|File|หน้าที่|
| ---- | ---- | 
|main.c|โชว์เมนูการทำงานทั้งหมดของโปรแกรม, เลือก function ในการทำงาน|
|library.c|เขียนข้อความลง txt file, บันทักการทำงานของ function|
|library.h|มีไว้เพื่อเก็บ function ต่างๆ| 
|test.txt|ใช้เก็บข้อมูลหนังสือทั้งหมด|


--------------------
### **main.c**
การทำงานของไฟล์ main.c ทำหน้าที่ run function

```c
#include "library.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
```
ส่วนของ function `getSelectMenu` ทำหน้าที่ โชว์เมนูการทำงานทั้งหมดของโปรแกรม และ return check; ไปให้ function `int main()`  

**ส่วนของ int main()**
```c
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
```
ทำหน้าที่ รับค่า `check ที่ user input` เข้ามาไปเพื่อ `เลือก function` ในการทำงาน

--------------------

### **library.c**
การทำงานของไฟล์ `library.c` ทำหน้าที่เขียนข้อความลง `file.txt`, บันทึกการทำงานของ function

**ส่วนของ function write_f**
```c
void write_f(DATEBOOK_T *book, int *arr, int amount) {
  FILE *fptr;
  fptr = fopen("test.txt", "w"); 
  for (int i = 0; i < amount; i++) {
    fprintf(fptr, "%s%s%s%s%s", book[i].Name_book, book[i].Author, book[i].Year,
            book[i].Status, book[i].BorrowStatus);
    for (int j = 0; j < arr[i]; j++) {
      fprintf(fptr, "%s", book[i].Borrow[j]);
    }
    fprintf(fptr, "\n");
  }
  fclose(fptr);
}
```
function นี้จะเป็นการเปิดไฟล์ `test.txt` เพื่อที่จะทำการเขียนข้อความใหม่ลงไปในไฟล์ `test.txt` โดยที่`เข้าลูป for` เพื่อรับค่าของหนังสือ โดยที่ค่าทั้งหมดที่เขียนนั้นจะประกอบด้วย
- ชื่อของหนังสือ (book[i].Name_book)
- ชื่อของผู้แต่ง (book[i].Author)
- ปีที่ทำการพิมพ์ (book[i].Year)
- การยืม-คืนหนังสือ (book[i].Status, book[i].BorrowStatus, book[i].Borrow[j])



ตัวแปรในฟังก์ชันประกอบด้วย
- DATEBOOK_T *book คือ ข้อมูลของหนังสือ 1 เล่ม
- int *arr คือ จำนวนคนที่ยืมหนังสือแต่ละเล่ม
- int amount คือจำนวนหนังสือทั้งหมด
- fopen คือ การเปิดไฟล์ test.txt เพื่อเขียน
--------------------
ส่วนของ function readN_flie
```c
void readN_flie(int *amount) {
  FILE *fptr;
  char buffer[100];
  int count = 0, index = 0;
  int countRow = 0;
  fptr = fopen("test.txt", "r");
  while (fgets(buffer, 100, fptr) != NULL) {
    // printf("%d %s", count, buffer);
    switch (count) {
    case 0:
      (*amount)++;
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    default:
      if (isalpha(buffer[0])) {
        // printf("case default %d %d %s", count, countRow, buffer);
        countRow++;
      } else if (buffer[0] == '\n') {
        index++;
        count = -1;
        countRow = 0;
      }
    }
    count++;
  }
  // *amount = count;
  fclose(fptr);
}
```
ฟังก์ชันนี้จะเป็นการอ่านค่าจากไฟล์ `test.txt` โดยที่ใน`ลูป while` จะทำหน้าที่นับจำนวนหนังสือทั้งหมด และใน `switch case` จะทำหน้าที่หาหนังสือแต่ละเล่ม โดยที่ใน `if` จะทำหน้าที่เช็คจำนวนของผู้ยืมหนังสือ

ตัวแปรในฟังก์ชันประกอบด้วย
- int *amount คือ จำนวนหนังสือ
- char buffer[100] คือ ตัวแปรที่ไว้รับค่าจากไฟล์
- int count คือ ตัวแปรที่ใช้เลื่อนบรรทัดใน test.txt
- int index คือ การเลื่อนช่องของ array of struct ที่ใช้เก็บข้อมูลหนังสือทั้งหมด
- int countRow คือ การนับบรรทัดของข้อมูลผู้ยืม
- fopen คือ การเปิดไฟล์ test.txt เพื่ออ่าน
--------------------
**ส่วนของ function readArray**
```c
void readArray(int *array) {
  FILE *fptr;
  char buffer[100];
  int count = 0, index = 0;
  int countRow = 0;
  fptr = fopen("test.txt", "r");
  while (fgets(buffer, 100, fptr) != NULL) {
    // printf("%d %s", count, buffer);
    switch (count) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    default:
      if (isalpha(buffer[0])) {
        // printf("case default %d %d %s", count, countRow, buffer);
        countRow++;
      } else if (buffer[0] == '\n') {
        array[index] = countRow;
        index++;
        count = -1;
        countRow = 0;
      }
    }
    count++;
  }
  fclose(fptr);
}
```
ฟังก์ชันนี้จะเป็นการอ่านค่าจากไฟล์ `test.txt` โดยที่ใน`ลูป while` จะทำหน้าที่นับจำนวนหนังสือทั้งหมด และใน `switch case` จะทำหน้าที่หาหนังสือแต่ละเล่ม โดยที่ใน `if` จะทำหน้าที่เช็คจำนวนของผู้ยืมหนังสือ และจะคอยเก็บจำนวนคนที่ยืม-คืนหนังสือเข้า `array`

ตัวแปรในฟังก์ชันประกอบด้วย
- int *array คือ array ที่เก็บข้อมูลของจำนวนคนยืม-คือหนังสือ
- char buffer[100] คือ ตัวแปรที่ไว้รับค่าจากไฟล์
- int count คือ ตัวแปรที่ใช้เลื่อนบรรทัดใน test.txt
- int index คือ การเลื่อนช่องของ array of struct ที่ใช้เก็บข้อมูลหนังสือทั้งหมด
- int countRow คือ การนับบรรทัดของข้อมูลผู้ยืม
- fopen คือ การเปิดไฟล์ test.txt เพื่ออ่าน
--------------------
**ส่วนของ function testread_flie**
```c
void testread_flie(DATEBOOK_T *readbook, int *arr) { // Advance
  FILE *fptr;
  char buffer[100];
  int count = 0, index = 0;
  int countRow = 0;
  fptr = fopen("test.txt", "r");
  while (fgets(buffer, 100, fptr) != NULL) {
    // printf("%d %s", count, buffer);
    switch (count) {
    case 0:
      // printf("case 0 %d %d %s", count,index,buffer);
      strcpy(readbook[index].Name_book, buffer);
      // (*amount)++;
      break;
    case 1:
      // printf("case 1 %d %d %s", count,index,buffer);
      strcpy(readbook[index].Author, buffer);
      break;
    case 2:
      // printf("case 2 %d %d %s", count,index,buffer);
      strcpy(readbook[index].Year, buffer);
      // index++;
      break;
    case 3:
      // printf("case 3 %d %d %s", count,index,buffer);
      strcpy(readbook[index].Status, buffer);
      break;
    case 4:
      // printf("case 4 %d %d %s", count,index,buffer);
      strcpy(readbook[index].BorrowStatus, buffer);
      readbook[index].Borrow = (char **)malloc(arr[index] * sizeof(char *));
      break;
    default:
      if (isalpha(buffer[0])) {
        // printf("case default %d %d %s", count, countRow, buffer);
        readbook[index].Borrow[countRow] = strdup(buffer);
        // readbook[index].Borrow = malloc(arr[index] * sizeof(char*));
        // strcpy(readbook[index].Borrow[countRow], buffer);
        countRow++;
      } else if (buffer[0] == '\n') {
        index++;
        count = -1;
        countRow = 0;
      }
    }
    count++;
  }
  fclose(fptr);
}
```
ฟังก์ชันนี้จะทำหน้าที่เก็บข้อมูลของหนังสือทั้งหมด โดยที่ใน`ลูป while` จะทำหน้าที่เอาข้อมูลจาก `test.txt` มาเก็บข้อมูลใน struct ที่ละบรรทัด และใน `switch case` จะทำหน้าที่นำข้อมูลที่ได้มาเก็บในข้อมูลของ struct แต่ละตัว และใน case ที่ 4 จะทำการ `malloc` เพื่อสร้าง address ให้กับข้อมูลการยืมของหนังสือแต่ละเล่ม โดยที่ใน `if` จะทำหน้าที่เช็คว่าเป็นชื่อคนอยู่ไหม ถ้ายังเป็นชืื่อคนอยู่ให้เก็บข้อมูลไปใน ข้อมูลการยืมอยู่ ถ้าไม่ใช่ให้เช็คว่าเป็นการกด 'enter' ไหม ถ้าใช่ก็ให้ขึ้นหนังสือเล่มใหม่เพื่อบันทึกข้อมูล

ตัวแปรในฟังก์ชันประกอบด้วย
- DATEBOOK_T *readbook คือ ข้อมูลของหนังสือทั้งหมด
- int *arr คือ จำนวนคนที่ยืมหนังสือแต่ละเล่ม
- char buffer[100] คือ ตัวแปรที่ไว้รับค่าจากไฟล์
- int count คือ ตัวแปรที่ใช้เลื่อนบรรทัดใน test.txt
- int index คือ การเลื่อนช่องของ array of struct ที่ใช้เก็บข้อมูลหนังสือทั้งหมด
- int countRow คือ การนับบรรทัดของผู้ยืม
- fopen คือ การเปิดไฟล์ test.txt เพื่ออ่าน
--------------------
**ส่วนของ function add_book**
```c
void add_book(DATEBOOK_T *book, int *amount, int *arr, int size) {
  FILE *fptr;
  fptr = fopen("test.txt", "a");
  DATEBOOK_T *temp= (DATEBOOK_T*)calloc(1, sizeof(size));
  int count = 0, tempA = 0;
  char strstatus[] = "Available\n";
  char strborrow[] = "Borrowing History:\n";
  while (count < 3) {
    switch (count) {
    case 0:
      printf("Enter title: ");
      int correct = 1;
      fgets(temp->Name_book, 100, stdin);
      if (temp->Name_book[0] == '\n') {
        printf("Invalid title\n");
        correct = 0;
      }
      for (int i = 0; i < *amount; i++) {
        if (strcmp(temp->Name_book, book[i].Name_book) == 0) {
          // printf("number = %d\n", strcmp(temp.Name_book, book[i].Name_book));
          printf("Invalid title\n");
          correct = 0;
        }
      }
      count = (correct) ? 1 : 0;
      break;
    case 1:
      printf("Enter author name: ");
      fgets(temp->Author, 100, stdin);
      count++;
      break;
    case 2: //broken here
      printf("Enter publish year: ");
      fgets(temp->Year, 100, stdin);
      int counttdigit = 0;
      //printf("case x core dumped this here 1");//here
      for (int i = 0; i < strlen(temp->Year) - 1; i++) {
        if (isdigit(temp->Year[i]) == 0) {
          //printf("case 1 core dumped this here 1");
          counttdigit++;
        }
      }
      if (counttdigit > 0) {
        printf("Invalid publish year\n");
        count = 2;
      } else {
        count++;
      }
    }
  }
  
  //printf("case 1 core dumped this here");
  fprintf(fptr, "%s%s%s%s%s\n", temp->Name_book, temp->Author, temp->Year,
          strstatus, strborrow);
  fclose(fptr);
  // free(temp);
}
```
ฟังก์ชันนี้ทำหน้าที่เพิ่มหนังสือเข้าไปในไฟล์ `test.txt` โดยจะรับค่าคือชื่อหนังสือ คนแต่ง และปีที่ตีพิมพ์ โดยที่ `while` เพื่อให้ผู้ใช้กรอกรายละเอียดของหนังสือที่จะเพิ่ม แลเข้า`ลูป for` เพื่อเช็คว่าหนังสือนั้นมีอยู่แล้วหรือยัง ถ้าไม่เข้า `if` จะเปลี่ยน count ให้เป็น 1 ถ้าหนังสือไม่ซ้ำ ก็จะให้ผู้ใช้กรอกผู้แต่ง

ตัวแปรในฟังก์ชันประกอบด้วย
- DATEBOOK_T *book คือ ข้อมูลของหนังสือทั้งหมดที่มี
- int *arr คือ จำนวนคนที่ยืมหนังสือแต่ละเล่ม
- fopen คือ การเปิดไฟล์ test.txt เพื่อปรับแต่ง
- DATEBOOK_T temp คือ ข้อมูลของหนังสือทั้งหมดที่มี
- int count คือ ตัวแปรที่ตั้งไว้ว่าจะเข้าเงื่อนไขใด
- char strstatus[] คือ สถานะของหนังสือเล่มที่จะเพิ่ม
- char strborrow[] คือ สถานะการยืมของหนังสือที่จะเพิ่ม
- int correct คือ ใช้เช็คว่าเป็นหนังสือเล่มเดียวกันหรือไม่
-  int counttdigit คือ ตัวแปรที่ใช้เชคว่าผู้ใช้กรอกมาแค่ตัวเลขใช่หรือไม่

--------------------
**ส่วนของ function del_book**
```c
void del_book(DATEBOOK_T *book,int *amount, int *arr) {
  FILE *fptr;
  fptr = fopen("test.txt", "w");
  char str[100] ;
  int temp = 0;
  printf("Enter title to be removed: ");
  fgets(str,100,stdin);
  for (int i = 0; i < *amount; i++) {
    if (strcmp(str, book[i].Name_book) != 0) {
      temp++;
      fprintf(fptr, "%s%s%s%s%s", book[i].Name_book, book[i].Author,
              book[i].Year, book[i].Status, book[i].BorrowStatus);
      for (int j = 0; j < arr[i]; j++) {
        fprintf(fptr, "%s", book[i].Borrow[j]);
      } 
      fprintf(fptr, "\n");
    }
  }
  *amount = temp;
  fclose(fptr);
}
}
```
ฟังก์ชันนี้ทำหน้าที่ลบข้อมูลหนังสือเล่มที่ต้องการในไฟล์ `test.txt` โดยที่มี `for` เพื่อเช็คว่าหนังสือที่ต้องการลบกับหนังสือที่มีอยู่มีชื่อตรงกันหรือไม่ จากนั้นก็เก็บค่าจำนวนหนังสือที่เหลืออยู่
ตัวแปรในฟังก์ชันประกอบด้วย
- DATEBOOK_T *book คือ ข้อมูลของหนังสือทั้งหมดที่มี
- int *arr คือ จำนวนคนที่ยืมหนังสือแต่ละเล่ม
- int *amount คือ จำนวนหนังสือทั้งหมด
- fopen คือ การเปิดไฟล์ test.txt เพื่อปรับเขียน
- int temp คือ ตัวแปรที่ใช้เก็บจำนวนหนังสือที่ไม่โดนลบ

--------------------
**ส่วนของ function edit_book**
```c
void edit_book(DATEBOOK_T *book, int amount, int *arr) {
  FILE *fptr;
  fptr = fopen("test.txt", "w");
  char str[100];
  DATEBOOK_T temp;
  printf("Enter title to edit: ");
  fgets(str, 100, stdin);
  printf("New title (leave blank to retain old value): ");
  fgets(temp.Name_book, 100, stdin);
  printf("New author name (leave blank to retain old value): ");
  fgets(temp.Author, 40, stdin);
  printf("New publish year (leave blank to retain old value): ");
  fgets(temp.Year, 6, stdin);
  // printf("%d", amount);
  for (int i = 0; i < amount; i++) {
    if (strcmp(str, book[i].Name_book) == 0) {
      if (temp.Name_book[0] != '\n') {
        strcpy(book[i].Name_book, temp.Name_book);
      }
      if (temp.Author[0] != '\n') {
        strcpy(book[i].Author, temp.Author);
      }
      if (temp.Year[0] != '\n') {
        strcpy(book[i].Year, temp.Year);
      }
      break;
    }
  }
  write_f(book, arr, amount);
  fclose(fptr);
}
```
ฟังก์ชันนี้ทำหน้าที่แก้ไขข้อมูลหนังสือในไฟล์ `test.txt` โดยในลูป `for `ทำหน้าที่เป็นหนังสือที่เลือกหรือไม่

ตัวแปรในฟังก์ชันประกอบด้วย
- DATEBOOK_T *book คือ ข้อมูลของหนังสือทั้งหมด
- int amount คือ จำนวนหนังสือ
- int *arr คือ จำนวนคนที่ยืมหนังสือแต่ละเล่ม
- fopen คือ การเปิดไฟล์ test.txt เพื่อเขียน
- char str[100] คือ เก็บค่าข้อมูลที่ผู้ใช้พิมพ์เข้ามา
- DATEBOOK_T temp คือ ตัวแปรที่ใช้เก็บข้อมูลของหนังสือ

--------------------
**ส่วนของ function show_book**
```c
void show_book(DATEBOOK_T *book, int amount, int *arr) {
  for (int i = 0; i < amount; i++) {
    // countRow = 0 ;
    printf("%d core dumped pls \n", i);
    printf("Title: %s", book[i].Name_book);
    printf("Author Name: %s", book[i].Author);
    printf("Publish Year: %s", book[i].Year);
    printf("Status: %s", book[i].Status);
    printf("%s", book[i].BorrowStatus);
    for (int j = 0; j < arr[i]; j++) {
      if (arr[i] % 2 == 0) { // even first borrow end with return ;
        if (j % 2 == 1) {
          printf("- Borrow by %s", book[i].Borrow[j]);
        } else {
          printf("- Return by %s", book[i].Borrow[j]);
        }
      } else {
        if (j % 2 == 0) { // odd first borrow end with borrow ;
          printf("- Borrow by %s", book[i].Borrow[j]);
        } else {
          printf("- Return by %s", book[i].Borrow[j]);
        }
      }
    }
    printf("\n");
  }
  // printf("%d",countRow);
}
```
ฟังก์ชันนี้ทำหน้าที่แสดงหนังสือที่อยู่ในไฟล์ `test.txt` ทั้งหมด `for` ใหญ่ทำหน้าที่พิมพ์ข้อมูลหนังสือ `for` ข้างในทำหน้าที่ดูว่าเป็นเลขคู่หรือเลขคี่่ ถ้าเป็นเลขคู่ จะขึ้นด้วยข้อมูลการยืมและจบด้วยข้อมูลการคืน ถ้าเป็นเลขคี่ จะขึ้นด้วยข้อมูลการยืมและจบด้วยข้อมูลการยืม

ตัวแปรในฟังก์ชันประกอบด้วย
- DATEBOOK_T *book คือ ข้อมูลของหนังสือทั้งหมด
- int amount คือ จำนวนหนังสือ
- int *arr คือ จำนวนคนที่ยืมหนังสือแต่ละเล่ม

--------------------
**ส่วนของ function search_book**
```c
void search_book(DATEBOOK_T *book, int amount, int *arr) {
  DATEBOOK_T temp;
  int count = 0, countCorrect = 1;
  printf("Enter title (leave blank to include all titles): ");
  fgets(temp.Name_book, 100, stdin);
  printf("Enter author name (leave blank to include all author names): ");
  fgets(temp.Author, 40, stdin);
  printf("\n");
  if (temp.Name_book[strlen(temp.Name_book) - 1] == '\n') {
    temp.Name_book[strlen(temp.Name_book) - 1] = '\0';
  }
  if (temp.Author[strlen(temp.Author) - 1] == '\n') {
    temp.Author[strlen(temp.Author) - 1] = '\0';
  }
  for (int i = 0; i < amount; i++) {
    char *pName_book = strstr(book[i].Name_book, temp.Name_book);
    char *pAuthor = strstr(book[i].Author, temp.Author);
    // printf("%p %p\n", pName_book, pAuthor);
    // printf("%d\n",i);
    if (temp.Author[0] == '\0' && temp.Name_book[0] == '\0') {
      count = 1;
      break;
    } else if (pName_book == NULL && pAuthor == NULL) {
      count = 1;
      break;
    } else if (pName_book == NULL && temp.Name_book[0] == '\0') {
      count = 1;
      break;
    } else if (pName_book != NULL) {
      if (temp.Author[0] == '\0') {
        countCorrect = 0;
        printf("Title: %s", book[i].Name_book);
        printf("Author Name: %s", book[i].Author);
        printf("Publish Year: %s", book[i].Year);
        printf("Status: %s", book[i].Status);
        printf("%s", book[i].BorrowStatus);
        for (int j = 0; j < arr[i]; j++) {
          if (arr[i] % 2 == 0) { // even first borrow end with return ;
            if (j % 2 == 1) {
              printf("- Borrow by %s", book[i].Borrow[j]);
            } else {
              printf("- Return by %s", book[i].Borrow[j]);
            }
          } else {
            if (j % 2 == 0) { // odd first borrow end with borrow ;
              printf("- Borrow by %s", book[i].Borrow[j]);
            } else {
              printf("- Return by %s", book[i].Borrow[j]);
            }
          }
        }
        printf("\n");
      } else if (pAuthor == NULL) {
        count = 1;
        // printf("case 2 Not found!\n");
      } else if (pAuthor != NULL) {
        countCorrect = 0;
        printf("Title: %s", book[i].Name_book);
        printf("Author Name: %s", book[i].Author);
        printf("Publish Year: %s", book[i].Year);
        printf("Status: %s", book[i].Status);
        printf("%s", book[i].BorrowStatus);
        for (int j = 0; j < arr[i]; j++) {
          if (arr[i] % 2 == 0) { // even first borrow end with return ;
            if (j % 2 == 1) {
              printf("- Borrow by %s", book[i].Borrow[j]);
            } else {
              printf("- Return by %s", book[i].Borrow[j]);
            }
          } else {
            if (j % 2 == 0) { // odd first borrow end with borrow ;
              printf("- Borrow by %s", book[i].Borrow[j]);
            } else {
              printf("- Return by %s", book[i].Borrow[j]);
            }
          }
        }
        printf("\n");
      } else if (pAuthor != NULL) {
        if (temp.Name_book[0] == '\0') {
          countCorrect = 0;
          printf("Title: %s", book[i].Name_book);
          printf("Author Name: %s", book[i].Author);
          printf("Publish Year: %s", book[i].Year);
          printf("Status: %s", book[i].Status);
          printf("%s", book[i].BorrowStatus);
          for (int j = 0; j < arr[i]; j++) {
            if (arr[i] % 2 == 0) { // even first borrow end with return ;
              if (j % 2 == 1) {
                printf("- Borrow by %s", book[i].Borrow[j]);
              } else {
                printf("- Return by %s", book[i].Borrow[j]);
              }
            } else {
              if (j % 2 == 0) { // odd first borrow end with borrow ;
                printf("- Borrow by %s", book[i].Borrow[j]);
              } else {
                printf("- Return by %s", book[i].Borrow[j]);
              }
            }
          }
          printf("\n");
        } else if (pName_book == NULL) {
          count = 1;
          // printf("case 3 Not found\n");
        }
      } else {
        count = 1;
      }
    }
    // printf("%d",count);
  }
  if (count && countCorrect) {
    printf("Not found!");
  }
}

```
ฟังก์ชันนี้ทำหน้าที่ค้นหาหนังสือเล่มที่ต้องการในไฟล์ `test.txt `โดยที่ใน `for และ if ใหญ่`มีหน้าที่คือเช็คว่าผู้ใช้พิมพ์ชื่อหนังสือ/คนแต่งถูกหรือไม่ ถ้ามีก็จะแสดงหนังสือออกมา ถ้าไม่มีก็จะแสดงผล NULL และ `for เล็ก และ if ใน for เล็ก` มีหน้าที่พิมพ์ประวัติการยืม-คืนหนังสือ

ตัวแปรในฟังก์ชันประกอบด้วย
- DATEBOOK_T *book คือ ข้อมูลของหนังสือทั้งหมด
- int amount คือ จำนวนหนังสือ
- int *arr คือ จำนวนคนที่ยืมหนังสือแต่ละเล่ม
- DATEBOOK_T temp คือ ข้อมูลของหนังสือ
- int count คือ ตัวแปรที่ใช้เช็คว่าเป็น NULL หรือไม่
- int countCorrect คือ ถ้าเจอหนังสือจะไม่พิมพ์ not found

--------------------
**ส่วนของ function borrow_book**
```c
void borrow_book(DATEBOOK_T *borrow, int *arr, int amount) {
  char str[50], str2[50];
  int count = 0 ; 
  // DATEBOOK_T *temp = (DATEBOOK_T*)calloc(1,sizeof(DATEBOOK_T));
  //printf("case 2 core dumped this here");
  char **tmp;
  printf("Enter borrower name: ");
  fgets(str2, 50, stdin);
  printf("Enter title to borrow: ");
  fgets(str, 50, stdin);
  /*เปลี่ยนสถานะของหนังสือให้เป็น Borrowed เมื่อมีการ borrow_book แล้ว*/
  for (int i = 0; i < amount; i++) {
    if (strcmp(str, borrow[i].Name_book) == 0) {
      if(strcmp(borrow[i].Status, "Borrowed\n") == 0){
        count = 1;
        break;
      }
      strcpy(borrow[i].Status, "Borrowed\n");
      tmp = (char **)malloc((arr[i] + 1) * sizeof(char *));
      for (int j = 1; j < arr[i] + 1; j++) {
        tmp[j] = strdup(borrow[i].Borrow[j - 1]);
        free(borrow[i].Borrow[j - 1]);
      }
      free(borrow[i].Borrow);
      tmp[0] = strdup(str2);
      borrow[i].Borrow = tmp;
      arr[i] += 1;
    }
  }
  if(count){
    printf("Status is Borrowed !!\n"); 
  }
  write_f(borrow, arr, amount);
}
```
ฟังก์ชันนี้มีหน้าที่บันทึกข้อมูลการยืมหนังสือในไฟล์ `test.txt` โดยที่ใน `for และ if ใหญ่` มีหน้าที่คือการเช็คว่าหนังสือเล่มนี้ใช่หนังสือที่จะยืมหรือไม่ จะมีการสร้าตัวแปรขึ้นมา 1 ตัว เป็นการจองพื่นที่จำนวน = จำนวนคนทั้งหมด + 1 และมีการเปลี่ยนสถานะใยการยืม/คืน และ `for เล็ก`มีหน้าที่คัดลอกข้อมูลไปใส่ในตัวแปร `tmp` และถ้าหนังสือมีสถานะ Borrowed จะไม่สามารถยืมได้

ตัวแปรในฟังก์ชันประกอบด้วย
- DATEBOOK_T *borrow คือ ข้อมูลของหนังสือทั้งหมด
- int *arr คือ จำนวนคนที่ยืมหนังสือแต่ละเล่ม
- int amount คือ จำนวนหนังสือ
- char str[50] คือ ชื่อหนังสือ
- char str2[50] คือ ชื่อคนยืมหนังสือ
- char **tmp คือ ตัวแปรที่ใช้รับค่าและส่งค่าเข้าไปใน struct
- int count คือ ตัวแปรไว้เช็คว่าหนังสือถูกยืมแล้วหรือยัง
--------------------
ส่วนของ function return_book
```c
void return_book(DATEBOOK_T *borrow, int *arr, int amount) {
  char str[50], str2[50];
  // DATEBOOK_T *temp = (DATEBOOK_T*)calloc(1,sizeof(DATEBOOK_T));
  char **tmp;
  printf("Enter title to return: ");
  fgets(str, 50, stdin);
  for (int i = 0; i < amount; i++) {
    if (strcmp(str, borrow[i].Name_book) == 0) {
      strcpy(borrow[i].Status, "Available\n");
      tmp = (char **)malloc((arr[i] + 1) * sizeof(char *));
      for (int j = 1; j < arr[i] + 1; j++) {
        tmp[j] = strdup(borrow[i].Borrow[j - 1]);
        free(borrow[i].Borrow[j - 1]);
      }
      free(borrow[i].Borrow);
      tmp[0] = strdup(tmp[1]);
      borrow[i].Borrow = tmp;
      arr[i] += 1;
    }
  }
  write_f(borrow, arr, amount);
}
```
ฟังก์ชันนี้มีหน้าที่บันทึกข้อมูลการคืนหนังสือในไฟล์ `test.txt` โดยที่ใน `for และ if ใหญ่ `มีหน้าที่คืออการเช็คว่าหนังสือเล่มนี้ใช่หนังสือที่จะคืนหรือไม่และมีการเปลี่ยนสถานะใยการยืม/คืน และ `for เล็ก` มีหน้าที่คัดลอกข้อมูลไปใส่ในตัวแปร `tmp`
ตัวแปรในฟังก์ชันประกอบด้วย
- DATEBOOK_T *borrow คือ ข้อมูลของหนังสือทั้งหมด
- int *arr คือ จำนวนคนที่ยืมหนังสือแต่ละเล่ม
- int amount คือ จำนวนหนังสือ
- char str[50] คือ รับค่าชื่อหนังสือ
- char str2[50] คือ ไม่ได้ใช้
- char **tmp คือ ตัวแปรที่ใช้รับค่าและส่งค่าเข้าไปใน struct
#### 
--------------------
### **library.h**
การทำงานของไฟล์ library.h มีไว้เพื่อเก็บ function ต่างๆ
```
#ifndef library
#define library
.
.
.
#endif
```
```(#define library)``` ส่วนนี้จะเป็นการเขียนขึ้นมาเพื่อ ประกาศค่าตัวแปรขึ้นมาเก็บค่าโดยที่ค่านี้จะมาสามารถที่จะเปลี่ยนไปได้ และ 

```(#ifndef library)``` ใช้เพื่อตรวจสอบ ```library``` ที่ถูกสร้างไว้ ถ้าเป็นจริงจะอนุญาติให้ส่วนของโค้ดคอมไพล์ได้ ถ้าไม่ใช่จะข้ามการคอมไพล์โค้ดส่วนนั้นไป
directive จะจบด้วย ```(#endif)```

------------------------------------
**ส่วนของ typedef struct{}**
```c 
typedef struct {
  char Name_book[100];
  char Author[40];
  char Year[6];
  char Status[30];
  char BorrowStatus[30];
  char **Borrow;
} DATEBOOK_T;
```
เป็นการกำหนดชนิดข้อมูลให้เป็น struct

**ส่วนของ void ต่าง ๆ**
```c

void write_f(DATEBOOK_T *book, int *arr, int amount);

void readN_flie(int *amount);

void readArray(int *array);

void testread_flie(DATEBOOK_T *readbook, int *arr); // Advance

void add_booktest(DATEBOOK_T *book , int * arr , int  *amount);

void add_book(DATEBOOK_T *book, int *amount, int *arr); // userinput

void del_book(DATEBOOK_T *book, char *str, int *amount);

void edit_book(DATEBOOK_T *book, int amount, int *arr); // userinput

void show_book(DATEBOOK_T *book, int amount, int *arr);

void search_book(DATEBOOK_T *book, int amount, int *arr);

void borrow_book(DATEBOOK_T *borrow, int *arr , int amount);

void return_book(DATEBOOK_T *borrow, int *arr, int amount);
```
เป็นไฟล์ส่วนหัวเพื่อรวมการประกาศตัวแปร ค่าคงที่ และfunction

-------------------------------------
### **การทำงานของไฟล์ test.txt**
ทำหน้าที่เก็บข้อมูลหนังสือทั้งหมดลงไปในไฟล์ .txt

ยกตัวอย่างการจัดเก็บไฟล์
```
Title
Author name
Publish year
Status:
Borrowing history:

```
เมื่อใส่ข้อมูลไปแล้วจะแสดงออกมาดังนี้

```
Harry Potter and the Philosopher's Stone
J. K. Rowling 
1997
Available
Borrowing History:
Tim Jobs
Tim Jobs
Steve Cook
Steve Cook

Harry Potter and the Chamber of Secrets 
J. K. Rowling
1998
Borrowed
Borrowing History:
Steve Cook
Steve Cook
Tim Jobs
```

--------------------
### **การทำงานของไฟล์ test.txt**
ทำหน้าที่เก็บข้อมูลหนังสือทั้งหมดลงไปในไฟล์ .txt

ยกตัวอย่างการจัดเก็บไฟล์
```
Title
Author name
Publish year
Status:
Borrowing history:

```
เมื่อใส่ข้อมูลไปแล้วจะแสดงออกมาดังนี้

```
Harry Potter and the Philosopher's Stone
J. K. Rowling 
1997
Available
Borrowing History:
Tim Jobs
Tim Jobs
Steve Cook
Steve Cook

Harry Potter and the Chamber of Secrets 
J. K. Rowling
1998
Borrowed
Borrowing History:
Steve Cook
Steve Cook
Tim Jobs
```

-------------

**ข้อจํากัดของโปรแกรม**

โปรแกรมนี้เป็นโปรแกรมสําหรับจัดการฐานข้อมูลหนังสือในห้องสมุดที่มีฟังก์ชันการทํางานดังนี้
1. สามารถเพิ่ม-ลบหนังสือในห้องสมุดได้ `[ ต้องปิดโปรแกรมก่อนถึงจะเริ่มทำงาน function ถัดไปได้ ]`
2. สามารถแก้ไขรายละเอียดของหนังสือ (ชื่อหนังสือ, ชื่อผู้แต่ง, ปีที่พิมพ์) ได้ `[ ชื่อหนังสือได้ไม่เกิน 100 ตัวอักษร, ชื่อผู้แต่งได้ไม่เกิน 40 ตัวอักษร, ปีที่พิมพ์ได้ไม่เกิน 4 ตัวอักษร ]`
3. สามารถค้นหาหนังสือจากชื่อหนังสือและ/หรือชื่อผู้แต่งได้ 
4. มีระบบการยืม-คืนหนังสือ โดยไม่จํากัดจํานวนครั้งในการยืม-คืนของหนังสือแต่ละเล่ม `[ ชื่อผู้ยืมต้องไม่เกิน 50 ตัวอักษร, ถ้าหนังสือมีสถานะ Borrowed จะไม่สามารถยืมได้ ]`
5. จัดเก็บข้อมูลลงไฟล์โดยอัตโนมัติโดยเมื่อเปิด-ปิดโปรแกรมใหม่รายละเอียดหนังสือและรายการยืมคืนทั้งหมด
จะต้องยังคงอยู่ 


**ข้อจำกัดเมื่อทดลองใช้งาน**
1. ผู้ใช้ที่ต้องการใช้ menu add book และ show book จำเป็นจะต้องมีการปิดโปรแกรมก่อนจึงจะสามารถเรียกใช้งาน function ถัดไปได้
2. ผู้ใช้ที่ต้องการใช้ menu edit book จะสามารถกรอกชื่อหนังสือได้ไม่เกิน100ตัว, กรอกชื่อผู้แต่งได้ไม่เกิน40ตัว, กรอกปีที่พิมพ์ได้ไม่เกิน4ตัว
3. ผู้ใช้ที่ต้องการใช้ menu borrow book  และ return book ลักษณะของการกรอกชื่อผู้ยืมต้องไม่เกิน50ตัว


----------