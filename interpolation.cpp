#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
int fact(int m){
    int res=1;
    if(m==0 || m==1){
        res = 1;
    }
    else{
        for(int i=1;i<=m;i++){
            res = res*i;
        }
    }
    return res;
}
int main(){
    int n;
    float x[100],y[100][100],realX,u,h,numU,looper,value;
    cout << "Enter N : ";
    cin >> n;
    cout << "Enter x : ";
    /*
    Here we are getting the values of x,
     where the values of function are known
    */
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    /*
    Here we are getting the values of 
    function at each x's
    */
    cout << "Enter y : ";
    for(int i=0;i<n;i++){
        cin >> y[i][0];
    }
    /*
    Making the interpolation table 
    in lines 26 to 30
    */
    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            y[i][j] = y[i+1][j-1]-y[i][j-1];
        }
    }
    /*
    Printing out the interpolation table
    */
    cout << "\nTable\n**********\n";
    cout << "x" << setw(10) << "y" << setw(10);
    for(int i=1;i<=n-1;i++){
        cout << "y"<<i << setw(10);
    }
    cout << "\n\n";
    for(int i=0;i<n;i++){
        cout << x[i] << setw(10);
        for(int j=0;j<n;j++){
            if(y[i][j]==0){
                continue;
            }
            cout << setprecision(3) << y[i][j] << setw(10);
        }
        cout << "\n";
    }
    /*Finding out u*/
    h = abs(x[1]-x[0]);
    cout << "\nh = " << h << "\n";
    cout << "Enter an x : ";
    cin >> realX;
    numU = realX - x[0];
    u = numU / h;
    cout << "u = " << u << "\n";
    /*Code Block to find out the value of 
    function at a given point x */
    value = y[0][0];
    looper = u;
    for(int i=1;i<n;i++){
        value += looper*(y[0][i]);
        looper = looper * ((looper-i)/fact(i+1));
    }
    cout << "\nValue of function at " << realX << " = " << value << "\n";
    return 0;
}