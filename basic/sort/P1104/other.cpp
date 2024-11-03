#include<bits/stdc++.h>
using namespace std;
struct Person{
    char name[25];
    int year,mon,day;
    bool operator <(Person tmp)const{
        if(year!=tmp.year) return year<tmp.year;
        if(mon!=tmp.mon) return mon<tmp.mon;
        if(day!=tmp.day) return day<tmp.day;
    }
};
Person oiers[105];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char c=getchar();
        //过滤行末换行
        scanf("%s %d %d %d", oiers[i].name, &oiers[i].year, &oiers[i].mon, &oiers[i].day);
    }
    stable_sort(oiers+1,oiers+n+1);
    //STL自带的稳定排序 
    for(int i=1;i<=n;i++) cout<<oiers[i].name<<endl;
    return 0;
}