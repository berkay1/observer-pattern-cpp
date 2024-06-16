#include "observer.hpp"
#include "observable.hpp"
#include <iostream>
void handle(const int& x){
    std::cout << "value = " << x << std::endl;
};

int main(){
    Observable<int> int_data;
    const IObserver<int>& observer = Observer<int>(&int_data, &handle);
    int_data = 10;
    int_data = 12;
}