#include "password.hpp"

// Implementation of Password class methods
Password::Password(const std::string &password, bool is_encrypted) {
    if (is_encrypted) {
        _encrypted_value = password;
    } else {
        _raw_value = password;
        encrypt(password);
    }
}

void Password::encrypt(const std::string &password) {
    // Placeholder encryption function
    _encrypted_value = std::string(password.rbegin(), password.rend());
}

std::string Password::str() const {
    return _raw_value;
}

bool Password::operator==(const std::string &str) const {
    return _encrypted_value == std::string(str.rbegin(), str.rend());
}

bool Password::operator==(const Password &other) const {
    return _encrypted_value == other._encrypted_value;
}

std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p._encrypted_value;
    return os;
}
