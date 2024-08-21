#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class SaveDate {
private:
    std::string lastName;
    std::string firstName;
    std::string middleName;

public:
    // Конструктор класса
    SaveDate(const std::string& lastName, const std::string& firstName, const std::string& middleName)
        : lastName(lastName), firstName(firstName), middleName(middleName) {}

    // Метод для сохранения данных в бинарный файл
    void saveToBinary(const std::string& filePath) const {
        std::ofstream file(filePath, std::ios::binary);
        if (file.is_open()) {
            size_t length = lastName.size();
            file.write(reinterpret_cast<const char*>(&length), sizeof(length));
            file.write(lastName.c_str(), length);

            length = firstName.size();
            file.write(reinterpret_cast<const char*>(&length), sizeof(length));
            file.write(firstName.c_str(), length);

            length = middleName.size();
            file.write(reinterpret_cast<const char*>(&length), sizeof(length));
            file.write(middleName.c_str(), length);

            file.close();
        }
        else {
            std::cerr << "Unable to open file: " << filePath << std::endl;
        }
    }

    // Геттеры для получения данных пользователя
    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getMiddleName() const { return middleName; }
};
