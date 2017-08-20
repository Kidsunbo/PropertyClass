//
// Created by Administrator on 2017-8-20.
//

#ifndef PROPERTY_PROPERTYCLASS_H
#define PROPERTY_PROPERTYCLASS_H
#include <functional>

template<typename T>
class Property {
private:
    std::function<T()> _get;
    std::function<void(T)> _set;
public:

    explicit Property(std::function<T()> get,std::function<void(T)> set=[](T){},T _value=0){
        this->_get = get;
        this->_set = set;
        this->_set(_value);

    }

    operator T(){
        return _get();
    }



    Property& operator = (T& t){
        _set(t);
        return *this;
    }

    Property& operator = (T&& t){
       _set(t);
        return *this;
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& os,Property<T> t){
    os<<(T)t;
    return os;
}


#endif //PROPERTY_PROPERTYCLASS_H
