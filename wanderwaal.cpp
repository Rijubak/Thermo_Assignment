#include<iostream>
#include<math.h>
#define R 8.314

using namespace std;


int main()
{
 float P,V,T,A,B;    //Declare all properties of the system 
 float Pc,Tc;
cout<<"Pressure(Pa): ";
 cin>>P;
 cout<<"Temperature(K): ";
 cin>>T;                     //Prompt user for required properties
 cout<<"Tc: ";
 cin>>Tc;
 cout<<"Pc: ";
 cin>>Pc;
 
 A = (27*R*R*Tc*Tc)/(64*Pc);
 B = (R*Tc)/(8*Pc);

 float a = -((R*T) + (P*B))/P;
 float b =  A/P;   
 float c = -(A*B)/P ; 

 float D = pow(((2*pow(a,3)) - (9*a*b) + (27*c)),2) + (4*pow((-a*a + 3*b),3));

 float d = (-2*pow(a,3)) + (9*a*b) - (27*c);
 float discrm_one = (d + sqrt(D))/54;
 float discrm_two = (d - sqrt(D))/54;
 V = -(a/3) + pow(discrm_one,0.333) + pow(discrm_two,0.333);
 cout<<"Volume: "<<V<<endl;

}


