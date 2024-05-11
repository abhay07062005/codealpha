#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void createDirectory(const std::string& dirName) {
    if (fs::create_directory(dirName)) {
        std::cout << "Directory created: " << dirName << std::endl;
    } else {
        std::cerr << "Error creating directory: " << dirName << std::endl;
    }
}

void copyFile(const std::string& source, const std::string& destination) {
    try {
        fs::copy(source, destination);
        std::cout << "File copied from " << source << " to " << destination << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error copying file: " << e.what() << std::endl;
    }
}

int main() {
    std::string currentDir = fs::current_path().string();
    std::cout << "Current directory: " << currentDir << std::endl;

    std::string command;
    while (true) {
        std::cout << "\nEnter a command (create/move/copy/exit): ";
        std::cin >> command;

        if (command == "create") {
            std::string dirName;
            std::cout << "Enter directory name: ";
            std::cin >> dirName;
            createDirectory(dirName);
        } else if (command == "copy") {
            std::string source, destination;
            std::cout << "Enter source file path: ";
            std::cin >> source;
            std::cout << "Enter destination file path: ";
            std::cin >> destination;
            copyFile(source, destination);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Invalid command. Try again." << std::endl;
        }
    }

    return 0;
}