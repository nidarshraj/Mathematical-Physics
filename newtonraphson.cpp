#include <iostream>
#include <cstdio>
using namespace std;
float f(float x){
    return (x*x + 2*x - 3);
}
float F(float x){
    //This is the derivative of the function f
    return (2*x + 2);
}
int main(){
    float x[100],derivate;
    cout << "Give a Rough approximation of x0 : ";
    cin >> x[0];
    if(f(x[0])==0){
        cout << "Root is " << x[0] << "\n";
        exit(0);
    }
    int i=1;
    x[1] = x[0] - ((f(x[0]))/(F(x[0])));
    while(f(x[i])!=0){
        i++;
        x[i] = x[i-1] - ((f(x[i-1]))/(F(x[i-1])));
    }
    cout << "Root is " << x[i] << "\n";
    return 0;
}