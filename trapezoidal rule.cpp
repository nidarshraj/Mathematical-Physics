#include <iostream>
#include <complex>
using namespace std;
float f(float x){
    float a = x*x; //Function here..
    return a;
}
int main(){
    float a,b,h,sum,integ;
    int n,i,j;
    cout << "Enter the First Limit, a = ";
    cin >> a;
    cout << "Enter the Final Limit, b = ";
    cin >> b;
    cout << "Enter number of subintervals, n = ";
    cin >> n;
    double x[n+1],y[n+1];
    h = (b-a)/n;
    for(i=0;i<=n;i++){
        x[i] = a+i*h;
        y[i] = f(x[i]);
    }
    sum = 0;
    for(i=1;i<n;i++){
        sum = sum + h*y[i];
    }
    integ = h/2.0 * (y[0]+y[n]) + sum;
    cout << "Integral = " << integ << "\n";
    return 0;
}
