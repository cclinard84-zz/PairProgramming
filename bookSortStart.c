#include <stdio.h>
#include <string.h>

#define MAX_CHARS 81
#define MAX_BOOKS 10 

typedef struct  {
   char title[MAX_CHARS];
   char author[MAX_CHARS];
   char publisher[MAX_CHARS];
   int edition;
} book_t;

int readBooks(book_t[]);
void initSortingArray(book_t[], book_t*[], int);
void sortBooks(book_t*[], int);
void swap(book_t**, book_t**);
void printBooks(book_t*[], int);

int main() {
   book_t books[MAX_BOOKS];  
   book_t* titlePtrs[MAX_BOOKS];
   int numBooks;
   
   numBooks = readBooks(books);

   initSortingArray(books, titlePtrs, numBooks);

   sortBooks(titlePtrs, numBooks);
   
   printBooks(titlePtrs, numBooks);
   
   return 0;
}

int readBooks(book_t a[]){
   FILE* in;
   int i = 0;
   char junk;
   in = fopen( "books.in", "r" );
   if ( in != NULL ) {
      while ( i < MAX_BOOKS &&
      fgets( a[i].title, MAX_CHARS, in ) != NULL ) {
         fgets( a[i].author, MAX_CHARS, in );
         fgets( a[i].publisher, MAX_CHARS, in );
         fscanf(in, "%d", &a[i].edition );
         fscanf(in, "%c", &junk );
         i++;
      }
   }
   return i;
}

void initSortingArray(book_t a[], book_t* t[], int n){
    for(int i = 0; i < n; i++){
        t[i] = &a[i];
    }
}

void sortBooks(book_t *t[], int n){
    int minI;
    for(int top = 0; top < n-1; top++){
        minI = top;
        for(int i = top+1; i < n; i++){
            if(strcmp(t[i]->title, t[minI]->title) < 0){
                minI = i;
            }
        }   
        swap(&t[top], &t[minI]);
    }
}

void swap(book_t **b1, book_t **b2){
    book_t *temp = *b2;
    *b2 = *b1;
    *b1 = temp;
}

void printBooks(book_t* t[], int n){
    for( int i = 0; i < n; i++){
        printf("%s %s %s %d\n", t[i]->title, t[i]->author, t[i]->publisher, t[i]->edition);
    }
}
