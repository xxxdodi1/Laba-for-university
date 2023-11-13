#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

int check1(void) {
    int k = 0;
    char c[100], p, q[100] = "";
    do {
    scanf("%s", c);
    for (int i = 0; i < strlen(c); i++) {
    p = c[i];
    if (isdigit(p) == 0) {
    puts("неверные данные, введите другое число:");
    continue;
    }
    else
    strncat(q, &p, 1);
    k += 1;
    }
    if (k < strlen(c)) {
    k = 0;
    strcpy(q, "");
    }
    } while (k < 1);
    int num;
    num = atoi(q);
    return num;
}
int check2(void) {
    int k = 0;
    char c[100], p, q[100] = "";
    do {
    scanf("%s", c);
    for (int i = 0; i < strlen(c); i++) {
    p = c[i];
    if (isdigit(p) == 0 && p!= '-' && p!='.' && p!=',') {
    puts("неверные данные, введите другое число:");
    continue;
    }
    else
    strncat(q, &p, 1);
    k += 1;
    }
    if (k < strlen(c)) {
    k = 0;
    strcpy(q, "");
    }
    } while (k < 1);
    int num;
    num = atoi(q);
    return num;
}
void ElemRas(int *array,int n){
    int sum=0;int i=0;
    while (array[i] <= 0)
    ++i;
    ++i;
 
  while (array[i] <= 0) {
    sum += array[i];
    ++i;
  }
 
  printf ("\nСумма между первым и вторым положительными элементами: %d\n",sum);
 
}
void MinElement(int *array,int n){
    int min=array[0];
    for(int i = 0; i < 5; ++i)
    if(array[i] < min)
    {
        min = array[i];
    }
    printf ("Минимальный элемент=%d",min);
}
void nulor(int *array,int n){
    for(int i=0;i<n;i++)
    {
    if (array[i]==0)
    {
    if(i!=0)
    {
    for(int j=i;j>0;j--)
    array[j]=array[j-1];
    array[0]=0;
    }
  }
}
    printf("Новый массив где располагаются с начало 0 Элемент: \n");
    for(int i=0; i<n; i++){		
    printf("%d ",array[i]);
        
    }
}

    int main(){
    int n;
    printf("Введите размер массива\n");
    n = check1();
    
   
    
    int array[n];
    
    for (int i = 0; i < n; i++){
    printf("Элемент массива=");
    array[i]=check2();
   }
    MinElement(array,n);
    ElemRas(array,n);
    nulor(array,n);
    return 0;
    }
