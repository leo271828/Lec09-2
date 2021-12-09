#include<stdio.h>

void sb_sort(int a[], int len){
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++)
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
void bs_sort(int a[], int len){
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++)
            if(a[i] < a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
int find_lonely(int data[], int total, int n){
    int flag = 1;
    for(int i=0;i<n;i++){
        if(total < 3) break;
        if(data[i] == -1) continue;
        flag = 1;

        for(int j=i+1;j<n;j++){
            if(!flag) break;
            if(data[j] == -1) continue;

            for(int k=0;k<n;k++){
                if(k == i || k == j)
                    continue;
                if(data[k] == -1) continue;
                if( (data[i] + data[j]) == data[k] ){
                    data[i] = -1;
                    data[j] = -1;
                    data[k] = -1;
                    flag = 0;
                    total-=3;
                    break;
                }
            }
        }
    }
    return total;
}
void print_data(int data[], int n){
    for(int i=0;i<n;i++)
        if(data[i] != -1)
            printf("%d ", data[i]);
}
int main(){
    int n;
    scanf("%d", &n);
    int raw_data[n], sb_data[n], bs_data[n], total = n;
    for(int i=0;i<n;i++){
        scanf("%d", &sb_data[i]);
        bs_data[i] = sb_data[i];
        raw_data[i] = bs_data[i];
    }
    sb_sort(sb_data, n);
    bs_sort(bs_data, n);

    int new_data[n], pos = 0, temp;
    do{
        temp = raw_data[pos];
        for(int i=0;i<n;i++)
            new_data[i] = raw_data[(i+pos)%n];

        // for(int i=0;i<n;i++)
        //     printf("%d ", new_data[i]);
        // printf("\n");

        pos++;
    } while( find_lonely(new_data, total, n) > 1 && pos < n );


    if( find_lonely(raw_data, total, n) > 1){ // big to small is failed.
        if( find_lonely(sb_data, total, n) > 1){
            if(find_lonely(bs_data, total, n) > 1){
                for(int i=0;i<n;i++)
                    if(new_data[i] != -1)
                        printf("%d ", new_data[i]);
            }
            else 
                print_data(bs_data, n);
        }
        else 
            print_data(sb_data, n);
    }
    else
        print_data(raw_data, n);

    return 0;
}
