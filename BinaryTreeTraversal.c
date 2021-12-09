#include<stdio.h>

int len, number = 0;

void inorder(int tree[], int n){
    if (n > len)
        return ;
    inorder(tree, 2*n);    
    printf("%d ", tree[n]);
    inorder(tree, 2*n+1);
}
void postorder(int tree[], int n){
    if (n > len)
        return ;
    postorder(tree, 2*n);
    postorder(tree, 2*n+1);
    printf("%d ", tree[n]);
}
void preorder(int tree[], int n){
    if (n > len)
        return ;
    printf("%d ", tree[n]);
    preorder(tree, 2*n);
    preorder(tree, 2*n+1);
}

int main(){
    int kind, degree, exp=2;
    scanf("%d", &kind);
    scanf("%d", &len);
    for(int i=1;i<20;i++){
        degree = i;
        if (exp > len) break;
        exp*=2;
    }
    int tree[len+1];
    tree[0] = 0;
    for(int i=1;i<len+1;i++)
        scanf("%d", &tree[i]);
    
    if (kind == 0)
        preorder(tree, 1);
    else if (kind == 1)
        inorder(tree, 1);
    else if (kind == 2)
        postorder(tree, 1);
    
    return 0;
}
