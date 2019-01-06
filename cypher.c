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

void preprocess_caesar(char* buf);
int control_sum(char*);

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

void preprocess_caesar(char* buf) {
    int i;
    for (i = 0; i < strlen(buf); i++) {
       if(isupper(buf[i]))
        buf[i] = tolower(buf[i]);
    }
    for (i = 0; i < strlen(buf); i++) {
        if(!isalpha(buf[i]))
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
        preprocess_caesar(buf);
        for(i = 0; i < strlen(buf); i++) {
            if(isalpha(buf[i])) {
                buf[i] = (buf[i] - 'a' + key_no) % 26 + 'a';
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
                buf[i] -=key_no;
                if(buf[i] < 'a')
                    buf[i] = buf[i] + 'z' - 'a' + 1;
            }
        }
        puts(buf);
        strcat(buf, "\n");
        fputs(buf, pf_out);
    }
}




void dec_xor(FILE* pf_in, FILE* pf_out, char* key){}


void en_vigenere(FILE* pf_in, FILE* pf_out, char* key) {
    
    char buf[1024];
    int i, j, n;
    int keyLength = strlen(key);
    
    while( fgets(buf, 1024, pf_in) != NULL ) {
        for (i = 0, j = 0, n = strlen(buf); i < n; i++) {   
            if (isalpha(buf[i])) {
                if(isupper(buf[i]))
                    buf[i] = tolower(buf[i]);
                
                char keyFirstLetter = (isupper(key[j % keyLength])) ? 'A' : 'a';
            
                // ci = (pi + kj) % 26 
                buf[i] = ((buf[i] - 'a' + (key[(j % keyLength)] - keyFirstLetter)) % 26) + 'a';
                j++;
            }
        }    
        puts(buf);
        fputs(buf, pf_out);
    }
}

void dec_vigenere(FILE* pf_in, FILE* pf_out, char* key) {
    
    char buf[1024];
    int i, j;
    int keyLength = strlen(key);
    
    while( fgets(buf, 1024, pf_in) != NULL ) {
        for (int i = 0, j = 0, n = strlen(buf); i < n; i++) {   
            if (isalpha(buf[i])) {
                if(isupper(buf[i]))
                    buf[i] = tolower(buf[i]);
                
                char keyFirstLetter = (isupper(key[j % keyLength])) ? 'A' : 'a';
                buf[i] = ((buf[i] - 'a' - (key[(j % keyLength)] - keyFirstLetter)) % 26) + 'a';
                j++;
            }
        }    
        puts(buf);
        fputs(buf, pf_out); 
    }
}



int control_sum(char* word) {
    int s = 0;
    int i;
    for(i = 0; i < strlen(word); i++) {
        s += word[i];
    }
    return (s % 256);
}

void en_xor(FILE* pf_in, FILE* pf_out, char* key){
    FILE* pf_key;
    char buf[1024];
    int i, sc, res;
    char* word;
    char* sep = " \t,";

    pf_key = fopen(key, "rb");
    if(pf_key == NULL) {
        puts("Nu s-a reusit deschiderea fisierului cheie!");
        exit(5);
    }

    while( fgets(buf, 1024, pf_in) != NULL ) {
        buf[strcspn(buf, "\r\n")] = 0;
        word = strtok (buf, sep); // primul cuvant din linie
	    while ( word != NULL ) {
           
		    sc = control_sum(word);
            printf("%d\n", sc);
            res = fseek(pf_key, SEEK_SET, sc);
            if(res != 0) {
                puts("Eroare la pozitionare in fisierului cheie!");
                exit(6);
            }
            char* wkey = (char*) malloc(sizeof(char) * strlen(word));
            res = fread(wkey, sc, 1, pf_key);
            if(res != 0) {
                puts("Eroare la citirea din fisierului cheie!");
                exit(7);
            }
            for (i = 0; i < strlen(word); i++) {
                word[i] = word[i] ^ wkey[i];
            }
            puts(word);
		    word = strtok(0, sep); // urmatorul cuvant din linie
	    }
    }


}