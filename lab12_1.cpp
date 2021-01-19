#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0]; // ค่าเฉลี่ยเลขคณิต
    cout << "\nStandard Deviation = " << B[1]; // ส่วนเบี่ยงเบนมาตรฐาน
    cout << "\nGeometric Mean = " << B[2]; // ค่าเฉลี่ยเลขาคณิต
    cout << "\nHarmonic Mean = " << B[3]; // ค่าเฉลี่ยฮาร์โมนิก
    cout << "\nMax = " << B[4]; // ค่าสูงสุด
    cout << "\nMin = " << B[5]; // ค่าต่ำสุด
    return 0;
}

void stat(const double a[],int n,double b[]){
    double sum = 0,sum2 = 0,koon = 1,sumhar = 0,standard,gemetric,harmonic,max = -999,min = 999;
    for(int i = 0 ; i < n ; i++){
        sum += a[i];
    }
    b[0] = sum/n;
    for(int i = 0 ; i < n ; i++){
        sum2 += pow(a[i] - (sum/(double)n),2);
    }
    b[1] = sqrt(sum2/(double)n);
    for(int i = 0 ; i < n ; i++){
        koon *= a[i];
    }
    b[2] = pow(koon,1/(double)n);
    for(int i = 0 ; i < n ; i++){
        sumhar += 1/a[i];
    }
    b[3] = (double)n/sumhar;
    for(int i = 0 ; i < n ; i++){
        if(a[i] > max) max = a[i];
        if(a[i] < min) min = a[i];
    }
    b[4] = max;
    b[5] = min;
}
