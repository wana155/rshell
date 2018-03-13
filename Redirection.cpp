


#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include "Redirection.h"
using namespace std;


void Redirection::clean(string &ins){
    
    
    while (ins[0]==32)
    {ins.erase(0,1);}
    while (ins[(ins.size()-1)]==32)
    {ins.erase((ins.size()-1),1);}

    
}
void Redirection::Rexecute(){
    for (int l=0;l<this->commads.size();l++){
        
        string tmo=this->commads[l];
        
        std::size_t found=tmo.find(">");
        std::size_t foundSy=tmo.find("<");
        std::size_t foundSy2=tmo.find(">>");/* need to change since only detects one >*/
        
/*=================To File >==================*/
        if (found!=std::string::npos){
    
            string Comand = tmo.substr(0, found);
            string outFile= tmo.substr(found+1);
            
            this->clean(Comand);
            this->clean(outFile);
            
            char *tm[50];
            char b[]="sh";
            tm[0]=b;
            char c[]="-c";
            tm[1]=c;
            
            char buffer[99];
            size_t length=Comand.copy(buffer, Comand.size(),0);
            buffer[length]='\0';
            tm[2]=buffer;
            tm[3]=NULL;
           
            /* Forks parent and child processes for execution */
            bool tmp=true;
            pid_t  pid;
            int    status;
            if ((pid = fork()) < 0) {     /* Start fork and child  */
                cout<<"* Unable to create fork child process"<<endl;}
            
            else if (pid == 0) {
                /* Redirection of stdout to file*/
                int filD = open(outFile.c_str(), O_RDWR);
                if (filD<0){
                    int filD = open(outFile.c_str(),O_CREAT|O_RDWR|O_TRUNC,0644);
                    dup2(filD, 1);}
                else{dup2(filD, 1);}
                /*execute comand*/
                if (execvp("/bin/sh", tm) < 0) {
                    cout<<"* unable to execute commnad"<<endl;
                    tmp=false;}}
            else {while (wait(&status) != pid);}
                cout<<"Output redirected to file '"<<outFile<<"'"<<endl;
}
/*=================To Screen==================*/
        else   if (foundSy!=std::string::npos){
            
    
        
string Comand = tmo.substr(0, foundSy);
            string outFile= tmo.substr(foundSy+1);
            
            this->clean(Comand);
            this->clean(outFile);
           char buffer[5000]="";
           
           int ToScreen=dup(1);
           int filD = open(outFile.c_str(),O_RDWR,0644);
           
           read(filD, buffer, 5000);
           
           write(ToScreen, buffer, 5000);
        }
        else   if (foundSy2!=std::string::npos){
            
            string Comand = tmo.substr(foundSy2+1);
            string outFile= tmo.substr(0, foundSy2);
            
            this->clean(Comand);
            this->clean(outFile);
            
        }
        else {
              BaseFactory* commandType2=new TestFactory();
            this->clean(tmo);
            this->Data= new Command(commandType2);
            this->Data->parse(tmo);
            this->Data->execute();
       }
        
    
        }}

