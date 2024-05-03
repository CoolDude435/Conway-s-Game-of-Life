#include "util.h"

int mapWidth(std::string& mapFile) {
    int width{0};
    std::ifstream mFile{mapFile};
    std::string s{};
    getline(mFile,s);
        width = s.length();
        mFile.close();
    return width;
}

int mapHeight(std::string& mapFile) {
    int height{0};
    std::ifstream mFile{mapFile};
    std::string s{};
    while (getline(mFile,s)) {
            height++;
        }
        mFile.close();
    return height;
}

int indexOf(std::string& s,char c) {
    //returns index of first instance of a char in a string
    for (int i=0;i<s.length();i++) {
        if (s[i]==c) {
            return i;
        }
    }
    return -1;
}

unsigned int randomNum(unsigned int ceiling) {
    //return a random number from 0 to ceiling-1
    std::srand(std::time(nullptr));
    return std::rand()%ceiling;
}

bool fileExist(std::string& fileName) {
    std::ifstream file;
    file.open(fileName);
    if (file) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}

int enterNum() {
    //gets a valid non-negative number from user
    bool loop{true};
    int iters{};
    while (loop) {
        std::cout << "Enter a number of iterations to run.\n";
        if (!(std::cin >> iters)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //clear cin stream if it does not contain a number
            std::cout << "Not a number, try again.\n";
        } else {
            if (iters >=0) {
                loop = false;
            } else {
                std::cout << "Enter a non-negative number, try again.\n";
            }
        }
    }
    return iters;
}