#include "password.hpp"
#include "user.hpp"
#include <iostream>
#include <cassert>

int main() {
    // Create a User with password
    Password password("toto");
    User user(1, password);

    // Test password encryption
    assert(password == "toto");
    std::cout << "Password encryption test passed." << std::endl;

    // Save user
    user.save();

    // Retrieve the User and attempt login
    User &retrieved_user = User::get(1);
    if (retrieved_user.login("toto")) {
        std::cout << "Login successful." << std::endl;
    } else {
        std::cout << "Login failed." << std::endl;
    }

    return 0;
}
