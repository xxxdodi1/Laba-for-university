//2ая лаба 2ое задание 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_SNT_LEN 512
#define DELIM "\n\t .,:;!?(){}"
 
#define STREQ(str1, str2) (strcmp((str1), (str2)) == 0) 
 
char **get_tokens_dup(char *src, const char *delim)
{
    size_t cnt;
    char  *word;
    char **result = NULL;
 
    for(word = strtok(src, delim), cnt = 1;
        word;
        word = strtok(NULL, delim))
    {
        if ((result = (char **) realloc(result,
            ++cnt * sizeof(char *))) == NULL)
        {
            fputs("Can't allocate memory\n", stderr);
            exit(1);
        }
        if ((result[cnt - 2] = strdup(word)) == NULL) {
            fputs("Can't duplicate word\n", stderr);
            exit(2);
        }
    }
    result[cnt-- - 1] = NULL;
    return result;
}
 
int main()
{
    char snt1[MAX_SNT_LEN];
    char snt2[MAX_SNT_LEN];
    char **snt1_words;
    char **snt2_words;
    char **p1, **p2;
    char **intersection = NULL;
    size_t cnt = 0;
    size_t max_len = 0;
 
    printf("Введите первое предложение: ");
    fgets(snt1, MAX_SNT_LEN, stdin);
    printf("Введите второе предложение: ");
    fgets(snt2, MAX_SNT_LEN, stdin);
 
        snt1_words = get_tokens_dup(snt1, DELIM);
    snt2_words = get_tokens_dup(snt2, DELIM);
 
    for (p1 = snt1_words; *p1 != NULL; ++p1) {
        for (p2 = snt2_words; *p2 != NULL; ++p2)
            if (STREQ(*p1, *p2)) {
                if ((intersection = (char **) realloc(intersection,
                    ++cnt * sizeof(char *))) == NULL) 
                {
                    fputs("Не удается выделить память\n", stderr);
                    exit(1);
                }
                intersection[cnt - 1] = *p1;
                if (strlen(*p1) > max_len)
                    max_len = strlen(*p1);
            }
    }
    if (0 == cnt) {
        printf("Здесь нет общих слов.\n");
        exit(0);
    }
 
    printf("общее слово:\n");
    for (size_t i = 0; i < cnt; ++i) {
        if (strlen(intersection[i]) == max_len)
            printf("%s\n", intersection[i]);
    }
    free(intersection);
 
    for (p1 = snt1_words; *p1 != NULL; ++p1)
        free(*p1);
    free(*p1);
    free(snt1_words);
 
    for (p2 = snt2_words; *p2 != NULL; ++p2)
        free(*p2);
    free(*p2);
    free(snt2_words);
 
    exit(0);
}
//2ая лаба 3е задание
#include <stdio.h>
 
void reverse(FILE* dst, FILE* src) {
    char ch;
    while ((ch = fgetc(src)) != EOF) {
        reverse(dst, src);
        fputc(ch, dst);
    }
}
 
int main() {
    FILE* src = fopen("new1.txt", "r");
    FILE* dst = fopen("new2.txt", "w");
 
    if (src && dst) {
        reverse(dst, src);
    }
 
    return 0;
}



//1ая лаба
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
 
#define  DAYS 6
 
typedef struct
{
    char name[64];
    int details[DAYS];
}Worker;
 
 
int GetNumDetails(const Worker *worker )
{
    int num = 0;
    int i = 0;
    for(i = 0; i < DAYS; i++)
        num += worker->details[i];
    return num;
}
 
int GetNumDetailsMax(const Worker *worker )
{
    int m = 0;
    int i = 0;
    for(i = 0; i < DAYS; i++)
        if(worker->details[i] > m)
            m= worker->details[i];
    return m;
}
 
int GetNumEntries(FILE* f)
{
    int num = 0;
    char tmp[80];
    while(fgets(tmp,80,f)!= NULL)
        num++;
    fseek(f,0,SEEK_SET);
    return num;
}
 
void PrintWithCondition(const Worker *arr, int len)
{
    int i = 0;
    puts("Name Number Maximum:");
    puts("--------------------");
    for(i = 0; i < len; i++)
    {
        printf("%s \nВсего-",arr[i].name);
        printf("%d \nМаксимально за день-",GetNumDetails(&arr[i]));
        printf("%d \n",GetNumDetailsMax(&arr[i]));
    }
}
 
 
int main(void)
{
    FILE* f = fopen("Workers.txt","r");
    Worker *arr = NULL;
    int numEntries = 0;
    int i = 0;
    if(!f)
        puts("Error in opening file");
    else
    {
        numEntries = GetNumEntries(f);
        arr = (Worker *)malloc(sizeof(Worker) * numEntries);
 
        for(i = 0; i < numEntries; i++)
        {
            fscanf(f,"%s %d %d %d %d %d %d\n",
                   arr[i].name, &arr[i].details[0], &arr[i].details[1],
                    &arr[i].details[2],&arr[i].details[3], &arr[i].details[4],&arr[i].details[5]);
        }
 
        PrintWithCondition(arr, numEntries);
 
        free(arr);
        fclose(f);
    }
}

Williams  0 2 6 7 10 
Peters  20 0 2 6 8 
Gibson  0 2 6 7 8 
Martin  0 2 6 1 9 
Jordan  50 2 6 7 9 
Jackson  100 0 2 6 8 
Grant  7 7 7 7 7 
