#include "Scripts.hpp"
#include "../file/text.hpp"
#include "../util/vector.hpp"
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include <iostream>

extern bool coreInfo;

const std::string keyWords[3] = {
	"print",
    "ptr",
    "if"
};

Script::Script(const char* path)
{
	this->code = text::load(path);

    if (coreInfo)
    {
        std::cout << "[" << glfwGetTime() << "] " << "OK: load script"
            ": " << path<< std::endl;
    }
}

void Script::run()
{
    for (unsigned int index = 0; index < this->code.length(); index++)
    {
        if (this->code[index] == ' ') continue;

        std::vector<unsigned short> numberKeyCode;
        std::string keyWorld = "";

        for (unsigned short indexKeyWord = 0; indexKeyWord < keyWords->size(); indexKeyWord += 1)
        {
            if (this->code[index] != keyWords[indexKeyWord][0]) continue;
              numberKeyCode.push_back(indexKeyWord);
        }

        for (unsigned int index1 = 0; index1 < numberKeyCode.size(); index1++)
        {
            std::cout << numberKeyCode[index] << std::endl;
        }

        for (unsigned int index_2 = index; numberKeyCode.size() != 0; index_2++)
        {
            if (index_2 == 0) break;
            //        for (unsigned short indexKeyWorkd = 0; indexKeyWorkd < keyWorlds->size(); indexKeyWorkd += 1)
            //        {
            //            if (this->code[index] != keyWorlds[numberKeyCode[indexKeyWorkd]][index - index_2])
            //            {
            //                std::vector<unsigned short>::const_iterator ITER = numberKeyCode.begin();
            //                numberKeyCode.erase(ITER + indexKeyWorkd);
            //                index = index_2;
            //            }
            //        }
            //    }

            //    std::cout << numberKeyCode[0] << std::endl;
        }
    }
}