#ifndef OBSERVABLE_HPP_
#define OBSERVABLE_HPP_

#include "observer.hpp"

#include <unordered_set>

template <class T>
class Observable {
  public:
    Observable() = default;
    //TODO: fix raw pointer usage.
    void Subscribe(Observer<T>* observer) {
        observers_.insert(observer);
    }

    void Unsubscribe(Observer<T>* observer) {
        observers_.erase(observer);
    }

    void operator=(const T& data) {
        for (auto& observer : observers_) {
            observer->Update(data);
        }
    }
    
private:
    std::unordered_set<Observer<T>*> observers_;
};

#endif // OBSERVABLE_HPP_
