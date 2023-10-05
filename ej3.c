#include <stdio.h>
#include <limits.h>
#include <assert.h>

int anagrama(char * s1, char * s2);

int main() {
    char * s = "anagrama";

    assert(anagrama(s, "amar gana"));
    assert(anagrama("enrique", "quieren"));
    assert(anagrama(s, s));
    assert(anagrama(" ", ""));
    assert(anagrama("amar gana", s));
    assert(anagrama("", ""));
    assert(anagrama("a gentleman", "elegant man"));
    assert(anagrama("a", "") == 0);
    assert(anagrama("mar", "amar") == 0);

    puts("OK!");
    return 0;
}

void count(char * s, int vec[], int inc) {
    for (int i = 0; s[i] != '\0'; i++) {
        if(s[i] != ' ') {
            vec[(int)s[i]] += inc;
        }
    }
}

int anagrama(char * s1, char * s2) {
    // uso int pq aclara que se podrian recibir frases extensas
    int apariciones[UCHAR_MAX] = {0};

    count(s1, apariciones, 1);
    count(s2, apariciones, -1);

    for (int i = 0; i < UCHAR_MAX; i++) {
        if(apariciones[i] != 0) {
            return 0;
        }
    }
    return 1;
}
