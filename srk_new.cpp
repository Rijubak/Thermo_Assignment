#include<iostream>
#include<math.h>
#include<cmath>

#define R 8.314

using namespace std;


int main()
{
 float P,V,T,A,B,Z;    //Declare all properties of the system 
 float Pc,Tc;
 float w;
 float M;       //Molar Mass of gas 
 cout<<"Pressure(Pa): ";
 cin>>P;
 cout<<"Temperature(K): ";
 cin>>T;                     //Prompt user for required properties
 cout<<"Tc: ";
 cin>>Tc;
 cout<<"Pc: ";
 cin>>Pc;
 cout<<"Omega(acentric factor): ";
 cin>>w;
 cout<<"Molar Mass(g): ";
 cin>>M;

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
  //cout<<"D: "<<D<<endl;
  float Q = (a*a - 3*b)/9;
  float r = (2*a*a*a - 9*a*b + 27*c)/54;
  
  cout<<endl<<"////////////////////////////"<<endl;
  
  float X = Q*Q*Q - r*r;
  if(X<0)
  {
    cout<<"X<0"<<endl;
    float S = cbrtf(sqrt(-X)+abs(r));
    Z = (-r/abs(r))*(S+(Q/S)) - a/3;
    cout<<"Z(Compressibility Factor): "<<Z<<endl;
    V = (Z*R*T)/P;
   cout<<"Volume: "<<V<<" m^3/mol"<<endl;
   float p = M/(1000*V);
   cout<<"Density: "<<p<<" kg/m^3"<<endl;
  }
else
 {	
  float theta = acos(r/sqrt(Q*Q*Q));
  float Z_one = -2*sqrt(Q)*cos(theta/3) - a/3;
  float Z_two = -2*sqrt(Q)*cos((theta+2*3.14)/3) - a/3;
  float Z_three = -2*sqrt(Q)*cos((theta+4*3.14)/3) - a/3;
  
  cout<<"Z1(Compressibility Factor): "<<Z_one<<endl;
  float V_one = (Z_one*R*T)/P;
  cout<<"Volume: "<<V_one<<" m^3/mol"<<endl;
  float p_one = M/(1000*V_one);
  cout<<"Density1: "<<p_one<<" kg/m^3"<<endl;

  cout<<"Z2(Compressibility Factor): "<<Z_two<<endl;
  float V_two = (Z_two*R*T)/P;
  cout<<"Volume: "<<V_two<<" m^3/mol"<<endl;
  float p_two = M/(1000*V_two);
  cout<<"Density2: "<<p_two<<" kg/m^3"<<endl;

    cout<<"Z3(Compressibility Factor): "<<Z_three<<endl;
  float V_three = (Z_three*R*T)/P;
  cout<<"Volume3: "<<V_three<<" m^3/mol"<<endl;
  float p_three = M/(1000*V_three);
  cout<<"Density3: "<<p_three<<" kg/m^3"<<endl;

  
 } 
 

 return 0; 	
}