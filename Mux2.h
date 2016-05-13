//
//  Mux2.h
//  ComputerArchitecture
//
//  Created by Baher Mursi on 5/12/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __ComputerArchitecture__Mux2__
#define __ComputerArchitecture__Mux2__

#include <stdio.h>

class Mux2{
    
public:
    Mux2(){
    }
    ~Mux2(){
    }
    
    void setI0(int i){
        I0 = i;
    }
    void setI1(int i){
        I1 = i;
    }
    void setS(int i){
        S = i;
    }
    int getOut() const{
        return (S == 0? I0 : I1);
    }
    
private:
    int I0,I1,S;
};
#endif /* defined(__ComputerArchitecture__Mux2__) */
