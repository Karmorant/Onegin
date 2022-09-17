#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    struct stat text = {};
    stat("Text.txt", &text);

    FILE* fp = fopen("Text.txt", "r");
    char* dinamicM = (char*) calloc(text.st_size, sizeof(char));
    int str_num = text.st_size -  fread(dinamicM, sizeof(char), text.st_size, fp);
    char* pointers[str_num] = {};


    

    pointers[0] = dinamicM;
    for(int i = 1, j = 0; i != str_num; i++)
    {
        while(dinamicM[j] != '\n')
        {
            j++;
          //  printf("%d\n", j);
        }
        if (dinamicM[j + 1] != EOF)
        {
            pointers[i] = &dinamicM[j + 1];
            j++;
        }
    }   

   // printf("%d\n", pointers[3]);
   // printf("%d", &dinamicM[0]);
    printf("%s", pointers[4]);

    free(dinamicM);
    fclose(fp);
    return 0;
}