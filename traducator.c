#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LINE 1024

char* get_file_in(int l, char* param[]);
char* get_file_out(int l, char* param[]);
char* get_limba_in(int l, char* param[]);
char* get_limba_out(int l, char* param[]);
char* translate(char* word, char** dict, int nl);

char** read_dictionary(FILE* pf_dict, int no_lines);
void getwords(char *line, char* words[], int index, int no_lines);
int get_dict_no_lines(FILE* pf_dict);
char* get_sep();
int check_sep(char p, char* sep);

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
    char* sep = get_sep();
    char* word;
    char* trad;
    char** dict;
    int nl;
    char eol;

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

    pf_out = fopen(file_out_name, "wt");
    if(pf_out == NULL) {
        puts("Nu s-a reusit deschiderea fisierului de iesire!");
        exit(3);
    }

    pf_in = fopen(file_in_name, "rt");
    if(pf_in == NULL) {
        fputs("Fisierul nu exista!", pf_out);
        exit(2);
    }

    pf_dictionar = fopen(dictionar, "rt");

    if(pf_dictionar == NULL) {
        puts("Nu s-a reusit deschiderea fisierului dictionar!");
        exit(4);
    }

    nl = get_dict_no_lines(pf_dictionar);
    dict = read_dictionary(pf_dictionar, nl);

    while( fgets(buf, MAX_LINE, pf_in) != NULL ) {
        buf[strcspn(buf, "\r\n")] = 0;
        if(check_sep(buf[strlen(buf)-1], get_sep()))
            eol = buf[strlen(buf)-1];
        else
            eol = 0;

        word = strtok(buf, sep);
        while(word != NULL) {
            trad = translate(word, dict, nl);
            if(trad == NULL) {
                fputs("<<", pf_out);
                fputs(word, pf_out);
                fputs(">>", pf_out);
            }
            else {
                fputs(trad, pf_out);
            }
            word = strtok(0, sep);
            if(word)
                fputs(" ", pf_out);
        }
        if(eol) {
           fputc(eol, pf_out);
        }
        fputs("\n", pf_out);
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


char* translate(char* word, char** dict, int nl) {
    int i;

    for( i = 0; i < nl; i++) {
        if(strcmp(word, dict[i]) == 0) {
            return dict[i + nl];
        }
    }
    return NULL;
}


void getwords(char *line, char* words[], int index, int no_lines) {
    char *p;
    char* sep = get_sep();

    p = (char*) malloc( sizeof(char) * strlen(line));
    strcpy(p, line);

    while(check_sep(*p, sep) && *p != 0)
        p++;

    words[index] = p;

    while(!check_sep(*p, sep))
        p++;
    *p = 0;

    p++;
    while(check_sep(*p, sep))
        p++;

    words[index + no_lines] = p;
    while(!check_sep(*p, sep) && *p != 0)
        p++;
    *p = 0;
}

int check_sep(char p, char* sep) {
    int res = 0;
    int i;
    for( i = 0; i < strlen(sep); i++)
        if(p == sep[i])
            res = 1;
    return res;
}

int get_dict_no_lines(FILE* pf_dict) {
    int res = 0;
    char buf2[MAX_LINE];

    rewind(pf_dict);
    while( fgets(buf2, MAX_LINE, pf_dict) != NULL ) {
            res++;
    }
    return res;
}

char** read_dictionary(FILE* pf_dict, int no_lines) {
    char** words;
    int index = 0;
    char buf2[MAX_LINE];

    words = (char**) malloc (sizeof(char*) * 2 * no_lines );

    rewind(pf_dict);

    while( fgets(buf2, MAX_LINE, pf_dict) != NULL ) {
        buf2[strcspn(buf2, "\r\n")] = 0;
        getwords(buf2, words, index, no_lines);
        index++;
    }
    return words;
}

char* get_sep() {
    char* sep = " \t.;,:";
    return sep;
}
