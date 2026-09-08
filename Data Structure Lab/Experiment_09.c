#include<stdio.h>

void Tower_of_Hanoi(int N, char BEG, char AUX, char END){
    
    if(N==1){
        printf("Disk Moved From %c TO %c \n", BEG, END);
    }
    else{
        Tower_of_Hanoi(N-1, BEG, END, AUX);
        printf("Disk Moved From %c TO %c\n", BEG, END);
        Tower_of_Hanoi(N-1, AUX, BEG, END);
    }

}
int main(){
    int N;
    printf("Enter the number of disks: ");
    scanf("%d", &N);
    Tower_of_Hanoi(N, 'A', 'B', 'C');
    return 0;
}
