#include <iostream>
#include <cstdio>
using namespace std;
float f(float x){
    return (x*x + 2*x - 8);
}
int main(){
    float a,b,c;
    cout << "Give the interval a, b : ";
    cin >> a >> b;
    if(f(a)*f(b) >= 0){
        cout << "Not Valid \n";
        exit(0);
    }
    c = ( a + b )/2.0;
    float root;
    while( f(a) * f(b) < 0.001 ){
        if(f(c) == 0){
            root = c;
            break;
        }
        else if( f(c) * f(a) < 0 ){
            b = c;
        }
        else{
            a = c;
        }
        c = (a+b)/2.0;
    }
    cout << "\nThe Root of the Function = " << root << endl;
    return 0;
}
