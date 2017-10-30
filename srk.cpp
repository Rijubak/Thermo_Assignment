#include<iostream>
#include<math.h>

#define R 8.314

using namespace std;


int main()
{
 float P,V,T,A,B,Z;    //Declare all properties of the system 
 float Pc,Tc;
 float w;
 cout<<"Pressure(Pa): ";
 cin>>P;
 cout<<"Temperature(K): ";
 cin>>T;                     //Prompt user for required properties
 cout<<"Tc: ";
 cin>>Tc;
 cout<<"Pc: ";
 cin>>Pc;
 cout<<"Omega: ";
 cin>>w;

 float Tr = T/Tc;                  //Reduced Temperature
 float S = 0.48 + 1.574*w - 0.176*w*w;
 float alpha = 1 + S*(1-sqrt(Tr)); 

 A = (0.42748*R*R*Tc*Tc*alpha)/Pc;
 B = (0.08664*R*Tc)/Pc;

 float E = (A*P)/(R*R*T*T);
 float F = (B*P)/(R*T);

 float a = -1;
 float b = E - F - F*F;
 float c = -E*F ;

  float D = pow(((2*pow(a,3)) - (9*a*b) + (27*c)),2) + (4*pow((-a*a + 3*b),3));
 
  if(D<0)
  {
  	cout<<"No real solution"<<endl;
  }
else
 {	
  float d = (-2*pow(a,3)) + (9*a*b) - (27*c);
  float discrm_one = (d + sqrt(D))/54;
  float discrm_two = (d - sqrt(D))/54;
  Z = -(a/3) + cbrtf(discrm_one) + cbrtf(discrm_two);
  cout<<"Z(Compressibility Factor): "<<Z<<endl;
  V = (Z*R*T)/P;
  cout<<"Volume: "<<V<<endl;
 } 
 

 return 0; 	
}