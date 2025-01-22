#include <iostream>
#include <vector>
#include <numeric>
#include <functional> 
#include <cmath> 
using namespace std;
struct GradientDecent{
    double eta;
    function<double(double)> f;

    void setEta(double e){
        eta = e;
    }
    void setF(function<double(double)> function){
        f = function;
    }
    
    double df(double x, function<double(double)> f){
        double lim = 1e-10;
        return (f(x+lim)-f(x-lim))/(2*lim); 
    }
    void gradient_decent(double &x, int iter){
        for(int i = 0; i < iter; i++){
            
            x -= eta*df(x, f);
            cout<<df(x, f)<<endl;
            if(abs(df(x, f))<1e-3){
                break;
            }
        }
    }
};
double f(double x){
        return pow(x, 2.0) + 5.0*sin(x);
    }


int main()
{
    double eta = 0.1;
    GradientDecent gd;
    gd.setF(f);
    gd.setEta(eta);
    double x = -5.0;
    gd.gradient_decent(x, 100);
    cout<<x<<endl;

}