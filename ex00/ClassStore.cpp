/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassStore.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:08:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/20 13:08:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassStore.hpp"

Store::Store(std::string &sym) : _str(sym), _detect(false)
{
//    std::cout << "Constructor is called." << std::endl;
}

Store::~Store()
{
//    std::cout << "Destructor is called." << std::endl;
}

Store::Store(const Store &copy) : _str(copy.getStr()), _detect(false)
{
//    std::cout << "Copy constructor is called." << std::endl;
    *this = copy;
}


Store &Store::operator=(const Store &store)
{
    if (this == &store)
        return *this;
    this->_detect = store.getDetect();
    this->_ch = store.getCh();
    this->_int = store.getInt();
    this->_f = store.getF();
    this->_d = store.getD();
    return *this;
}

const std::string &Store::getStr() const
{
    return this->_str;
}

bool Store::getDetect() const
{
    return this->_detect;
}

char Store::getCh() const
{
    return this->_ch;
}

int Store::getInt() const
{
    return this->_int;
}

float Store::getF() const
{
    return this->_f;
}

double Store::getD() const
{
    return this->_d;
}

void Store::convert()
{
    ifChar();
    if (this->_detect)
        printOut();
    else
        printOutImpExc();
}

void Store::ifChar()
{
    if (this->_str.size() == 1 && !std::isdigit(this->_str[0]))
    {
        this->_ch = static_cast<char>(this->_str[0]);
        this->_int = static_cast<int>(this->_ch);
        this->_f = static_cast<float>(this->_ch);
        this->_d = static_cast<double>(this->_ch);
        this->_detect = true;
    }
    else
        ifInt();
}

void Store::ifInt()
{
    const char *str = this->_str.c_str();
    if ((this->_str.size() == 1 && this->_str[0] == '0')
        || ( !strchr(str, '.') && atoi(str)))
    {
        std::stringstream ss(this->_str);
        ss >> this->_int;
        this->_ch = static_cast<char>(this->_int);
        this->_f = static_cast<float>(this->_int);
        this->_d = static_cast<double>(this->_int);
        this->_detect = true;
    }
    else
        ifFloat();
}

bool Store::exclusions()
{
    if (exclusionsF() || exclusionsD())
        return true;
    return false;
}


bool Store::findExc()
{
    if (this->_str == "+nan" || this->_str == "-nan" || this->_str == "inf")
        return false;
    if (!this->_str.find("nan") || !this->_str.find("+inf")
    || !this->_str.find("+inf") || !this->_str.find("+nan")
    || !this->_str.find("-nan") || !this->_str.find("inf"))
        return false;
    return true;
}

bool Store::exclusionsF()
{
    if (this->_str == "nanf" || this->_str == "+inff" || this->_str == "-inff")
        return true;
    return false;
}

bool Store::exclusionsD()
{
    if (this->_str == "nan" || this->_str == "+inf" || this->_str == "-inf")
        return true;
    return false;
}

void Store::ifFloat()
{
    if (!exclusions() && findExc() && atof(this->_str.c_str()))
    {
        std::stringstream ss(this->_str);
        ss >> this->_f;
        this->_ch = static_cast<char>(this->_f);
        this->_int = static_cast<int>(this->_f);
        this->_d = static_cast<double>(this->_f);
        this->_detect = true;
    }
}

void Store::printOut()
{
    std::cout << "char: "; printOutCh();
    std::cout << "int: " << this->_int << std::endl;
    std::cout << "float: " << this->_f; printOutF();
    std::cout << "double: " << this->_d; printOutD();
}

void Store::printOutCh()
{
    if (this->_int >= 0 && this->_int < 128)
    {
        if (!isprint(this->_ch) || this->_ch == ' ')
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << this->_ch << std::endl;
    }
    else
        std::cout << "Impossible" << std::endl;
}

void Store::printOutF()
{
    float f = this->_f - static_cast<int>(this->_f);
    if (f == 0)
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void Store::printOutD()
{
    double d = this->_d - static_cast<int>(this->_d);
    if (d == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

void Store::printOutImpExc()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (exclusionsF())
    {
        const char *from = this->_str.c_str();
        char to[5];
        std::cout << "float: " << this->_str << std::endl;
        std::cout << "double: " << strncpy(to, from, strlen(from) - 1);
        std::cout << std::endl;
    }
    else if (exclusionsD())
    {
        std::cout << "float: " << this->_str + "f" << std::endl;
        std::cout << "double: " << this->_str << std::endl;
    }
    else
    {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
