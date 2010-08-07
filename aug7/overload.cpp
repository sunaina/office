#include <iostream>
#include<fstream>
#include<istream>
#include<ostream>
#include <string.h>
using namespace std;
class Base
{
      char strVal[100];
      public:
      Base(){ strcpy(strVal,"");}
      Base(char *val){ strcpy(strVal,val);}
      ~Base(){*strVal = '\0';}
      friend istream& operator >>(istream &is,Base &obj);
      friend ostream& operator <<(ostream &os,const Base &obj);
};
istream& operator >>(istream &is,Base &obj)
{
      is>>obj.strVal;
      return is;
}
ostream& operator <<(ostream &os,const Base &obj)
{
      os<<obj.strVal;
      return os;
}
int main()
{
      Base b;
      cin>>b;
      cout<<"Printing the value\n";
      cout<<b<<endl;

      return 0;
}
