//
//  store.cpp
//  MSTimer
//
//  Created by System Administrator on 2021/2/2.
//  Copyright © 2021 liruogu. All rights reserved.
//

#include "store.hpp"
Data::Data(string path){
    this->path = path;
}
void Data::write(float time){
    ofstream outFile;
    outFile.open(this->path,ios::app);
    outFile<<time<<endl;
    outFile.close();
}

Record Data::read(){
    ifstream inFile;
    inFile.open(this->path,ios::in);
    float time;
    Record temp;
    while(inFile>>time){
        temp.times.push_back(time);
    }
    inFile.close();
    return temp;
}



