//
//  record.cpp
//  MSTimer
//
//  Created by System Administrator on 2021/2/1.
//  Copyright © 2021 liruogu. All rights reserved.
//

#include "record.hpp"



float Record::avg_of_3(){
    Constant cons;
    if(this->times.size()<3) return cons.DNF;
    else{
        unsigned long end = this->times.size()-1;
        if(abs(this->times[end]-cons.DNF)<1e-5||abs(this->times[end-1]-cons.DNF)<1e-5 || abs(this->times[end-2]-cons.DNF)<1e-5) return cons.DNF;
            
            
        else return (this->times[end] + this->times[end-1] + this->times[end-2]) / 3;
    }
}
float Record::best(){
    float minn = this->times[0];
    for(int i=1;i<this->times.size();i++){
        minn = min(minn,this->times[i]);
    }
    return minn;
}
float Record::best_avg_of_3(){
    Constant cons;
    float DNF = cons.DNF;
    float minn;
    
    if(this->times.size()<3) return cons.DNF;
    float sum = this->times[0] + this->times[1] + this->times[2];
    if(abs(times[0]-DNF) < 1e-5||abs(times[1]-DNF)<1e-5||abs(times[2]-DNF)<1e-5) minn = DNF;
    else minn = sum/3;
    for(int i=3;i<this->times.size();i++){
        bool noDNF = true;
        sum = 0;
        for(int j=i-3+1;j<=i;j++){
            sum += times[j];
            if(abs(times[j]-DNF)<1e-5) noDNF = false;
        }
        
        if(noDNF)
            minn = min(minn,sum/3);
    }
    
    return minn;
}
float Record::succeed_rate(){
    Constant cons;
    int attempts = (int)this->times.size();
    float DNF = cons.DNF;
    int suc = 0;
    for(int i=0;i<this->times.size();i++){
        if(!(abs(this->times[i]-DNF)<1e-5)) suc++;
    }
    
    return (float) suc/attempts;
}

float Record::avg_of_nonDNFs(){
    Constant cons;
    int size = 0;
    float sum = 0.0;
    for(int i=0;i<times.size();i++)
    {
        if(times[i]!=cons.DNF) {sum+= times[i];size++;}
    }
    return sum/size;
}
string Record::get_status(){
    Constant cons;
    string current_time = abs(times[times.size()-1] - cons.DNF) < 1e-5? "DNF" : to_string(times[times.size()-1]);
    string current_avg = abs(this->avg_of_3() - cons.DNF)<1e-5? "DNF" : to_string(this->avg_of_3());
    string best_time = abs(this->best() - cons.DNF) < 1e-5? "DNF" : to_string(this->best());
    string best_avg = abs(this->best_avg_of_3() - cons.DNF) < 1e-5? "DNF" : to_string(this->best_avg_of_3());
    string avg = abs(this->avg_of_nonDNFs()-cons.DNF) < 1e-5? "DNF" : to_string(this->avg_of_nonDNFs());
    return "Time: " + current_time + "\n" + "Average of 3: " + current_avg + ", " + "Best: " + best_time + ", " + "Best average: " + best_avg + ", " + "Total average: " + avg;
    
}
