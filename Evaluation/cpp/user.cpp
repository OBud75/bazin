#include "user.hpp"
#include "password.hpp"
#include <iostream>

User::User(int id, Password password) 
    : id(id), password(std::make_unique<Password>(std::move(password))), is_logged_in(false) {}

int User::login(const char *raw_password) {
    Password temp_password(raw_password);
    if (*password == temp_password) {
        is_logged_in = true;
        return 1;
    }
    return 0;
}

void User::save() {
    std::cout << "User avec ID " << id << " sauvegardé." << std::endl;
}

User& User::get(int id) {
    static User user(id, Password("default"));
    return user;
}
