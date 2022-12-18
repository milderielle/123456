#ifndef library
#define library


/*Member
1. นายธเนศ จอมพูล 65070501025
2. นางสาวอริยาภรณ์ สุดเสถียรธานนท์ 65070501060
3. นายอาณกร งานสุจริต 65070501089*/


// typedef struct {
// DATEBOOK_T * book ; 
// int size ; 
// int Maxsize ; 
// } FILE_T;

typedef struct {
  char Name_book[100];
  char Author[40];
  char Year[6];
  char Status[30];
  char BorrowStatus[30];
  char **Borrow;
} DATEBOOK_T;

/* ฟังก์ชันทั้งหมดที่ใช้ใน project นี้ */
void write_f(DATEBOOK_T *book, int *arr, int amount);

void readN_flie(int *amount);

void readArray(int *array);

void testread_flie(DATEBOOK_T *readbook, int *arr); // Advance

void add_book(DATEBOOK_T *book, int *amount, int *arr,int size); // userinput

void del_book(DATEBOOK_T *book, int *amount,int *arr);

void edit_book(DATEBOOK_T *book, int amount, int *arr); // userinput

void show_book(DATEBOOK_T *book, int amount, int *arr);

void search_book(DATEBOOK_T *book, int amount, int *arr);

void borrow_book(DATEBOOK_T *borrow, int *arr , int amount);

void return_book(DATEBOOK_T *borrow, int *arr, int amount);

#endif