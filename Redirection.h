

#ifndef Redirection_h
#define Redirection_h
#include "Command.hpp"
using namespace std;

class Redirection: public Command{
public: Redirection():Command(){}
    void Rexecute();
private:
    void clean(string &ins);
    CommandExecute * Data;
};

#endif /* Redirection_h */

