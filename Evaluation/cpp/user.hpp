#ifndef USER_HPP
#define USER_HPP

#include "password.hpp"
#include <memory>

class User {
    private:
        int id;
        std::unique_ptr<Password> password;
        bool is_logged_in;

    public:
        explicit User(int id, Password password);
        void save();
        int login(const char *raw_password);
        static User &get(int id);
        int getId() const { return id; }
        void setId(int new_id) { id = new_id; }
};

#endif
