#include <stdio.h>
#include <math.h>

double It (double a,double b,double e);
double bissec (double a,double b);
double func (double var);
double roundN (double val);

int main()
{
    double a0,b0,E,var;
    
    printf("Informe a0 b0 E\n");
    scanf ("%lf %lf %lf",&a0,&b0,&E);
    
    double NIt = ceil(It(a0,b0,E));
    int NItConv = NIt;
    printf ("K = %.1lf\n",NIt);
    
    double x[NItConv];
    double a[NItConv], b[NItConv];
    a[0]=a0, b[0]=b0;
    
   
    
    for(int i=0;i<NIt;i++){
        
        x[i]=bissec(a[i],b[i]);
        
        /*roundN(a[i]);
        roundN(b[i]);
        roundN(x[i]);*/
        
        func(a[i]);
        func(b[i]);
        func(x[i]);
        printf ("a[%d] = %lf b[%d] = %lf x[%d] = %lf\n",i,a[i],i,b[i],i,x[i]);
        printf ("fa[%d] = %lf\n",i,func(a[i]));
        printf ("fb[%d] = %lf\n",i,func(b[i]));
        printf ("fx[%d] = %lf\n",i,func(x[i]));
        
        if((func(a[i])*func(x[i])<0)){
            a[i+1]=a[i];
            b[i+1]=x[i];
            printf("primeiro caso\n");
        }
        else if ((func(x[i])*func(b[i])<0)){
            a[i+1]=x[i];
            b[i+1]=b[i];
            printf("segundo caso\n");
        }
        
        
    }
    
   printf("Raiz aproximada: %lf",x[NItConv-1]);
    
    return 0;
}

double It (double a,double b,double e){
    double k = (log(b-a) - log(e))/log(2);
    return k;
}

double bissec (double a,double b){
    double x = (a+b)/2;
    return x;
}

double func (double var){
    double fx = (5*(cos (var)) - pow(var,4)*exp(var) - 3*(pow(var,2)) + 2);
    return fx;
}

double roundN (double val){
    double nearest = roundf(val * 100) / 100;
    return nearest;
}