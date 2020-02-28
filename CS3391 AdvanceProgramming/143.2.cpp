#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define DUBUG true
#define OJ_DEBUG

#define $(x) {if (DUBUG) cout << #x << " = " << x << ' ' << '\n';}
#define _(x) {cout << #x << " = " << x << ' ';}


using namespace std;

int m ,n;
struct Edge{
    int a,b,w;
};


int a [100];
bool connected(Edge* e , int start, int end){
    for(int i = 1 ;i <= n ; i++){
        a[i] = i;
        // at first we havent seen any edge
        // everyedge is considered as individual
    }

    for (int i =start ;i <= end ;i++){
        if (a[e[i].a] != a[e[i].b]){
            // look from start to end change all a[e[i].a] to b
            int oldGroupNo = a[e[i].a];
            for(int j = 1 ;j <= n ; j++){
                if (a[j] == oldGroupNo){
                    a[j] = a[e[i].b];
                }
            }
        }
    }
    

    int everyoneShouldBe = a[1];
    for (int i= 1;i<=n ;i++){
        if (a[i] != everyoneShouldBe){
            return false;
        }
    }
    return true;

}

int slimify(Edge* e,int start , int end){ // end inclusive start inclusive
    // _(" ");
    if (start > end || !connected(e,start,end)){
        return INT_MAX;
    }
    if (e[start].w == e[end].w){
        return 0;
    }
    int res = e[end].w - e[start].w;
    if (res != 0){
        int endRight = end;
        while (e[endRight-1].w == e[endRight].w ){
            endRight--;
        }
        endRight --;
        int delRight = slimify(e,start,endRight);
        int startLeft = start;
        while(e[startLeft + 1].w == e[startLeft].w){
            startLeft ++;
        }
        startLeft++;
        int delLeft = slimify(e,startLeft,end);
        if (delRight < res){
            res = delRight;
        }
        if (delLeft < res){
            res = delLeft;
        }
    }
    return res;
}


int cmp(const void* e1,const void *e2){
    return ((Edge *)e1)->w-((Edge *)e2)->w;
}

int main(){

    Edge w[4951];
    int a,b,c;

	ios_base::sync_with_stdio(false);
    while (cin >> n >> m && n != 0 ){
        memset(w,0,sizeof(w));
        
        for (int i = 0 ;i < m ; i++){
            cin >> a >> b >>c;
            Edge e;
            e.a = a;
            e.b = b;
            e.w = c;
            w[i] = e;
        }

        qsort(w,m,sizeof(int)*3,cmp);

        connected(w,0,m-1);

        // from first edge to the last edge, 
        //     start accepting new edge until the minimum spanning tree can be formed
        //     calculate the difference
        

        
        // // got all edges ordered;

        // int slimest = slimify(w,0,m-1);
        int slimest = INT_MAX;
        if (slimest == INT_MAX){
            cout << "-1\n"; 
        }else{
            cout << slimest << '\n';
        }
            // // next step throw into slimify
            // for (int i = 0; i< m ;i++){
            //     cout << w[i].a << " " << w[i].b << " "<<w[i].w << endl;
            // }
        

    }
    


    return 0;
}

/*

4
5
1 2 3
3 4 7
2 4 6
1 3 5
1 4 6
*/