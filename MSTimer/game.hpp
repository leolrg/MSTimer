//
//  game.hpp
//  MSTimer
//
//  Created by liruogu on 2021/1/31.
//  Copyright © 2021 liruogu. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "mem.hpp"
#include "constant.hpp"
using namespace std;




class Game{
private:
    Constant cons;
    
public:
    float get_time(task_t);
    bool get_suceeded(task_t);
    int get_level(task_t);
    float time;
    int level;
};
#endif /* game_hpp */
