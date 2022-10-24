//
// Created by 17336 on 2022/3/7.
//

#include <iostream>

int height(int val){
    int h=1,minVal=2;
    while (val>=minVal){
        ++h;
        minVal<<=1;
    }
    return h;
}

int main(){
    int n;
    std::cin>>n;
    for (int i = 0; i < n; ++i) {
        int fir,sec;
        std::cin>>fir>>sec;
        if(fir==sec) {
            std::cout<<0<<std::endl;
            continue;
        }
        //让fir维持大的值
        if(fir<sec){
            std::swap(fir,sec);
        }
        int h1= height(fir),h2= height(sec);
        int res=0;
        while (h1>h2){
            fir/=2;
            --h1;
            ++res;
        }
        while (fir!=sec){
            fir/=2;
            sec/=2;
            res+=2;
        }
        std::cout<<res<<std::endl;
    }
}