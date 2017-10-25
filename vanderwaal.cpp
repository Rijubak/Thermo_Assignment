#include<iostream>
using namespace std;

#define R 8.314

int main()
{
 float P,V,T,a,b;            //Declare all properties of the system
 
 cout<<"Pressure(Pa): ";
 cin>>P;
 cout<<"Temperature(K): ";
 cin>>T;                     //Prompt user for required properties
 cout<<"a: ";
 cin>>a;
 cout<<"b: ";
 cin>>b;
 float v;                   //initial value for volume 
 float num,den;
 V = v;
 for(int i=0; i<10; i++)
 {
  num = (P + a/(V*V))*(V-b) - R*T;        //numerator
  den = (P+a/(V*V))-2*a*(V-b)/(V*V*V);    //denominator
  /******Direct Formula*************************************************/
  //V = ((P + a/(V*V))*(V-b) - R*T)/(P+a/(V*V) - 2*a/(V*V*V)*(V-b)) + V; 	
  /*********************************************************************/
  V = num/den + V;
 }
 cout<<"Volume: "<<V<<endl;
 return 0 ;	
}
