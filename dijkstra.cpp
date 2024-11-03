#include <bits/stdc++.h>
using namespace std;
const int max_node = 20;
struct Edge {
    int dst; int w;
} ;
vector<Edge> edges[max_node+5];
static int path[max_node+5], dist[max_node+5];
struct MyPQ {
    MyPQ(unsigned _sz){
        _p = 1;
        int i=0;
        while (_sz!=0) {
            _sz>>=1;
            ++i;
        }
        sz = 1<<i;
        arr = (int *)calloc(sz+1, sizeof(int));
    }
    bool empty() {return _p==1;}
    virtual bool cmp(int a, int b) {
        return dist[edges[a].dst]>dist[edges[b].dst];
    }
    void push(int x) {
        int p = _p++;
        if (p==1) arr[p] = x;
        else
            while (p!=1) {
                if (cmp(x, p>>1)) {
                    arr[p] = x;
                    return;
                } else {
                    arr[p] = arr[p>>1];
                    arr[p>>1] = x;
                    p>>=1;
                }
            }
    }
    int top() {return arr[1];}
    void pop() {
        unsigned i=1;
        while (2*i<_p) {
            int p = 2*i;
            if (2*i+1<_p && cmp(arr[2*i], arr[2*i+1])) p = 2*i+1;
            arr[i] = arr[p];
            i = p;
        }
        arr[i] = arr[--_p];
    }
    ~MyPQ() {free(arr);}
    int *arr;
    unsigned _p; // 指向待添加的元素
    unsigned sz;
};
int dijkstra(int s, int d) {
    memset(dist, 0x7f, sizeof(dist));
    dist[s] = 0;
    MyPQ nodes(max_node+5);
    nodes.push(s);
    while (!nodes.empty()) {
        int x=nodes.top();
        nodes.pop();
        for (Edge &e: edges[x]) {
            if (dist[x]+e.w<dist[e.dst]) {
                path[e.dst] = x;
                dist[e.dst]=dist[x]+e.w;
                nodes.push(e.dst);
            }
        }
    }
    int p=d;
    printf("%d", p);
    if (dist[d]!=0x7f7f7f7f) {
        while (p!=s) {
            p = path[p];
            printf("<-%d", p);
        }
        putchar('\n');
    }
    return dist[d];
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w);
        edges[from].push_back({to, w});
    }
    int s, d;
    scanf("%d%d", &s, &d);
    printf("%d", dijkstra(s, d));
    return 0;
}
