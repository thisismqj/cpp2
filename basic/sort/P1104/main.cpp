#include <bits/stdc++.h>
using namespace std;
struct Person {
    char name[22];
    int year, month, day;
    int index;
} oiers[100];
bool cmp(Person &first, Person &second) {
    if (first.year!=second.year) return first.year<second.year;
    if (first.month!=second.month) return first.month<second.month;
    if (first.day!=second.day) return first.day<second.day;
    return first.index > second.index;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%s %d %d %d", oiers[i].name, &oiers[i].year, &oiers[i].month, &oiers[i].day);
        oiers[i].index = i;
    }
    sort(oiers, oiers+n, cmp);
    for (int i=0; i<n; ++i) {
        printf("%s\n", oiers[i].name);
    }
}

