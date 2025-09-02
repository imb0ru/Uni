#include <stdio.h>
#define SIZE 10
void bubble(int[],const int, void (*)(int,int,int*)); 
//si noti il parametro di tipo puntatore a funzione
void ascending(int,int,int*);
void descending(int,int,int*);

int main(){
    int order,
    counter,
    a[SIZE] = {2,6,4,8,10,12,89,68,45,37};

    printf("Enter 1 to sort in ascending order,\n"
    "Enter 2 to sort in descending order: ");

    scanf("%d",&order);

    printf("\nData items in original order\n");

    for(counter=0;counter<SIZE;counter++){
        printf("%5d",a[counter]);
    }

    if(order==1){
        bubble(a,SIZE,ascending);
        printf("\nData items in ascending order\n");
    }else{
        bubble(a,SIZE,descending);
        printf("\nData items in descending order\n");
    }

    for(counter=0;counter<SIZE;counter++){
        printf("%5d",a[counter]);
    }

    printf("\n");

    return 0;
}

void bubble(int work[],const int size, void (*compare)(int,int,int*)){
    int pass,
    count,
    bool;

    void swap(int*,int*);
    
    for(pass=1;pass<size;pass++){
        for(count=0;count<size-1;count++){
            (*compare)(work[count],work[count+1],&bool); 
            //ascending e descending restituiscono in bool il risultato
            //che puo' essere 0 o 1.

            //bubble chiama swap se bool e' 1.

            //nota come i puntatori a funzione vengano chiamati
            // con l'operatore di deferenziazione (*), 
            //che, seppur non sia strettamente necessario, 
            //enfatizza come compare sia un puntatore a funzione 
            //e non una funzione vera e propria.
            if(bool){
                swap(&work[count],&work[count+1]);
            }
        }
    }
}

void swap(int *element1Ptr,int *element2Ptr){
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

void ascending(int a,int b, int *c){
    *c = a > b;
}

void descending(int a,int b, int *c){
    *c = a < b;
}

