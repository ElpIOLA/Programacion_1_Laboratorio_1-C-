#include <stdio.h>
#include <stdlib.h>

int main()
{
    char vec[5] = {'f','j','q','h','a'};
    char aux;
    int i, j;

    for(i=0;i<4;i++){ //i = 5 - 1 (I NO LLEGA HASTA EL FINAL DEL VECTOR)

        for(j=i+1;j<5;j++){

            if(vec[i]>vec[j]){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    for(i=0;i<5;i++){
        printf("\nVector: %c",vec[i]);
    }
    return 0;
}
