#include <stdio.h>
#include <stdlib.h>


int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int v1[1000], v2[1000];
    int count = 0;

    // Read input from stdin
    while (count < 1000 && scanf("%d %d", &v1[count], &v2[count]) == 2) {
        count++;
    }


    radixsort(v1, 1000);
    radixsort(v2, 1000);

    int absVal = 0;
    int dst = 0;
    for(int i = 0; i < 1000; i++){
        dst += abs(v1[i]-v2[i]);

        int ret = binarySearch(v2, 0, 1000, v1[i]);
        if(ret == -1) continue;
        while(ret>=1 && v2[ret-1] == v1[i]) ret--;
        while(ret < 1000 && v2[ret] == v1[i]){
            ret ++;
            absVal += v1[i];
        }
    }
    printf("Part1: %d\n", dst);
    printf("Part2: %d\n", absVal);

    fflush(stdout);

    return 0;
}
