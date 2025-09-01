#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

typedef struct { 
    int elem[MAX];
    int count;
}List;

List L;
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
List display(List L);

int main(){


}


List initialize(List L){
    L.count = 0;
    return 0;
}


List insertPos(List L, int data, int position){
    if(pos <= L.count && L.count < MAX){
        for( int i = L.count; i > pos; i--){
            L.elem[i] = L.elem[i - 1];
        }
        L.elem[pos] = data; 
        L.count++;
    }
    return 0;
}
List deletePos(List L, int position){
    if(pos < L.count){
        for(int i = L.count; i > pos; i--){
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
    }
    return 0;
}
int locate(List L, int data){

    for(int i = 0; L.count; i++){
        if(L.elem[i] == data) return 1;

    }
    return -1;
}

List insertSorted(List L, int data){
    if(L.count < MAX){
        int i = L.count -1;
        while (i >= 0 && L.elem[i] > data){
            L.elem[i + 1] = data; 
            L.count++;
        }
        return L;
    }


List display(List L){
    for(int i = 0; L.count; i++){
        printf("%d", L.elem[i]);
    }
    printf("\n");
}
