// Boari Ioana 312CD//
#include <stdio.h>
#define douazeci_si_noua 29
#define treizeci_si_unu 31
#define douazeci_si_opt 28

int main() {
    unsigned int inst = 0, copie = 0, mask1 = 0, mask2 = 0;
    unsigned int N = 0, op = 0, Dim = 0;
    char operatii[4] = {'+', '-', '*', '/'};
    scanf("%u", &inst);  // se citeste instructiunea //
    copie = inst;
    // se interpreteaza primii 3 biti pentru a afla nr de operatii//
    N = (inst >> douazeci_si_noua) + 1;
    printf("%d ", N);
    for (int i = treizeci_si_unu; i > douazeci_si_opt; i--) {
        mask1 = ~(1 << i);
        copie = copie & mask1;
    }  // se reseteaza primii 3 biti (valoarea devine 0) //
    for (int j = 1; j < (N + 1); j++) {
        // se interpreteaza bitii pentru operatii //
        op = (copie >> (douazeci_si_noua - 2*j));
        printf("%c ", operatii[op]);  // se afiseaza operatiile //
        for (int k = (douazeci_si_opt - ((j-1) * 2)); k > (douazeci_si_opt - (j * 2)); k--) {
            mask2 = ~(1 << k);
            copie = (copie & mask2);
        }  // dupa fiecare operatie, bitii aferenti acelei operatii se reseteaza //
    }
    /* se interpreaza ultimii 4 biti semnificativi
    pentru a afla dimensiunea unui operand */
    Dim = (copie >> (douazeci_si_noua - (2*N) - 4)) + 1;
    printf("%d\n", Dim);
}
