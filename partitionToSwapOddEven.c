#include <stdio.h>

// 讓even在前，odd在後
void swap_odd_even(int x[], int node_num)
{
    int s = 0;
    int e = node_num-1;
    
    while(s < e){
        while(x[s] %2 ==0){
            s = s+1;
        };
        while(x[e] %2 ==1){
            e = e-1;
        };
        if(s<e)
        {
            int temp = x[s];
            x[s] = x[e];
            x[e] = temp;
        };
    }
    for(int p = 0; p < node_num; p++)
    {
        printf("%d\n", x[p]);
    };
}

int main()
{
    int a[] = {1,2,4,7};
    swap_odd_even(a, 4);
    return 0;
}
