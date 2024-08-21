#include "SaveData.h"
using namespace std;

std::string generateFilePath(const std::string& folderPath, const SaveDate& user, const std::vector<std::string>& existingFiles) {
    std::string baseName = folderPath + "/" + user.getLastName() + " " + user.getFirstName() + " " + user.getMiddleName();
    std::string fileName = baseName + ".bin";
    int counter = 1;

    // Проверяем, существует ли файл с таким именем, и если да, добавляем номер
    while (std::find(existingFiles.begin(), existingFiles.end(), fileName) != existingFiles.end()) {
        fileName = baseName + std::to_string(counter) + ".bin";
        counter++;
    }

    return fileName;
}