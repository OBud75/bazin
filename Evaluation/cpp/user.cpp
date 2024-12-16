#include "user.hpp"
#include "password.hpp"
#include <iostream>

// Constructor
User::User(int id, Password password) 
    : id(id), password(std::make_unique<Password>(std::move(password))), is_logged_in(false) {}

// Login function
int User::login(const char *raw_password) {
    Password temp_password(raw_password);
    if (*password == temp_password) {
        is_logged_in = true;
        return 1; // Success
    }
    return 0; // Failure
}

// Save function
void User::save() {
    // Placeholder save function
    std::cout << "User with ID " << id << " saved." << std::endl;
}

// Get user by ID
User& User::get(int id) {
    static User user(id, Password("default"));
    return user;
}
