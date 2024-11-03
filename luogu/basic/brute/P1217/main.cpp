#include <bits/stdc++.h>
using namespace std;
int primes[2000];
bool isPrime(int x) {
    for (int i=2; i*i<=x; ++i) 
        if (!(x%i)) return false;
    return true;
}
int gen_palin(int x) { // l: length hl: half> length
    int arr[4], pal[8], hl, l;
    for (hl=0; x!=0; ++hl) {
        arr[hl] = x%10;
        x/=10;
    }
    static bool second=0;
    if (second==0) {
        l=2*hl-1;
        second=1;
    } else {
        l=2*hl;
        second=0;
    }
    for (int i=0; i<hl; ++i) {
        pal[hl-1-i] = arr[i];
        pal[l-1-hl+1+i] = arr[i];
    }
    int result=0;
    for (int i=0; i<l; ++i) {
        result += pal[i] * pow(10, i);
    }
    return result;
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int primes_len=0;
    for (int i = 1; i<=9999; ++i) {
        int palin1 = gen_palin(i);
        int palin2 = gen_palin(i);
        if (palin1>=a&&palin1<=b && isPrime(palin1)) primes[primes_len++]=palin1;
        if (palin2>=a&&palin2<=b && isPrime(palin2)) primes[primes_len++]=palin2;
    }
    sort(primes, primes+primes_len);
    for (int i=0; i<primes_len; ++i)
        printf("%d\n", primes[i]);
}
// int main() {
//     int i;
//     scanf("%d", &i);
//     printf("%d %d\n", gen_palin(i), gen_palin(i));
// }