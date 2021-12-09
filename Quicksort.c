int partition(int a[], int low, int high){
    int pivot = a[high]; // last number in array is pivot
    int counter = low;
    for (int i=low;i<high;i++){
        if (a[i] <= pivot) {
            swap(a[i], a[counter]);
            counter++;
        }
    }
    swap(a[high], a[counter]);
    return counter;
}
void quicksort(int a[], int low, int high){
    int middle;
    if (low >= high) return ;
    middle = partition(a, low, high);
    for (int i=0;i<size;i++){
        if (i == low) printf("[ ");
        if (i == middle) printf("*");
        printf("%d ", a[i]);
        if (i == high) printf("] ");
    }
    printf("\n");
    quicksort(a, low, middle-1);
    quicksort(a, middle+1, high);
}
