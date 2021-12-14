#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 15000

void split(char str[], int len){
    char even_str[len], odd_str[len];
    int even_len=0, odd_len=0;

    // input even and odd number
    for(int i=0;i<len;i++){
        if (i%2==0){
            even_str[even_len] = str[i];
            even_len++;
        }
        else{
            odd_str[odd_len] = str[i];
            odd_len++;
        }
    }

    // compute each even and odd number sums
    int even_sum=0, odd_sum=0;
    char even_hex[N], odd_hex[N];
    for(int i=0;i<even_len;i++){
        if('0' <= even_str[i] && even_str[i] <= '9'){
            even_sum += (even_str[i] - '0');
        }
        else if('A' <= even_str[i] && even_str[i] <= 'Z'){
            even_sum += (even_str[i] - 'A' + 10);
        }
        else if('a' <= even_str[i] && even_str[i] <= 'z'){
            even_sum += (even_str[i] - 'a' + 10);
        }
    }
    for(int i=0;i<odd_len;i++){
        if('0' <= odd_str[i] && odd_str[i] <= '9'){
            odd_sum += (odd_str[i] - '0');
        }
        else if('A' <= odd_str[i] && odd_str[i] <= 'Z'){
            odd_sum += (odd_str[i] - 'A' + 10);
        }
        else if('a' <= odd_str[i] && odd_str[i] <= 'z'){
            odd_sum += (odd_str[i] - 'a' + 10);
        }
    }

    // dec to hex
    sprintf(even_hex, "%x", even_sum);
    sprintf(odd_hex, "%x", odd_sum);

    // save the data
    if (strlen(odd_hex) <= 1)
        printf("%c", odd_hex[0]);
    else
        split(odd_hex, strlen(odd_hex));

    if (strlen(even_hex) <= 1)
        printf("%c", even_hex[0]);
    else   
        split(even_hex, strlen(even_hex));
}
int main(){
    char str[N];
    scanf("%s", str);
    split(str, strlen(str));

    return 0;
}
