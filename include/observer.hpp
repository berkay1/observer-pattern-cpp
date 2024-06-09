#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <functional>

template <typename T>
class Observable;

template <typename T>
class Observer {
public:
    using Handle = std::function<void(const T&)>;
    //TODO: fix raw pointer usage
    explicit Observer(Observable<T>* observable, Handle handle): handle_(handle) {
        observable->Subscribe(this);
    };
    virtual ~Observer() = default;

    void Update(const T& value){
        handle_(value);
    };

private:
    Observable<T>* observable_;
    std::function<void(T)> handle_;
};

#endif // OBSERVER_H_
