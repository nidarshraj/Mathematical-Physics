#include <iostream>
#include <complex>
#include <iomanip>
using namespace std;
double f(double x){
    double a = 1/(1+(x*x)); //Function here..
    return a;
}
int main(){
    double a,b,h,sum,integ;
    int n,i;
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
        if(i%2 == 0){
            sum = sum + 2*(y[i]);
        }
        else{
            sum = sum + 4*(y[i]);
        }
    }
    integ = h/3.0 * ((y[0]+sum+y[n]));
    cout << "Integral = " << integ << "\n";
    return 0;
}