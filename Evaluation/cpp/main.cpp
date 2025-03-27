#include "password.hpp"
#include "user.hpp"
#include <iostream>
#include <cassert>

int main() {
    Password password("toto");
    User user(1, password);
    assert(password == "toto");
    
    std::cout << "test du chiffrement ok" << std::endl;

    user.save();

    User &retrieved_user = User::get(1);
    if (retrieved_user.login("toto")) {
        std::cout << "Login reussi" << std::endl;
    } else {
        std::cout << "Login rate" << std::endl;
    }


    User &bugged = User::get(1000);
    std::cout << "User ID: " << bugged.getId() << std::endl;

    bugged.setId(1001);
    std::cout << "User ID: " << retrieved_user.getId() << std::endl;

    return 0;
}
