#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int fact(int m){
    int res=1;
    if(m==0 || m==1){
        return 1;
    }
    else{
        for(int i=1;i<=m;i++){
            res = res*i;
        }
        return res;
    }
}
int main(){
    float h,u,realX,yp,looper;
    int i,j,n,realN,u0;
    float x[10],y[10][10];
    cout << "Enter N : ";
    cin >> n;
    cout << "x\n";
    for(i=0;i<n;i++){
        cin >> x[i];
    }
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            y[i][j] = 0;
        }

    }
    cout << "\ny\n";
    for(i=0;i<n;i++){
        cin >> y[i][0];
    }
    
    //Interpolation table creation starts
    for(j=1;j<n;j++){
        for(i=n-1;i>=j;i--){
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }
    cout << "x" << setw(10) << " y" << setw(9);
    for(i=1;i<n;i++){
        cout << "y" << i << setw(9);
    }
    cout << "\n------------------------------------------------------------------\n";
    for(i=0;i<n;i++){
        cout << x[i] << setw(10);
        for(j=0;j<n;j++){
            if(j>i){
                continue;
            }
            cout << y[i][j] << setw(10);
        }
        cout << "\n";
    }
    realN = n-1;
    h = x[realN] - x[realN-1]; //Step size of the function
    cout << "Point of interest : ";
    cin >> realX; 
    u = (realX-x[n-1])/h;
    cout << "h = " << h << "," << " u = " << u << "\n";
    yp = y[n-1][0];
    for(i=1;i<n;i++){
        u0=u; 
        for(j=1;j<i;j++){
            u0 = u0*(u+j);
        }
        yp += (u0*y[n-1][i])/fact(i);
    }
    cout << "\nValue = " << yp <<"\n";
    return 0;
}
