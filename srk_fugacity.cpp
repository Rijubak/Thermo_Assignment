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
  
  float Z_one;
  float Z_two;
  float Z_three;

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
  Z_one = -2*sqrt(Q)*cos(theta/3) - a/3;
  Z_two = -2*sqrt(Q)*cos((theta+2*3.14)/3) - a/3;
  Z_three = -2*sqrt(Q)*cos((theta+4*3.14)/3) - a/3;
  
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
 
 float Bb = (P*B)/(R*T); 
 
 if(X<0)
 {
  cout<<"**********************************************"<<endl;
  //cout<<"Z_one - Bb: "<<Z_one - Bb<<endl;
 //cout<<"V_one - B: "<<V_one - B<<endl;
  float ln_phi = Z - 1 - log(Z - Bb) - (A/(B*R*T))*log((Z +Bb)/Z);
  cout<<"ln_phi: "<<ln_phi<<endl;
  float fugacity_coeff = exp(ln_phi);
  float fugacity = P*fugacity_coeff;
  cout<<"Fugacity Coefficient: "<<fugacity_coeff<<endl;
  cout<<"Fugacity: "<<fugacity<<endl;
  cout<<"**********************************************"<<endl;
 }


 else
 {
  cout<<"**********************************************"<<endl;
  //cout<<"Z_one - Bb: "<<Z_one - Bb<<endl;
 //cout<<"V_one - B: "<<V_one - B<<endl;
  float ln_phi_one = Z_one - 1 - log(Z_one - Bb) - (A/(B*R*T))*log((Z_one +Bb)/Z_one);
  cout<<"ln_phi_one: "<<ln_phi_one<<endl;
  float fugacity_coeff_one = exp(ln_phi_one);
  float fugacity_one = P*fugacity_coeff_one;
  cout<<"Fugacity Coefficient_one: "<<fugacity_coeff_one<<endl;
  cout<<"Fugacity_one: "<<fugacity_one<<endl;
  cout<<"**********************************************"<<endl;

  cout<<"**********************************************"<<endl;
  float ln_phi_two = Z_two - 1 - log(Z_two - Bb) - (A/(B*R*T))*log((Z_two +Bb)/Z);
  float fugacity_coeff_two = exp(ln_phi_two);
  float fugacity_two = P*fugacity_coeff_two;
  cout<<"Fugacity Coefficient_two: "<<fugacity_coeff_two<<endl;
  cout<<"Fugacity_two: "<<fugacity_two<<endl;
  cout<<"**********************************************"<<endl<<endl;

  cout<<"**********************************************"<<endl;
  float ln_phi_three = Z_three - 1 - log(Z_three - Bb) - (A/(B*R*T))*log((Z_three +Bb)/Z);
  float fugacity_coeff_three = exp(ln_phi_three);
  float fugacity_three = P*fugacity_coeff_three;
  cout<<"Fugacity Coefficient_three: "<<fugacity_coeff_three<<endl;
  cout<<"Fugacity_three: "<<fugacity_three<<endl;
  cout<<"**********************************************"<<endl<<endl;
 }
 return 0; 	
}