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
    for (int i=0;i<s.length();i++) {
        if (s[i]==c) {
            return i;
        }
    }
    return -1;
}