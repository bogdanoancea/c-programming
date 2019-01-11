#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define DEBUG 1

#define MAX_LINE 1024

char* get_file_in(int l, char* param[]);
char* get_file_out(int l, char* param[]);
char* get_limba_in(int l, char* param[]);
char* get_limba_out(int l, char* param[]);
char* translate(char* word, char** dict, int nl);
char* get_dict_name(char* limba_in, char* limba_out, char* folder);
char** read_dictionary(FILE* pf_dict, int no_lines);
void getwords(char *line, char* words[], int index, int no_lines);
int get_dict_no_lines(FILE* pf_dict);
char* get_sep();
int check_sep(char p, char* sep);
char* autodetect_dict(char* folder_dic, FILE* pf_in, FILE* pf_out);
char** get_dictionaries(char* folder_dic, int* no_dict);
int is_text_dict1(char* text, char** dictionar, int no_dic_lines);
int is_text_dict2(char* text, char** dictionar, int no_dic_lines);
char** read_input_text(FILE* pf_in, int* no_in_words);
char* replace_char(char* str, char find, char replace);



#ifdef DEBUG
int main(int argc, char* argv[]) {
    char* folder_dic = "translator/dictionare/";
    char* limba;
    char* file_in_name = get_file_in(argc, argv);
    char* file_out_name = get_file_out(argc, argv);
    char* limba_out = get_limba_out(argc, argv);
    FILE *pf_in, *pf_out;

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

    limba = autodetect_dict(folder_dic, pf_in, pf_out);
    puts(limba);
    return 0;
}
#else

int main(int argc, char* argv[] ) {
    FILE* pf_in;
    FILE* pf_out;
    FILE* pf_dictionar;
    char* limba_in;
    char* limba_out;
c    char* dictionar;
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

    if(limba_in != NULL)
        dictionar = get_dict_name(limba_in, limba_out, folder_dic);
    else
        dictionar = autodetect_dict(folder_dic);

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
#endif // DEBUG

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

char* get_dict_name(char* limba_in, char* limba_out, char* folder){
    char* dictionar = NULL;

    dictionar = (char*) malloc(sizeof(char) * (strlen(limba_in) + strlen(limba_out) + strlen(folder) + 5) );
    if(dictionar == NULL) {
        puts("Memorie insuficienta");
        exit(1);
    }
    dictionar[0] = 0;
    dictionar = strcat(dictionar, folder);
    dictionar = strcat(dictionar, limba_in);
    dictionar = strcat(dictionar, "-");
    dictionar = strcat(dictionar, limba_out);
    dictionar = strcat(dictionar, ".txt");
    return dictionar;
}

char* autodetect_dict(char* folder_dic, FILE* pf_in, FILE* pf_out) {
    char* res = NULL;
    char** dictionaries;
    char** dictionar = NULL;
    char** text;
    int no_in_words = 0;
    int no_dict = 0;
    int i,j;
    FILE* pf_dict;
    int no_dic_lines;
    int n1, n2;
    char* dictionar_name;

    dictionaries = get_dictionaries(folder_dic, &no_dict);
    for(i = 0; i < no_dict; i++) {
        puts(dictionaries[i]);
        n1 = n2 = 0;
        dictionar_name = NULL;
        dictionar_name = (char*) malloc(sizeof(char) * (strlen(folder_dic) + strlen(dictionaries[i])));
        if(dictionar_name == NULL) {
            puts("Memorie insuficienta");
            exit(1);
        }
        dictionar_name[0] = 0;
        dictionar_name = strcat(dictionar_name, folder_dic);
        dictionar_name = strcat(dictionar_name, dictionaries[i]);

        pf_dict = fopen(dictionar_name, "rt");
        if(pf_dict == NULL) {
            puts("Nu s-a reusit deschiderea fisierului dictionar!");
            exit(4);
        }
        no_dic_lines = get_dict_no_lines(pf_dict);
        dictionar = read_dictionary(pf_dict, no_dic_lines);
        //read input file
        text = read_input_text(pf_in, &no_in_words);
        //check if input text is in dict
        for(j = 0; j < no_in_words; j++) {
            if(is_text_dict1(text[j], dictionar, no_dic_lines)) {
                n1++;
            }
            if(is_text_dict2(text[j], dictionar, no_dic_lines)) {
                n2++;
            }

        }
        if(n1/no_in_words>=0.7) {
            replace_char(dictionaries[i], '-', 0);
            res = dictionaries[i];
            //am gasit limba 1 res = limba 1
        }
        else if (n2/no_in_words >=0.7) {
            // am gasit limba 2 res = limba2
            char *minus_pos = strchr(dictionaries[i],'-');
            replace_char(dictionaries[i], '.', 0);
            res = minus_pos;
        }
        else
            fputs("Limba necunoscuta", pf_out);

    }
    return res;
}

char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos){
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}

int is_text_dict1(char* text, char* dictionar[], int no_dic_lines) {
    int res = 0;
    int i;
    for(i = 0;  i < no_dic_lines; i++) {
        if(strcmp(text, dictionar[i]) == 0) {
            res = 1;
            break;
        }
    }
    return res;
}


int is_text_dict2(char* text, char* dictionar[], int no_dic_lines) {
    int res = 0;
    int i;
    for(i = 0;  i < no_dic_lines; i++) {
        if(strcmp(text, dictionar[i+no_dic_lines]) == 0) {
            res = 1;
            break;
        }
    }
    return res;
}

char** get_dictionaries(char* folder_dic, int* no_dict) {
    char** dictionaries = NULL;
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir (folder_dic)) != NULL) {
  /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {

            if(strcmp(ent->d_name, ".") !=0 && strcmp(ent->d_name, "..")!=0) {
                //puts(ent->d_name);
                if (dictionaries == NULL)
                    dictionaries = (char**) malloc (sizeof(char*));
                else
                    dictionaries = (char**)realloc(dictionaries, *no_dict + 1);

                dictionaries[*no_dict] = (char*) malloc(sizeof(char) * strlen(ent->d_name));
                strcpy(dictionaries[*no_dict] , ent->d_name);
                (*no_dict)++;
            }
        }
        closedir (dir);
    }
    return dictionaries;
}

char** read_input_text(FILE* pf_in, int* no_in_words) {
    char buf[MAX_LINE];
    char* sep = get_sep();
    char** text = NULL;
    char* word;

    while( fgets(buf, MAX_LINE, pf_in) != NULL ) {
        buf[strcspn(buf, "\r\n")] = 0;
        word = strtok(buf, sep);
        while(word != NULL) {
            if(text == NULL)
                text = (char**) malloc(sizeof(char*));
            else
                text = (char**) realloc(text, *no_in_words + 1);
            (*no_in_words)++;
            text[*no_in_words] = (char*) malloc(sizeof(char)*strlen(word));
            strcpy(text[*no_in_words], word);
            word = strtok(0, sep);
        }
    }
    return text;
}


