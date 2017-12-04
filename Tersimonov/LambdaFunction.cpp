#include <iostream>

int main()//re-defining some basic operations with lambdas
{
    auto add = [](auto x, auto y) {
      return x + y;
    };
    auto sub = [](auto x, auto y) {
      return x - y;
    };
    auto mul = [](auto x, auto y) {
      return x * y;
    };

    auto a = add(5,7);
    auto b = sub(5,7.0);
    auto c = mul(5.5,7);
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;
    std::cout<<"c = "<<c<<std::endl;
} 
