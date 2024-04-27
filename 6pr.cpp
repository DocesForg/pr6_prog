#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

bool compareByNameFirstLetter(const Contact& a, const Contact& b) {
    return a.name.front() < b.name.front();
}

bool compareByEmailFirstLetter(const Contact& a, const Contact& b) {
    return a.email.front() < b.email.front();
}

bool compareByFirstFourDigits(const Contact& a, const Contact& b) {
    // Получаем первые четыре цифры номера телефона
    std::string firstFourDigitsA = a.phone.substr(0, 4);
    std::string firstFourDigitsB = b.phone.substr(0, 4);

    // Сравниваем первые четыре цифры
    return firstFourDigitsA < firstFourDigitsB;
}

void addContact(std::multimap<std::string, Contact>& contacts) {
    Contact newContact;
    std::cout << "Введи имя: ";
    std::cin >> newContact.name;
    std::cout << "Введи телефон: ";
    std::cin >> newContact.phone;
    std::cout << "Введи email: ";
    std::cin >> newContact.email;
    contacts.insert(std::make_pair(newContact.name, newContact));
}

void deleteContact(std::multimap<std::string, Contact>& contacts) {
    std::string name;
    std::cout << "Введи имя кого удалить: ";
    std::cin >> name;
    contacts.erase(name);
}

void printContacts(const std::multimap<std::string, Contact>& contacts) {
    for (const auto& entry : contacts) {
        std::cout << "Имя: " << entry.second.name << ", Телефон: " << entry.second.phone << ", Email: " << entry.second.email << std::endl;
    }
}

void printContactsSortedByNameFirstLetter(const std::multimap<std::string, Contact>& contacts) {
    std::vector<Contact> sortedContacts;
    for (const auto& entry : contacts) {
        sortedContacts.push_back(entry.second);
    }
    std::sort(sortedContacts.begin(), sortedContacts.end(), compareByNameFirstLetter);

    std::cout << "\nОтсортировано по первой букве имени:\n";
    for (const auto& contact : sortedContacts) {
        std::cout << "Имя: " << contact.name << ", Телефон: " << contact.phone << ", Email: " << contact.email << std::endl;
    }
}

void printContactsSortedByEmailFirstLetter(const std::multimap<std::string, Contact>& contacts) {
    std::vector<Contact> sortedContacts;
    for (const auto& entry : contacts) {
        sortedContacts.push_back(entry.second);
    }
    std::sort(sortedContacts.begin(), sortedContacts.end(), compareByEmailFirstLetter);

    std::cout << "\nОтсортировано по первой букве емейл:\n";
    for (const auto& contact : sortedContacts) {
        std::cout << "Имя: " << contact.name << ", Телефон: " << contact.phone << ", Email: " << contact.email << std::endl;
    }
}

void printContactsSortedByFirstFourDigits(const std::multimap<std::string, Contact>& contacts) {
    std::vector<Contact> sortedContacts;
    for (const auto& entry : contacts) {
        sortedContacts.push_back(entry.second);
    }
    std::sort(sortedContacts.begin(), sortedContacts.end(), compareByFirstFourDigits);

    std::cout << "\nОтсортировано по 4 первым цифрам номера:\n";
    for (const auto& contact : sortedContacts) {
        std::cout << "Имя: " << contact.name << ", Телефон: " << contact.phone << ", Email: " << contact.email << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::multimap<std::string, Contact> contacts;

    int choice;
    do {
        std::cout << "\nМеню:\n1. Добавить контакт\n2. Удалить контакт\n3. Показать контакты\n4. Сортировать по первой букве имени\n5. Сортировать по первой букве Email\n6. Сортировать по первым 4 числам телефона\n7. Выход\n";
        std::cout << "Выбери пункт меню: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            deleteContact(contacts);
            break;
        case 3:
            printContacts(contacts);
            break;
        case 4:
            printContactsSortedByNameFirstLetter(contacts);
            break;
        case 5:
            printContactsSortedByEmailFirstLetter(contacts);
            break;
        case 6:
            printContactsSortedByFirstFourDigits(contacts);
            break;
        case 7:
            std::cout << "Выходим...\n";
            break;
        default:
            std::cout << "Такого пункта нет!.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}