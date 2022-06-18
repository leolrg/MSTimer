//
//  main.cpp
//  MSTimer
//
//  Created by liruogu on 2021/1/31.
//  Copyright © 2021 liruogu. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include "game.hpp"
#include "record.hpp"
#include "store.hpp"



using namespace std;


Record beginner;
Record intermediate;
vector<float> times;
string game_name = "Minesweeper Deluxe";
Constant cons;
string beginner_path = "/opt/MSTimer1.dat";
string intermediate_path = "/opt/MSTimer2.dat";
int level = 1;
task_t get_task(){
    pid_t pid = pid_from_name(game_name);
    task_t task = task_from_pid(pid);
    return task;
}



Game oneGame(){
    task_t task = get_task();
    Game game;
    float pre = game.get_time(task);
    bool start = false; //whether the game started or not

    while(true){

        this_thread::sleep_for(std::chrono::milliseconds(250));
        float now = game.get_time(task);
        if(abs(now-pre)<1e-5&&!(now-0.0<1e-5)){

            if(start){  //before the game has started but now it ended.
                if(game.get_suceeded(task)){
                    game.time = now;
                    game.level = level;
                    return game;
                }
                else{ //DNF
                    game.time = cons.DNF;
                    game.level = level;
                    return game;
                }
                }
            }
        else start = true;
        pre = game.get_time(task);

    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    Timer();
    cout<<"Which level are you playing? 1: beginner.  2:intermediate. "<<endl;
    cin>>level;
    Data beginnerData = Data(beginner_path);
    Data intermediateData = Data(intermediate_path);
    beginner = beginnerData.read();
    intermediate = intermediateData.read();
    while(true)
    {
        Game game = oneGame();
        if(game.level == 1){ //beginner
            beginnerData.write(game.time);
            beginner.times.push_back(game.time);
            cout<<beginner.get_status()<<endl;
        }
        else{
            intermediateData.write(game.time);
            intermediate.times.push_back(game.time);
            cout<<intermediate.get_status()<<endl;
        }
    }
    return 0;
}
