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
    // static fait en sorte que l'utilisateur soit créé (et donc initialisé)
    // une seule fois, il est ensuite partagé entre les appels. (cf main)
    // Pour éviter cela, il faudrait créer un utilisateur à chaque appel,
    // donc enlever le static et, soit retourner une copie : User,
    // soit retourner un pointeur/référence : User* / User& en ayant
    // alloué l'utilisateur sur le tas avec new (l'équivalent de malloc en C).
    // Mais cela impliquerait de gérer la mémoire (libérer l'utilisateur
    // avec delete), pour éviter cela, C++ propose des smart pointers,
    // on retournera un std::unique_ptr<User> ou std::shared_ptr<User>.
    return user;
}
