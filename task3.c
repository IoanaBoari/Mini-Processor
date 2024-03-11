// Boari Ioana 312CD//
#include <stdio.h>
#define douazeci_si_noua 29
#define treizeci_si_unu 31
#define douazeci_si_opt 28
#define saisprezece 16
#define cincisprezece 15
#define SIZE 100

int main() {
    unsigned int inst = 0, copie = 0, mask1 = 0, mask2 = 0, mask3 = 0;
    unsigned int N = 0, op = 0, Dim = 0;
    unsigned int nr = 0;
    char operatii[4] = {'+', '-', '*', '/'};
    char opr[SIZE];  // vectorul retine operatiile decodificate //
    short unsigned int numere[SIZE];  // vectorul retine nr introduse //
    short unsigned int numere_cp[SIZE];
    short unsigned int operanzi[SIZE];  // vectorul retine operanzii //
    int m = 0, n = 0, result = 0;
    scanf("%u", &inst);  // se citeste instructiunea //
    copie = inst;
    // se interpreteaza primii 3 biti pentru a afla nr de operatii//
    N = (inst >> douazeci_si_noua) + 1;
    for (int i = treizeci_si_unu; i > douazeci_si_opt; i--) {
        mask1 = ~(1 << i);
        copie = copie & mask1;
    }  // se reseteaza primii 3 biti (valoarea devine 0) //
    for (int j = 1; j < (N + 1); j++) {
        // se interpreteaza bitii pentru operatii //
        op = (copie >> (douazeci_si_noua - 2*j));
        opr[j-1] = operatii[op];  // operatiile se retin in vectorul opr[] //
        for (int k = (douazeci_si_opt - ((j-1) * 2)); k > (douazeci_si_opt - (j * 2)); k--) {
            mask2 = ~(1 << k);
            copie = (copie & mask2);
        }  // dupa fiecare operatie, bitii aferenti acelei operatii se reseteaza //
    }
    /* se interpreaza ultimii 4 biti semnificativi
    pentru a afla dimensiunea unui operand */
    Dim = (copie >> (douazeci_si_noua - (2*N) - 4)) + 1;
    if (((N+1)*Dim)%saisprezece == 0) {
        nr = ((N+1)*Dim)/saisprezece;
    } else {
        nr = ((N+1)*Dim)/saisprezece + 1;
    }  // se stabilesc cate nr trebuie introduse //
    for (m = 0; m < nr; m++) {
        scanf("%hu", &numere[m]);  // se citesc numerele //
    }
    for (m = 0; m < nr; m++) {
        numere_cp[m] = numere[m];  // se copiaza numerele in alt vector //
    }
    m = 0;
    for (n = 0; n < N + 1;) {
        if (saisprezece%Dim == 0) {
    // r = cati operanzi reies din fiecare nr introdus //
        for (int r = saisprezece/Dim; r > 0; r--) {
            // se interpreteaza bitii numerelor pentru a extrage operanzii //
            operanzi[n] = numere_cp[m] >> ((r-1) * Dim);
            for (unsigned int l = (cincisprezece - ((saisprezece/Dim - r) * Dim));
            l > (cincisprezece - ((saisprezece/Dim - r + 1) * Dim)); l--) {
                mask3 = ~(1 << l);
                numere_cp[m] = (numere_cp[m] & mask3);
            }  // bitii interpretati se reseteaza //
            n++;
        }
        m++;
    } else {
    // r = cati operanzi reies din fiecare nr introdus //
        for (int r = saisprezece/Dim; r > 0; r--) {
            // se interpreteaza bitii numerelor pentru a extrage operanzii //
            operanzi[n] = numere_cp[m] >> (saisprezece - Dim);
            for (unsigned int l = (cincisprezece - ((saisprezece/Dim - r) * Dim));
            l > (cincisprezece - ((saisprezece/Dim - r + 1) * Dim)); l--) {
                mask3 = ~(1 << l);
                numere_cp[m] = (numere_cp[m] & mask3);
            }  // bitii interpretati se reseteaza //
            numere_cp[m] = numere_cp[m] << Dim;
            numere_cp[m+1] = numere_cp[m+1] >> ((m+1)*(saisprezece - Dim));
            numere_cp[m+1] = numere_cp[m] | numere_cp[m+1];
            n++;
        }
        m++;
    }
    }
    result = operanzi[0];
    for (int p = 0; p < N; p++) {
        /* operatiile se executa in ordine,
        fara a tine cont de precedenta */
        if (opr[p] == '+') {
                result = result+operanzi[p+1];
        } else if (opr[p] == '-') {
                result = result-operanzi[p+1];
        } else if (opr[p] == '*') {
                result = result*operanzi[p+1];
        } else if (opr[p] == '/') {
                result = result/operanzi[p+1];
        }
    }
    printf("%d\n", result);  // se afiseaza rezultatul //
    return 0;
}
