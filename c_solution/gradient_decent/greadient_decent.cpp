#include <iostream>
#include <vector>
#include <numeric>
#include <functional> 
#include <cmath> 
using namespace std;
struct GradientDecent{
    double eta;
    double gamma;
    function<double(double)> f;

    void setEta(double e){
        eta = e;
    }
    void setGamma(double g){
        gamma = g;
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

    double nag_gradient_decent(double &x, int iter){
        double theta = f(x);
        for(int i = 0; i < iter; i++){
            
            x = gamma*x + eta*df(theta-gamma*x, f);
            // cout<<x<<endl;
            theta = theta - x;
            cout<<i<<endl;
            if(abs(df(theta-gamma*x, f))<1e-3){
                break;
            }
        }
        return theta;
    }
};
double f(double x){
        return pow(x, 2.0) + 10.0*sin(x);
    }


int main()
{
    double eta = 0.1;
    double gamma = 0.9;

    GradientDecent gd;
    gd.setF(f);
    gd.setEta(eta);
    gd.setGamma(gamma);
    double x = 0.0;
    double min = gd.nag_gradient_decent(x, 1000);
    cout<<min<<endl;

}