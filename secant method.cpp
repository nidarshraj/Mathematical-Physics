#include <iostream>
#include <cmath>
using namespace std;
float f(float x){
    return (x*x + 2*x - 8);
}
int main(){
    float x0,xm,x1,x2,E=0.0001,c;
    int n=0;
    cout << "Give approxiamtion for x1 and x2 : ";
    cin >> x1 >> x2;
    cout << f(x1) << "\t" << f(x2) <<"\n";
    if( f(x1)*f(x2) < 0){
        do{
            x0 = (x1*f(x2) - x2*f(x1))/(f(x2)-f(x1));
            c = f(x1)*f(x0);
            x1 = x2;
            x2 = x0;
            n++;
            if(c==0){
                break;
            }
            xm = (x1*f(x2) - x2*f(x1))/(f(x2)-f(x1));
        }while(abs(xm-x0)>=E);
        cout << "Root of the given function = " << x0 << endl;
        cout << "Number of iterations = " << n << endl;
    }
    else{
        cout << "Can't find roots within this interval.\n";
    }
    return 0;
}