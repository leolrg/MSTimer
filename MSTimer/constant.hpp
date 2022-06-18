//
//  constant.hpp
//  MSTimer
//
//  Created by liruogu on 2021/1/31.
//  Copyright © 2021 liruogu. All rights reserved.
//

#ifndef constant_hpp
#define constant_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class Constant{
public:
    const uintptr_t base = 0x1001078B8;
    vector<uintptr_t> time_offset = {0x120,0x10,0x0,0x10,0x138};
    const uintptr_t suc_base = 0x100107B78;
    vector<uintptr_t> suc_offset = {0x60};
    const float DNF = 99999.000;
    const uintptr_t lev_base = 0x7FFF8664C310;
    vector<uintptr_t> lev_offset = {0x90,0x50,0x60,0x88,0xB0,0x8,0x24};
};
#endif /* constant_hpp */
