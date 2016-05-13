//
//  Mux3.h
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/12/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __ComputerArchitecture__Mux3__
#define __ComputerArchitecture__Mux3__

#include <stdio.h>
class Mux3{
    
public:
    Mux3(){
    }
    ~Mux3(){
    }
    
    void setI0(int i){
        I0 = i;
    }
    void setI1(int i){
        I1 = i;
    }
    void setI2(int i){
        I2 = i;
    }
    void setS(int i){
        S = i;
    }
    
    int getOut() const{
        return (S == 0? I0 : S == 1? I1 : I2);
    }
    
private:
    int I0,I1,I2,S;
};

#endif /* defined(__ComputerArchitecture__Mux3__) */
