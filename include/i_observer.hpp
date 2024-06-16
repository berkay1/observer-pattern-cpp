template <typename T>
class IObserver{
    virtual void Update(const T&) = 0;
};