# PropertyClass

this is just a test and a try for property in C++.

There are no `get` and `set` functions with the fields in C++. So this project is a try to wrapper the member variable to provide the similar function.



## Usage

```c++
template<typename T>
class{
    T _t;
  public:
  //read-write variable
  Property<T> t{
  //get
    [this](){
        return _t;
    },
  //set
    [this](auto v){
        if(fun(c)){
            std::cout<<"c has some ...(whatever you wanna say)"<<std::endl;
        	return;
        }
      	_t = v;
      
    },
  //initial value
    T()
  };
  
  //read-only variable
  Property<T> read_only_t{
    [this](){
        return _t;
    }  
  };
  
}
```

Oh, it's a little ugly but it's more concise than Macro(maybe). The constructor of Property has the following signature.

`Property(get,set,init_val)`



# Set && Get

`set` should be a lambda with the signature like `[this](auto val){/*something*/}`, and you can do something to restrict the value of `val`

`get` should be a lambda with the signature like `[this](){return someval}`, and you can do something you like.



# Defect

Initially, I want to use exception, but it doesn't work. I will look for a solution.