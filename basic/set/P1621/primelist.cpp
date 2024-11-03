#include <stdio.h>
bool isPrime(int x) {
    for (int i=2; i*i<=x; ++i) {
        if (x%i==0) return false;
    }
    return true;
}
int main() {
    printf("{");
    for (int i=2; i<=100000; ++i) {
        if (isPrime(i)) printf("%d,", i);
    }
    printf("}\n");
}
