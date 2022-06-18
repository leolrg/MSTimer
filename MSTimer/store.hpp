//
//  store.hpp
//  MSTimer
//
//  Created by System Administrator on 2021/2/2.
//  Copyright © 2021 liruogu. All rights reserved.
//

#ifndef store_hpp
#define store_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include "record.hpp"
using namespace std;
class Data{
private:
    string path;
public:
    void write (float);
    Record read();
    Data(string);
};
#endif /* store_hpp */
