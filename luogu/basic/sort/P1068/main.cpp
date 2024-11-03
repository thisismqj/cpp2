#include <bits/stdc++.h>
using namespace std;
struct Employee {
    int id;
    int score;
} employees[5005];
// 写比较器
// 分数高的<分数低的
// 同分则id小的<id大的
bool cmp(Employee &e1, Employee &e2) {
    if (e1.score!=e2.score) return e1.score>e2.score;
    return e1.id < e2.id;
}
int main() {
    int n, m; // 总数， 计划
    scanf("%d %d", &n, &m);
    m = m * 1.5f;
    for (int i=0; i<n;++i) {
        int _id, _score;
        scanf("%d %d", &_id, &_score);
        employees[i].id = _id;
        employees[i].score = _score;
    }
    sort(employees, employees+n, cmp);
    int enterLine, i;
    for (i=0; i<m; ++i) {
        enterLine = employees[i].score;
    }
    while (employees[i].score==enterLine) ++i;
    printf("%d %d\n", enterLine, i);
    for (int j=0; j<i; ++j)
        printf("%d %d\n", employees[j].id, employees[j].score);
}

