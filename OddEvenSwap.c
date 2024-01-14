#include <stdio.h>

void swap(int *c, int *d){
    int temp;
    temp = *c;
    *c = *d;
    *d = temp;
}

int main()
{
    int array[7] ={1,2,7,4,8,11,9};
    int l =0;
    int r =6;
    while(l < r){
        /*遇到奇數就停*/
        while(array[l] % 2 ==0)
        {
            l+=1;
        }
        /*遇到偶數就停*/
        while(array[r] % 2 ==1)
        {
            r-=1;
        }
        if(l<r)
        {
            swap(array +l, array +r);
        }
    }
    
    for(int i =0; i <=6; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
