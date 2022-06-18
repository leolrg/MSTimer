//
//  record.hpp
//  MSTimer
//
//  Created by System Administrator on 2021/2/1.
//  Copyright © 2021 liruogu. All rights reserved.
//

#ifndef record_hpp
#define record_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include "constant.hpp"

using namespace std;
class Record{
public:
    float avg_of_3();
    float best();
    float best_avg_of_3();
    float avg_of_nonDNFs();
    float succeed_rate();
    string get_status();
    vector<float> times;
};


#endif /* record_hpp */
