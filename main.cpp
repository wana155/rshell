





#include <iostream>
#include "GetInput.hpp"
#include <unistd.h>
#include  <stdio.h>
#include  <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include "Command.hpp"
#include <sys/stat.h>
#include "BaseFactory.h"
#include "CommandExecute.hpp"
#include <fcntl.h>
#include "Redirection.h"
using namespace std;

int main() {
cout<<"Type 'Exit' to End Program"<<endl;
   
   BaseFactory* commandType1=new CoShellFactory();
   BaseFactory* commandType2=new TestFactory();

    GetInput test;

 do{
    cout<<"$ ";
    test.getData();
     
     bool TezT=false;
     bool Redir=false;
     
   if(test.retrieveData(&TezT,&Redir) =="Exit"){
      return 0;
   }
   else if (Redir==true){
       Redirection * instance=new Redirection();
       instance->parse(test.retrieveData());
       instance->Rexecute();
       
       
   }
   else if (TezT==true){
           CommandExecute *instance=new Command(commandType2);
            instance->parse(test.retrieveData());
           instance->execute();
       }
       else{
           CommandExecute *instance=new Command(commandType1);
           instance->parse(test.retrieveData());
           instance->execute();
       }
    
    cout<<endl;
   
  }while(test.retrieveData() != "Exit");

}

