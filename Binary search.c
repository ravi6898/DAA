#include <stdio.h>

int iterativeSearch(int arr[], int n, int target) {
    int low=0;
    int high=n-1;

    while(low<=high) {
        int mid=low+high/2;

        if(arr[mid]==target)
            return mid;
        else if (arr[mid]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int recursiveSearch(int arr[],int low,int high,int target) {
    if (low > high)
        return -1;

    int mid=low+high/2;

    if (arr[mid]==target)
        return mid;
    else if (arr[mid]<target)
        return recursiveSearch(arr,mid+1,high,target);
    else
        return recursiveSearch(arr,low,mid-1,target);
}

int main() {
   
    int n, target, choice, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

 int arr[n];

    printf("Enter elements in sorted order:\n");
    for (int i = 0;i<n;i++) {
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d",&target);

    printf("1. Iterative Binary Search\n");
    printf("2. Recursive Binary Search\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result=iterativeSearch(arr,n,target);
            break;

        case 2:
            result=recursiveSearch(arr,0,n-1,target);
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    if (result==-1)
        printf("Element not found.\n");
    else
        printf("Element found at position %d index.\n",result);
    return 0;
}