#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void saxpyCuda(int N, float alpha, float* x, float* y, float* result);
void printCudaInfo();


void usage(const char* progname) {
    printf("Usage: %s [options]\n", progname);
    printf("Program Options:\n");
    printf("  -n  --arraysize <INT>  Number of elements in arrays\n");
    printf("  -?  --help             This message\n");
}


int main(int argc, char** argv)
{

    // default: arrays of 100M numbers
    int N = 100 * 1000 * 1000;

    // parse commandline options ////////////////////////////////////////////
    for (int i = 1; i < argc; i++) {
        if ((strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--arraysize") == 0) && i + 1 < argc) {
            N = atoi(argv[++i]);
        } else {
            usage(argv[0]);
            return 1;
        }
    }
    // end parsing of commandline options //////////////////////////////////////

    const float alpha = 2.0f;
    float* xarray = new float[N];
    float* yarray = new float[N];
    float* resultarray = new float[N];

    for (int i=0; i<N; i++) {
        xarray[i] = yarray[i] = i % 10;
        resultarray[i] = 0.f;
   }

    printCudaInfo();
    
    printf("Running 3 timing tests:\n");
    for (int i=0; i<3; i++) {
      saxpyCuda(N, alpha, xarray, yarray, resultarray);
    }

    delete [] xarray;
    delete [] yarray;
    delete [] resultarray;

    return 0;
}
