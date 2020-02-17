#include "vt100.h"




void sleep(unsigned long int n) {
        /* boucle vide parcourue (n * 100000) fois*/
        int i = 0;
        unsigned long int max = n * 100000;
        do {
                i++;
        }
        while(i <= max);
}
