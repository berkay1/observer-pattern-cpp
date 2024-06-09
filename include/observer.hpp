#ifndef OBSERVER_H_
#define OBSERVER_H_

template <typename T>
class Observable;

template <typename T>
class Observer {
public:
    using Ptr = Observer*;
    //TODO: fix raw pointer usage
    explicit Observer(Observable<T>* observable){
        observable->Subscribe(this);
    };
    virtual ~Observer() = default;

    virtual void Update(const T& value) = 0;

private:
    Observable<T>* observable_;
};

#endif // OBSERVER_H_
