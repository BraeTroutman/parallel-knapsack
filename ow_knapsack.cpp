#include <iostream>
#include <algorithm>
#include <omp>
using namespace std;

// function for linearizing row/col indices
inline int lin(int i, int j, int m, int n) {
    return i*n + j;
}

int main(int argc, char** argv)
{
    // parse command line inputs
    if(argc < 3 or argc > 4) {
        cout << "Usage: EXE nitems capacity nthreads" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    int W = atoi(argv[2]);
    int p = 1;
    if(argc == 4) 
        p = atoi(argv[3]);

    // allocate memory
    int* values = new int[n];
    int* weights = new int[n];
    int* K = new int[(W+1)];

    // randomly populate weights and values 
    // * always do this sequentially for reproducibility
    srand(12345);
    for(int j = 0; j < n; j++) {
        values[j] = rand() % max(n,W) + 1;
        weights[j] = rand() % max(n,W) + 1;
    }

    // print weights and values (for debugging)
    // cout << "  ";
    // for(int j = 0; j < n; j++)
    //     cout << weights[j] << " ";
    // cout << endl << "  ";
    // for(int j = 0; j < n; j++)
    //     cout << values[j] << " ";
    // cout << endl;

    double start = omp_get_wtime();

    // initialize base cases
    for(int j = 0; j < n; j++) 
        K[j] = 0;

    // fill in DP table
    int wj, vj;
    for(int j = 1; j <= n; j++) {
        wj = weights[j];
        vj = values[j];
        for(int i = W; i>=wj; i--) {
	    K[i] = max(K[i], vj + K[i-wj]);
        }
    }

    double elapsed = omp_get_wtime() - start;

    // print DP table (for debugging)
    // for(int i = 0; i <= W; i++) {
    //     for(int j = 0; j <= n; j++) {
    //         cout << K[lin(i,j,n+1)] << " ";
    //     }
    //     cout << endl;
    // }

    // report value of optimal knapsack
    cout << "Opt value: " << K[W] << endl;

    // report timing
    cout << "Time: " << elapsed << "s" << endl;

    // free memory
    delete[] K;
    delete[] weights;
    delete[] values;
}
