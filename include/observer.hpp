#ifndef OBSERVER_HPP_
#define OBSERVER_HPP_

#include <functional>

template <typename T>
class Observable;

template <typename T>
class Observer {
  public:
    using Handle = std::function<void(const T&)>;
    
    explicit Observer(Observable<T>* observable, Handle handle): handle_(handle) {
        observable->Subscribe(this);
    };

    virtual ~Observer(){
        if(!observable_)
            observable_->Unsubscribe(this);
    };

    void Update(const T& value){
        handle_(value);
    };

private:
    Observable<T>* observable_;
    std::function<void(T)> handle_;
};

#endif // OBSERVER_HPP_
