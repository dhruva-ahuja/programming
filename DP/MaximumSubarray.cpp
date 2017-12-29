/*
    The idea behind this algorithm is to calculate the min_subarray_sum array till now
    and subtract this min_subarray_sum from total sum till now to get max_subarray_sum
    till now. 
*/

#include <iostream>
using namespace std;

int MaximumSubarray(int A[], int N) {
    int min_subarray_sum = 0, max_subarray_sum = 0, sum=0;
    for(int i=0; i < N; ++i) {
        sum += A[i];
        if(min_subarray_sum > sum) {
            min_subarray_sum = sum; // for the first time this will only be updated if sum goes negative 
        }                           // in that case we need to discard this portion of array 
        if(max_subarray_sum < sum - min_subarray_sum) {
            max_subarray_sum = sum - min_subarray_sum; // so here we discard that part
        }
    }
    return max_subarray_sum;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i < N; ++i) {
        cin >> A[i];
    }
    cout << MaximumSubarray(A, N);
}

