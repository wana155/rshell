


#ifndef GetInput_hpp
#define GetInput_hpp

#include <stdio.h>


class GetInput{
  
private:
    std::string in;

public:
   void getData();
    std::string retrieveData(bool*a,bool*b);
     std::string retrieveData();
    
};


#endif /* GetInput_h */

