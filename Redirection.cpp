

#include <stdio.h>
#include <iostream>
#include "Redirection.h"
using namespace std;

void Redirection::clean(char *tx,long siz){}

void Redirection::Rexecute(){
    cout <<"dentro xe Rexe"<<endl;
    
    for (int l=0;l<this->commads.size();l++){
        
        string tmo=this->commads[l];
        
        char outFile[50]="";
         char Comand[50]="";
        
        std::size_t found=tmo.find(">");
        std::size_t foundSy=tmo.find("<");
        std::size_t foundSy2=tmo.find(">>");
        
        if (found!=std::string::npos||foundSy!=std::string::npos){
            
            cout<<tmo<<endl;
            if (found!=std::string::npos){
                tmo.copy(Comand,(found),0);
                tmo.copy(outFile,(tmo.size()-(found+1)),found+1);
              
                cout<<Comand<<endl;
                cout<<outFile<<endl;
                this->clean(outFile,(tmo.size()-(found+1)));
                this->clean(Comand, found);
                cout<<"here it is ;"<<outFile<<endl;
                cout<<"here it is ;"<<Comand<<endl;
             }
            if (tmo[found]==32)
            {tmo.erase(found,1);}
            if (tmo[found-1]==32)
            cout<<tmo<<endl;
if (tmo[tmo.size()-1]==32){
                     tmo.erase(tmo.size()-1,1);
                }
            if (foundSy!=std::string::npos){
                tmo.erase((foundSy2-1),2);
                tmo.erase(0,(foundSy+2));
                
            }}
    
    }}
