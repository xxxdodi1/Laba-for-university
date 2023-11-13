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


void Sort(int* array, int n){
     int temp = 0;
    for(int i = 1; i < n; ++i)
	{
		for(int r = 0; r < n-i; r++)
		{
			if(array[r] < array[r+1])
			{
				// Обмен местами
				int temp = array[r];
				array[r] = array[r+1];
				array[r+1] = temp;
			}
		}
	}
    printf("\nОтсортированный массив: ");
	for(int i = 0; i < n; ++i)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
     
}




void otlichie(int* array, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
    if (array[i] != array[n - 1])
    j++;
    }
    printf("\nкол во элементов отличных от последнего %d", j);
    }
    void SumPositive(int* array, int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
    {
    if (array[i] > 0) s += array[i];
    }
    printf("Сумма положительных элементов равна=%d", s);
}


int indMaxEl(int* array, int n) {
    int max = array[0], index = 0;
    for (int i = 0; i < n; i++)
    {
    if (array[i] > max) {
    max = array[i];
    index = i;
    }
}
return index;
}

int indMinEl(int* array, int n) {
    int min = array[0], index = 0;
        for (int i = 0; i < n; i++)
        {
        if (array[i] < min) {
        min = array[i];
        index = i;
    }
}
return index;
}

void multElAr(int* array, int n) {
    int m = 1;
    int indexMax = indMaxEl(array, n);
    int indexMin = indMinEl(array, n);

if (indexMin < indexMax) {
    for (int i = indexMin; i <= indexMax; i++)
    {
    m *= array[i];
    }
    printf("Произведение элементов между минимальным и максимальным элементами: %d\n", m);
    }
    else if (indexMin > indexMax) {
        for (int i = indexMax; i <= indexMin; i++)
        {
        m *= array[i];
        }
        printf("Произведение элементов между минимальным и максимальным элементами: %d\n", m);
        }
        else
    printf("Максимальный и минимальный элементы совпадают\n");
    }

int main()
{
    int n;
    printf("Vvedite razmernost' massiva\n");
    //scanf("%d",&n);
    n = check1();
    
   
    
    int array[n];
    
    for (int i = 0; i < n; i++){
    printf("array[]=");
    array[i]=check2();
}

multElAr(array, n);
SumPositive(array, n);
otlichie(array, n);
Sort(array, n);


}
