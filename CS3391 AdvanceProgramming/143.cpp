#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

    
struct Edge{
    int a,b, w;
};

int m , n ;
Edge e[5000];
int compareFunction(const void* a, const void* b){
    return ((Edge *)a)->w > ((Edge *)b)->w;
}

int disjointSet[101] ;

int setIndex(int index){
    if (index == disjointSet[index]){
        return index;
    }else{
        return disjointSet[index] = setIndex(disjointSet[index]);
    }
}
void unionAtoB(int indexOfA,int indexOfB){
    disjointSet[indexOfA] = indexOfB;
}

int slimnessFromI(int start){
    // start from blank disjoint set
    for(int i = 1 ;i <= n ; i++){
        disjointSet[i] = i;
    }

    // for each edge from start

    int min = e[start].w,max;
    int count =0;
    for (int edgeIdx = start ; edgeIdx < m ; edgeIdx++){
        // while(edgeIdx < m && e[edgeIdx].w == e[edgeIdx - 1].w){
            int indexOfA = setIndex(e[edgeIdx].a);
            int indexOfB = setIndex(e[edgeIdx].b);
            if (indexOfA != indexOfB){
                unionAtoB(indexOfA,indexOfB);
                max = e[edgeIdx].w;
                count ++;
            }
            // edgeIdx++;
        // }
    }
    return  count >=n-1?(max - min):10001;
}


int main()
{
    while (~scanf("%i%i",&n,&m) && n != 0)
    {
        memset(e, 0, sizeof(e));

        for (int i = 0; i < m; i++)
        {
            scanf("%i%i%i",&(e[i].a),&(e[i].b),&(e[i].w));
        }

        qsort(e,m,sizeof(Edge),compareFunction);

        // is graph connected?

        // first step is to iterate all i
        int slimness = 10001;
        for(int i = 0 ; i < m ; i++){
            slimness = std::min(slimnessFromI(i),slimness);
            // $(slimness);
            // $(i);
        }
        if (slimness == 10001){
            printf("-1\n");
        }else{
            printf("%i\n",slimness);
        }
        
    }

    return 0;
}