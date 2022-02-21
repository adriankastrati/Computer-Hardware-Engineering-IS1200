#include <stdio.h>

char* text1 = "This is a string.";
char* text2 = "Yet another thing.";
int* list1;
int* list2;
int *count = 0;

void printlist(const int* lst){
  printf("ASCII codes and corresponding characters.\n");
  while(*lst != 0){
    printf("0x%03X '%c' ", *lst, (char)*lst);
    lst++;
  }
  printf("\n");
}

void endian_proof(const char* c){
  printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n", 
         (int)*c,(int)*(c+1), (int)*(c+2), (int)*(c+3));
  
}

void work(){
  copy_codes(*text1, *list1, *count);
  copy_codes(*text2, *list2, *count);
}

void copy_codes(char *a, char *b, int* c){  
  while((*a & 0xff) != 0){
        
    *b = (*a & 0xff);
    
    a++;
    
    b += 4;
    
    *c = *c + 1;
  }
}


int main(void){
  
  printf("\nlist1: ");
  printlist(list1);
  printf("\nlist2: ");
  printlist(list2);
  printf("\nCount = %d\n", count);

  endian_proof((char*) &count);
}
