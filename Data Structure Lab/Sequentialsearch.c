#include<stdio.h>

int main(){
    int arr[10], index[5];
    int n, i, j, key, block, start, end;
    printf("Enter No Of elemnts in array: ");
    scanf("%d", &n);
    printf("Enter Elements in Sorted Order: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    j = 0;
    for(i=0; i<n; i=i+3){
        index[j] = i;
        j++;
    }
    printf("Enter Key to be searched: ");
    scanf("%d", &key);
    block = -1;
    
    for (i=0; i<j; i++){
        if(key >= arr[index[i]]){
            block = i;
        }
        if(block == -1){
            printf("Element Not Found");
            return 0;
        }
    }
    start = index[block];
    if(block+1 <= j){
        end = index[block+1] - 1;
    }
    else{
        end = n-1;
    }
    for(i = start; i<=end; i++){
        if(arr[i] == key){
            printf("Element is at %d", i+1);
            return 0;
        }
    }
    printf("Element Not Found");
    return 0;
}