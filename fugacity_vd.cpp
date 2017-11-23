#include<iostream>
#include<math.h>
#include<cmath>
#define R 8.314               //Universal Gas Constant

using namespace std;


int main()
{
 float P,V,T,A,B;    //Declare all properties of the system 
 float Pc,Tc;
 float M;       //Molar Mass of gas
 cout<<"Pressure(Pa): ";
 cin>>P;
 cout<<"Temperature(K): ";
 cin>>T;                     //Prompt user for required properties
 cout<<"Tc: ";
 cin>>Tc;
 cout<<"Pc: ";
 cin>>Pc;
 cout<<"Molar Mass(g): ";
 cin>>M;
 
 A = (27*R*R*Tc*Tc)/(64*Pc);
 B = (R*Tc)/(8*Pc);
 //cout<<"b: "<<B;
 float a = -((R*T) + (P*B))/P;
 float b =  A/P;   
 float c = -(A*B)/P ; 

 float D = pow(((2*pow(a,3)) - (9*a*b) + (27*c)),2) + (4*pow((-a*a + 3*b),3));
 
 float Q = (a*a - 3*b)/9;
 float r = (2*a*a*a - 9*a*b + 27*c)/54;
 //cout<<D;
  cout<<endl<<"////////////////////////////"<<endl;

  float X = Q*Q*Q - r*r;
  if(X<0)
  {
  	cout<<"X<0"<<endl;
    float S = cbrtf(sqrt(-X)+abs(r));
    V = (-r/abs(r))*(S+(Q/S)) - a/3;
    cout<<"Volume: "<<V<<" m^3/mol"<<endl;
    float p = M/(1000*V);
    cout<<"Density: "<<p<<" kg/m^3"<<endl;
  }
else
 {	
  float d = (-2*pow(a,3)) + (9*a*b) - (27*c);
  //cout<<d;
  float discrm_one = (d + sqrt(D))/54;
  //cout<<discrm_one;
  float discrm_two = (d - sqrt(D))/54;
  //cout<<"discrm_two: "<<discrm_two<<endl;
  //cout<<-a/3.0<<endl;;
  //cout<<"Pow1: "<<cbrtf(discrm_one)<<endl;
  //cout<<"Pow2: "<<cbrtf(discrm_two)<<endl;
   V = -(a/3.0) + cbrtf(discrm_one) + cbrtf(discrm_two);
   cout<<"Volume: "<<V<<" m^3/mol"<<endl;
   float p = M/(1000*V);
   cout<<"Density: "<<p<<" kg/m^3"<<endl;

 } 

 cout<<"**********************************************"<<endl;
 float Z = (P*V)/(R*T);
 float ln_phi = Z - 1 - log(P*(V-B)/(R*T)) - A/(R*T*V);
 float fugacity_coeff = exp(ln_phi);
 float fugacity = P*fugacity_coeff;
 cout<<"Fugacity Coefficient: "<<fugacity_coeff<<endl;
 cout<<"Fugacity: "<<fugacity<<endl;
 cout<<"**********************************************"<<endl;
 return 0;
}