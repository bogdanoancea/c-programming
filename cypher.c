#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



char* get_file_in(int l, char* param[]); 
char* get_file_out(int l, char* param[]); 
char* get_key(int l, char* param[]); 
char* get_mode(int l, char* param[]); 
char* get_alg(int l, char* param[]); 
void encrytion(FILE* pf_in, FILE* pf_out, char* alg, char* key);
void decrytion(FILE* pf_in, FILE* pf_out, char* alg, char* key);
void en_caesar(FILE* pf_in, FILE* pf_out, char* key);
void dec_caesar(FILE* pf_in, FILE* pf_out, char* key);
void en_vigenere(FILE* pf_in, FILE* pf_out, char* key);
void dec_vigenere(FILE* pf_in, FILE* pf_out, char* key);
void en_xor(FILE* pf_in, FILE* pf_out, char* key);
void dec_xor(FILE* pf_in, FILE* pf_out, char* key);

void preprocesare_caesar(char* buf);

int main(int argc, char* argv[] ) {
    FILE* pf_in;
    FILE* pf_out;
    char* key;
    char* mode;
    char* alg;
    char* file_in_name;
    char* file_out_name;

    if(argc != 11) {
        puts("Numarul de parametrii este incorect!");
        puts("Programul se foloseste astfel: >tema2.exe –in file_in.txt –out file_out.txt –key 5 -mode enc –alg alg_name");
        exit(1);
    }

    file_in_name = get_file_in(argc, argv);
    file_out_name = get_file_out(argc, argv);
    key = get_key(argc, argv);
    mode = get_mode(argc, argv);
    alg = get_alg(argc, argv);

    if(strcmp(mode, "enc") != 0 && strcmp(mode, "dec") != 0 ) {
        puts("Parametrul mode trebuie sa fie enc sau dec");
        exit(2);
    }
    

    if(strcmp(alg, "caesar") != 0 && strcmp(alg, "vigenere") != 0  && strcmp(alg, "xor") != 0 ) {
        puts("Parametrul alg trebuie sa fie caesar sau vigenere sau xor");
        exit(3);
    }
    
    pf_in = fopen(file_in_name, "rt");
    if(pf_in == NULL) {
        puts("Nu s-a reusit deschiderea fisierului de intrare!");
        exit(4);
    }

    pf_out = fopen(file_out_name, "wt");
    if(pf_out == NULL) {
        puts("Nu s-a reusit deschiderea fisierului de iesire!");
        exit(4);
    }

    if(strcmp(mode, "enc") == 0) {
        encrytion(pf_in, pf_out, alg, key);
    } else {
        decrytion(pf_in, pf_out, alg, key);
    }

    fclose(pf_in);
    fclose(pf_out);
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

char* get_key(int l, char* param[]) {
    int i;

    for(i = 1; i < l; i++) {
        if(strcmp("-key", param[i]) == 0)
            return param[i+1];
    }
    return NULL;
}

char* get_mode(int l, char* param[]) {
    int i;

    for(i = 1; i < l; i++) {
        if(strcmp("-mode", param[i] ) == 0)
            return param[i+1];
    }
    return NULL;
}

char* get_alg(int l, char* param[]) {
    int i;

    for(i = 1; i < l; i++) {
        if(strcmp("-alg", param[i]) == 0)
            return param[i+1];
    }
    return NULL;
}

void encrytion(FILE* pf_in, FILE* pf_out, char* alg, char* key ) {
    if(strcmp(alg, "caesar") == 0)
        en_caesar(pf_in, pf_out, key);
    else 
        if(strcmp(alg, "vigenere") == 0)
            en_vigenere(pf_in, pf_out, key);
        else
            en_xor(pf_in, pf_out, key);
}

void decrytion(FILE* pf_in, FILE* pf_out, char* alg, char* key ) {
    if(strcmp(alg, "caesar") == 0)
        dec_caesar(pf_in, pf_out, key);
    else 
        if(strcmp(alg, "vigenere") == 0)
            dec_vigenere(pf_in, pf_out, key);
        else
            dec_xor(pf_in, pf_out, key);
}

void preprocesare_caesar(char* buf) {
    int i;
    for (i = 0; i < strlen(buf); i++) {
        if(buf[i] >= 'A' && buf[i] <= 'Z')
            buf[i]+=32;
    }
    for (i = 0; i < strlen(buf); i++) {
        if(buf[i] < 'a' || buf[i] > 'z')
            buf[i] ='q';
    }
}

void en_caesar(FILE* pf_in, FILE* pf_out, char* key) {
 
    char buf[1024];
    int i;
    int key_no;

    key_no = atoi(key);
   
    while( fgets(buf, 1024, pf_in) != NULL ) {
        buf[strcspn(buf, "\r\n")] = 0;
        preprocesare_caesar(buf);
        for(i = 0; i < strlen(buf); i++) {
            if(isalpha(buf[i])) {
                buf[i] += key_no;
                if(buf[i] >= 'z')
                    buf[i] = buf[i] - 'z' + 'a' - 1;
            }
        }
        puts(buf);
        strcat(buf, "\n");
        fputs(buf, pf_out);
        
    }
}


void dec_caesar(FILE* pf_in, FILE* pf_out, char* key) {
 
    char buf[1024];
    int i;
    int key_no;

    key_no = atoi(key);
   
    while( fgets(buf, 1024, pf_in) != NULL ) {
        buf[strcspn(buf, "\r\n")] = 0;
        for(i = 0; i < strlen(buf); i++) {
            if(isalpha(buf[i])) {
                buf[i] -= key_no;
                if(buf[i] < 'a')
                    buf[i] = buf[i] + 'z' - 'a' + 1;
            }
        }
        puts(buf);
        strcat(buf, "\n");
        fputs(buf, pf_out);
        
    }
}


void dec_vigenere(FILE* pf_in, FILE* pf_out, char* key) {}
void en_xor(FILE* pf_in, FILE* pf_out, char* key){}
void dec_xor(FILE* pf_in, FILE* pf_out, char* key){}


void en_vigenere(FILE* pf_in, FILE* pf_out, char* key) {
    
    char buf[1024];
    int i, j;
    int keyLength = strlen(key);
    
    while( fgets(buf, 1024, pf_in) != NULL ) {
        //buf[strcspn(buf, "\r\n")] = 0;
        for (int i = 0, j = 0, n = strlen(buf); i < n; i++) {   
            // if alphabetic proceed with ciphering, else return normal character
            if (isalpha(buf[i])) {
            
                // calculate ASCII code for the key position (j), wrap around beginning of keyword when end of keyword is reached
                char keyReferenceValue = (isupper(key[j % keyLength])) ? 'A' : 'a';
            
                // calculate ASCII code of the first letter of alphabet depending on upper- or lowercase
                char referenceValue = (isupper(buf[i])) ? 'A' : 'a';
            
                // calculate cipher letter using formula ci = (pi + kj) % 26, then convert to right ASCII character number
                buf[i] = ((buf[i] - referenceValue + (key[(j % keyLength)] - keyReferenceValue)) % 26) + referenceValue;
                j++;
            }
        }    
        puts(buf);
        fputs(buf, pf_out);
        
    }
}