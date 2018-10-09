#include <iostream>
using namespace std;
float f(float x){
    return (x*x + 2*x - 8);
}
int main(){
    float a,b,c;
    cout << "Give the interval a, b : ";
    cin >> a >> b;
    c = ( a + b )/2;
    float root;
    while( f(a) * f(b) < 0.001 ){
        if(f(c) == 0){
            root = c;
            break;
        }
        else if( f(c) * f(a) < 0 ){
            c = b;
        }
        else{
            c = a;
        }
    }
    cout << "\nThe Root of the Function = " << root << endl;
    return 0;
}