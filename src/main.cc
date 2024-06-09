#include "observer.hpp"
#include "observable.hpp"
#include <iostream>

class CoutObserver: public Observer<int>{
  public:
    CoutObserver(Observable<int>* subject): Observer<int>(subject){

    };
    void Update(const int& x) override {
        std::cout << "value is " << x << std::endl;
    }
};

int main(){
    Observable<int> int_data;
    CoutObserver observer(&int_data);
    int_data = 10;
    int_data = 12;
}