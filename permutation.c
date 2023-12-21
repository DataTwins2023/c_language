#include <stdio.h>

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;                                                                                             
};


void perm(int a[3], int i, int n)
{
    if(i == n){
        for(int x = 0; x <= n; x++){
            printf("%d", *(a+x));
        }
        printf("\n%d\n",100000);
    }
    else{
        for(int j = i; j <= n; j++){
            swap(&a[i], &a[j]);
            perm(a, i+1, n);
            swap(&a[i], &a[j]);
        }
    }
};

int main()
{
    int array[3] = {1,2,3};
    perm(array,0,2);
    return 0;
}
