#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int SIZE = 501;

void getString(char *q, char *a);
void printResult(char *text);
long countAverage(char *text);

int main(){
    char text[SIZE];
    printResult(text);
    return 0;
}

void getString(char *q, char *a){
    printf("%s", q);
    fgets(a, SIZE, stdin);
    a [strcspn(a, "\n")] = '\0';
}

long countAverage(char *text){
    getString("Insert a text within 500 character: ", text);
    int l = 0;
    int w = 1;
    int s = 0;
    float avl;
    float avs;
    float index;
    for (int i = 0; i < strlen(text); i++){
        if (text[i] == '.' || text[i] == '?' || text[i] == '!'){
            s += 1;
        }
        else if (text[i] == ' '){
            w += 1;
        }
        else{
            l += 1;
        }
    }
    if (l != 0 && w != 0 && s != 0){
        avl = ((float)l / (float)w) * 100;
        avs = ((float)s / (float)w) * 100;
    }
    else {
        index = 0;
        return index;
    }
    index = (0.0588 * avl) - (0.296 * avs) - 15.8;
    index = (long) round(index);
    return index;
}

void printResult(char *text){
    long index = countAverage(text);
    if (index > 16){
        printf("Grade 16+");
    }
    else if(index < 1){
        printf("Below Grade 1");
    }
    else {
        printf("Grade is %ld", index);
    }
}
