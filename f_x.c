#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 255

typedef struct {
    float x;
    float y;
} point;

void read_line(char [], FILE*);


int main(){

    point p;
    FILE *init, *final;
    char line[MAX];

    init = fopen("values.csv", "r");
    final = fopen("final.csv", "w");

    while (!feof(init)){
        read_line(line, init);
        p.x = atof(line);
        if (p.x>=1){
            p.y = log(p.x);
        }
        else{
            p.y = 0;
        }
        fprintf(final,
        "%.1f;%.1f\n", p.x, p.y);
    }

    fclose(init);
    fclose(final);

    return 0;
}

void read_string(char txt[]){
    fflush(stdin);
    fgets(txt, MAX, stdin);
    if (txt[strlen(txt)-1]=='\n')
        txt[strlen(txt)-1]='\0';
}
