



#include <iostream>
#include <string>
#include "GetInput.hpp"

using namespace std;

void GetInput::getData(){
    getline(cin,in);
}
string GetInput::retrieveData(bool*a,bool*b){
    string tmp=in;
        std::size_t found=tmp.find("test");
         std::size_t foundSy=tmp.find("[");
        if (found!=std::string::npos||foundSy!=std::string::npos)
        { *a= true;}
    std::size_t found1=tmp.find("<");
    std::size_t foundSy1=tmp.find(">");
    if (found1!=std::string::npos||foundSy1!=std::string::npos)
    { *b= true;}
    return in;
    
}
string GetInput::retrieveData(){
    return in;
}

