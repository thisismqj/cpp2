// 80pts
#include <bits/stdc++.h>
using namespace std;
int quene[20*20]; // 安排序列
struct Step {
    int i=0;
    int m; // 机器
    int l; // 长度
    int t; // 完成时间
} st[20][20];// 工件列表
Step *quene_arr[20*20]; // 工件set arr
bool m_t[20][10000];
int main() {
    int m, n, max_t=0;// m: 工序长度， n: 工件数
    cin >> m >> n;
    for (int i=0; i<m*n; ++i){
        cin >> quene[i];    // 录入安排序列
    }
    for (int i=0; i<n; ++i) // 录入机器号
        for (int j=1;j<=m;++j){
            cin>>st[i][j].m;
            --st[i][j].m;
        }
    for (int i=0; i<n; ++i) // 录入加工时长
        for (int j=1;j<=m;++j)
            cin>>st[i][j].l;
    // for (int i=0; i<m*n; ++i) { // 更新工序set arr
    //     int q_i = quene[i]; // 工序号
    //     for (int j=0; j<n; ++j) { // j: 工件号
    //         // 逐工件遍历，若未安排此道工序则安排
    //         if (!st[j][q_i].i) { // 录入工序 从1开始
    //             st[j][q_i].i = q_i;
    //             quene_arr[i] = &st[j][q_i];// 回调
    //             break;
    //         }
    //     }
    // }
    for (int i=0; i<m*n; ++i) {
        Step *machine = st[quene[i]-1]+1; // machine的序列指针
        for (int j=1; j<=m; ++j, ++machine) {
            // 如果没有被录入
            if (!machine->i) {
                machine->i = j;
                quene_arr[i] = machine;
                break;
            }
        }
    }
    for (int i=0; i<m*n; ++i) {
        // 遍历安排序列，插入时间
        int len=1; // 含j指针的长度
        Step *cur_ord=quene_arr[i]; // 当前安排指针
        bool *p = m_t[cur_ord->m]; // 时间表头指针
        for (int j=0; j<10000; ++j) { // j: 时刻 0, 1, ...
            // 空余长度需大于等于长度， 当前是第一个工序或者前一工序已完成
            if (len>=cur_ord->l&&(cur_ord->i==1||j-cur_ord->l>=(cur_ord-1)->t)) {
                // 置1
                for (int k=j; k>j-cur_ord->l; --k)
                    p[k] = 1;
                // 更新完成时间
                cur_ord->t=j;
                // 更新时长
                max_t = j>max_t?j:max_t;
                break;
            } else if (p[j]){// 不满足: 清零 继续
                len=0;
            }
            ++len;
        }
    }
    cout<<++max_t;
}

