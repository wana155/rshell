

#ifndef Redirection_h
#define Redirection_h
#include "Command.hpp"
using namespace std;

class Redirection: public Command{
public: Redirection():Command(){}
    void Rexecute();
private:
    void clean(char *tx,long siz);
};

#endif /* Redirection_h */

