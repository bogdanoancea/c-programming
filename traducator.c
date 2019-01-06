#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LINE 1024

char* get_file_in(int l, char* param[]);
char* get_file_out(int l, char* param[]);
char* get_limba_in(int l, char* param[]);
char* get_limba_out(int l, char* param[]);
char* translate(char* word, FILE* pf_dict);

int main(int argc, char* argv[] ) {
    FILE* pf_in;
    FILE* pf_out;
    FILE* pf_dictionar;
    char* limba_in;
    char* limba_out;
    char* file_in_name;
    char* file_out_name;
    char* dictionar;
    char* folder_dic = "translator/dictionare/";
    char buf[MAX_LINE];
    char* sep = " \t";
    char* word;
    char* trad;



    if(argc != 9) {
        puts("Numarul de parametrii este incorect!");
        puts("Programul se foloseste astfel: >tranducator.exe -in file_in.txt -out file_out.txt -limba_in rom -limba_out eng");
        exit(1);
    }

    file_in_name = get_file_in(argc, argv);
    file_out_name = get_file_out(argc, argv);
    limba_in = get_limba_in(argc, argv);
    limba_out = get_limba_out(argc, argv);


    dictionar = (char*) malloc(sizeof(char) * (strlen(limba_in) + strlen(limba_out) + strlen(folder_dic) + 5) );
    if(dictionar == NULL) {
        puts("Memorie insuficienta");
        exit(1);
    }
    dictionar[0] = 0;
    dictionar = strcat(dictionar, folder_dic);
    dictionar = strcat(dictionar, limba_in);
    dictionar = strcat(dictionar, "-");
    dictionar = strcat(dictionar, limba_out);
    dictionar = strcat(dictionar, ".txt");

    pf_in = fopen(file_in_name, "rt");
    if(pf_in == NULL) {
        puts("Nu s-a reusit deschiderea fisierului de intrare!");
        exit(2);
    }

    pf_out = fopen(file_out_name, "wt");
    if(pf_out == NULL) {
        puts("Nu s-a reusit deschiderea fisierului de iesire!");
        exit(3);
    }

    pf_dictionar = fopen(dictionar, "rt");
    puts(dictionar);
    if(pf_dictionar == NULL) {
        puts("Nu s-a reusit deschiderea fisierului dictionar!");
        exit(4);
    }


    while( fgets(buf, MAX_LINE, pf_in) != NULL ) {
        buf[strcspn(buf, "\r\n")] = 0;
        word = strtok(buf, sep);
        while(word != NULL) {
            trad = translate(word, pf_dictionar);
            if(trad == NULL) {
                fputs("<<", pf_out);
                fputs(word, pf_out);
                fputs(">> ", pf_out);
            }
            else {
                fputs(trad, pf_out);
                fputs(" ", pf_out);
            }
            word = strtok(0, sep);
        }
    }
    fclose(pf_in);
    fclose(pf_out);
    fclose(pf_dictionar);
    return 0;
}


char* get_file_in(int l, char* param[]) {
    int i;

    for(i = 1; i < l; i++) {
        if(strcmp("-in", param[i]) == 0)
            return param[i+1];
    }
    return NULL;
}

char* get_file_out(int l, char* param[]) {
    int i;

    for(i = 1; i < l; i++) {
        if(strcmp("-out", param[i]) == 0)
            return param[i+1];
    }
    return NULL;
}

char* get_limba_in(int l, char* param[]) {
    int i;
    for(i = 1; i < l; i++) {
        if(strcmp("-limba_in", param[i]) == 0)
            return param[i+1];
    }
    return NULL;
}

char* get_limba_out(int l, char* param[]) {
    int i;
    for(i = 1; i < l; i++) {
        if(strcmp("-limba_out", param[i]) == 0)
            return param[i+1];
    }
    return NULL;
}


char* translate(char* word, FILE* pf_dict) {
    char buf2[MAX_LINE];

    rewind(pf_dict);
    while( fgets(buf2, MAX_LINE, pf_dict) != NULL ) {
        buf2[strcspn(buf2, "\r\n")] = 0;
        if(strncmp(word, buf2, strlen(word)) == 0) {
           char* result = malloc( sizeof(char) * (strlen(buf2) - 1 - strlen(word) ));
           return strcpy(result, &buf2[strlen(word)+1]);
        }
    }
    return NULL;
}


