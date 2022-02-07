#include <iostream>
#include <fstream>
#include <string>

bool nameCorrect(std::string str)
{
    bool nCorrect = true;
    if (str[0] < 'A' || str[0] > 'Z')
    {
        nCorrect = false;
        std::cout << "ERROR,write the name with a capital letter " << std::endl;
        return nCorrect;
    }
    else
    {
        for(int i = 1; i < str.length(); ++i)
        {
            if (str[i] < 'a' || str[i] > 'z')
            {
                nCorrect = false;
                std::cout << "ERROR" << std::endl;
                return nCorrect;
            }
        }
    }
    return nCorrect;
}

bool numberCorrect(std::string str)
{
    bool nCorrect = true;
    for(int i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            nCorrect = false;
            std::cout << "ERROR" << std::endl;
            return nCorrect;
        }
    }
    return nCorrect;
}

bool dateCorrect(std::string str)
{
    bool dCorrect = true;
    if (str.length() != 10 || str[2] != '.' || str[5] != '.')
    {
        dCorrect = false;
        std::cout << "ERROR" << std::endl;
        return dCorrect;
    }
    else
    {
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] < '0' && str[i] != '.' || str[i] > '9')
            {
                dCorrect = false;
                std::cout << "ERROR" << std::endl;
                return dCorrect;
            }
        }
    }
    int d = std::stoi(str.substr(0,2));
    int m = std::stoi(str.substr(3,2));
    int y = std::stoi(str.substr(6,4));
    if (d < 1 || d > 31 || m > 12 || m < 1 || y > 2022 || y < 2000)
    {
        dCorrect = false;
        return dCorrect;
    }
    else if (((y % 4 == 0) || (y % 100 != 0 && y % 400 == 0)) && m == 2 && (d < 1 || d > 29))
    {
        dCorrect = false;
        return dCorrect;
    }
    else if (m == 2 && d > 28)
    {
        dCorrect = false;
        return dCorrect;
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
    {
        dCorrect = false;
        return dCorrect;
    }
    return  dCorrect;
}

int main() {

    std::string str;
    std::string strLine;
    bool yes = true;
    int count = 0;

    std::ofstream file("myFile.txt",std::ios::app);

    if (!file.is_open())
    {
        std::cout << "Error!" << std::endl;
    }
    else
    {
        while (yes)
        {
            strLine = "";
            std::cout << "Enter 1 to continue the program: " << std::endl;
            std::cout << "To end the recording, enter 0:" << std::endl;
            std::cin >> yes;
            if (!yes)
            {
                break;
            }
            else
            {
                do
                {
                    std::cout << "Name?" << std::endl;
                    std::cin >> str;
                }
                while (!nameCorrect(str));
                strLine += " " + str;
                do
                {
                    std::cout << "Surname?" << std::endl;
                    std::cin >> str;
                }
                while (!nameCorrect(str));
                strLine += " " + str;
                do
                {
                    std::cout << "Date?" << std::endl;
                    std::cin >> str;
                }
                while (!dateCorrect(str));
                strLine += " " + str;
                do
                {
                    std::cout << "Payment?" << std::endl;
                    std::cin >> str;
                }
                while (!numberCorrect(str));
                strLine += " " + str + " RUB";
                count ++;
                if (count == 1)
                {
                    file << count << "." <<strLine;
                }
                else
                {
                    file << std::endl << count << "." << strLine;
                }
            }
        }
        file.close();
    }
    return 0;
}
