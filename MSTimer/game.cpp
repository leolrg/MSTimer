//
//  game.cpp
//  MSTimer
//
//  Created by liruogu on 2021/1/31.
//  Copyright © 2021 liruogu. All rights reserved.
//

#include "game.hpp"

float Game::get_time(task_t task){
    auto time_addr = resolve_pointer_chain(task,cons.base,cons.time_offset);
//    cout<<"get_time: "<<hex<<time_addr<<endl;
    return read_data<float>(task,time_addr);
}

bool Game::get_suceeded(task_t task){
    auto suc_addr = resolve_pointer_chain(task, cons.suc_base, cons.suc_offset);
//    cout<<"get_suc: "<<hex<<suc_addr<<endl;
    return read_data<bool>( task, suc_addr);
    
}

//int Game::get_level(task_t task){
//    auto level_addr = resolve_pointer_chain(task, cons.lev_base, cons.lev_offset);
//    int lev = read_data<int>(task, level_addr);
//    if(lev == 1081262080) return 1;
//    else return 2;
//}
