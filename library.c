#include "library.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Member
1. นายธเนศ จอมพูล 65070501025
2. นางสาวอริยาภรณ์ สุดเสถียรธานนท์ 65070501060
3. นายอาณกร งานสุจริต 65070501089*/

/* write a text in test.txt file */
void write_f(DATEBOOK_T *book, int *arr, int amount) {
  FILE *fptr;
  fptr = fopen("test.txt", "w");
  /*รับค่าข้อมูลต่าง ๆ ของหนังสือ*/
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

// amount is all of the book that we have
/* อ่านค่าจากไฟล์ .txt */
void readN_flie(int *amount) {
  FILE *fptr;
  char buffer[100];
  int count = 0, index = 0;
  int countRow = 0;
  fptr = fopen("test.txt", "r");
  /*นับจำนวนหนังสือทั้งหมด*/
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
      /*เช็คจำนวนผู้ยืมหนังสือ*/
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

/* อ่านค่าจากไฟล์ .txt */
void readArray(int *array) {
  FILE *fptr;
  char buffer[100];
  int count = 0, index = 0;
  int countRow = 0;
  fptr = fopen("test.txt", "r");
  /* นับจำนวนหนังสือทั้งหมด */
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
        /* เก็บจำนวนผู้ยืม-คืนเข้า array */
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
/*เป็น function เพื่อเก็บข้อมูลขอหนังสือทั้งหมด */
void testread_flie(DATEBOOK_T *readbook, int *arr) { // Advance
  FILE *fptr;
  char buffer[100];
  int count = 0, index = 0;
  int countRow = 0;
  fptr = fopen("test.txt", "r");
  /* เอาข้อมูลจากไฟล์มาเก็บไว้ใน struct ทีละบรรทัด */
  while (fgets(buffer, 100, fptr) != NULL) {
    // printf("%d %s", count, buffer);
    /* เก็บข้อูลใน struct แต่ละตัว */
    switch (count) {
    case 0:
      // printf("case 0 %d %d %s", count,index,buffer);
      strcpy(readbook[index].Name_book, buffer);
      // *amount = *amount+1;
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
      /* สร้าง address ให้กับข้อมูลการยืมของหนังสือแต่ละเล่ม */
      readbook[index].Borrow = (char **)malloc(arr[index] * sizeof(char *));
      break;
    default:
      /* เช็คว่ายังเป็นชื่อคนอยู่หรือไม่ */
      if (isalpha(buffer[0])) {
        // printf("case default %d %d %s", count, countRow, buffer);
        readbook[index].Borrow[countRow] = strdup(buffer);
        // readbook[index].Borrow = malloc(arr[index] * sizeof(char*));
        // strcpy(readbook[index].Borrow[countRow], buffer);
        countRow++;
        /* เช็คว่ายังเป็นชื่อ 'enter' หรือไม่ */
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
/*function เพื่อเพิ่มหนังสือ*/
//dump
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

/*เป็น function เพื่อการลบหนังสือออกไปจากคลังที่บันทึกไว้ */
//dump
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

/*เป็น function สำหรับการ edit_book แก้ไขรายละเอียดต่าง ๆ ในหนังสือ */
void edit_book(DATEBOOK_T *book, int amount, int *arr) {
  FILE *fptr;
  fptr = fopen("test.txt", "w"); //เขียนไฟล์ลง test.txt
  char str[100];
  DATEBOOK_T temp;
  printf("Enter title to edit: ");//ชื่อหนังสือที่ต้องการแก้ไข
  fgets(str, 100, stdin);
  printf("New title (leave blank to retain old value): ");//เปลี่ยนชื่อหนังสือ
  fgets(temp.Name_book, 100, stdin);
  printf("New author name (leave blank to retain old value): ");//เปลี่ยนชื่อผู้เขียน
  fgets(temp.Author, 40, stdin);
  printf("New publish year (leave blank to retain old value): ");//เปลี่ยนปี
  fgets(temp.Year, 6, stdin);
  // printf("%d", amount);
  
  /*เข้า for เพื่อทำการเปลี่ยนรายละเอียดตามที่รับเข้ามาด้านบน*/
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

/*เป็น function สำหรับโชว์หนังสือ ประกอบด้วย Title, Author Name, Publish Year, Status, Borrow History ของหนังสือ*/
void show_book(DATEBOOK_T *book, int amount, int *arr) {
// readN_file()
  for (int i = 0; i < amount; i++) {
    // countRow = 0 ;
    // printf("%d core dumped pls \n", i);
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

/*เป็น function เพื่อการค้นหาหนังสือ ป้อน title หรือ author name ลงไปแล้วหนังสือจะแสดงออกมาตามเงื่อนไขที่ป้อนลงไป */
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

/*function สำหรับบันทึกการยืมหนังสือ */
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

/*function สำหรับบันทึกการคืนหนังสือ */
void return_book(DATEBOOK_T *borrow, int *arr, int amount) {
  char str[50], str2[50];
  // DATEBOOK_T *temp = (DATEBOOK_T*)calloc(1,sizeof(DATEBOOK_T));
  char **tmp;
  printf("Enter title to return: ");
  fgets(str, 50, stdin);
  /*เปลี่ยนสถานะของหนังสือให้เป็น Available เมื่อมีการ return แล้ว*/
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