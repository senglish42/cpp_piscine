/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:36:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/01 17:36:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

void show_content(const std::string& filename, int num)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        std::cerr   << "Error: can not open file called " << filename << "."
                    << std::cout;
    std::cout << "..............................................." << std::endl;
    if (!num)
        std::cout << "ORIGINAL FILE CONTENT:" << std::endl;
    else
        std::cout << "REPLACED FILE CONTENT:" << std::endl;
    std::string content;
    while(std::getline(file, content))
    {
        std::cout << content << std::endl;
    }
    file.close();
}

void check_output(const std::string& to, const std::ofstream& output)
{
    std::cout << "Checking output file:" << std::endl;
    if (output.is_open())
        std::cout << "Filename called " << to << " is present." <<
                  std::endl;
    else
    {
        std::cerr   << "Error: filename called " << to << " is not "
                                                                "present."
                    <<  std::endl;
        exit (3);
    }
    std::cout   << "Checking of output file is successfully done." << std::endl;
}

void check_input(const std::string& from, const std::ifstream& input)
{
    std::cout << "Checking input file:" << std::endl;
    if (input.is_open())
        std::cout << "Filename called " << from << " is present." <<
        std::endl;
    else
    {
        std::cerr   << "Error: filename called " << from << " is not "
                                                               "present."
                    <<  std::endl;
        exit (3);
    }
    std::cout   << "Checking of input file is successfully done." << std::endl;
}

void check_content(const std::string& from, const std::string& s1,
                   const std::string& s2)
{
    std::cout << "Checking content of arguments:" << std::endl;
    if (from.empty() || s1.empty() || s2.empty())
    {
        std::cerr   << "Error: neither filename nor strings shouldn't be empty."
                    << std::endl;
        exit (2);
    }
    std::cout   << "Checking of arguments content is successfully done."
                << std::endl;
}

void check_amount(int argc)
{
    std::cout << "Checking amount of arguments:" << std::endl;
    if (argc != 4)
    {
        std::cerr   << "Error: program should only contain a filename and two "
                       "strings." << std::endl;
        exit (1);
    }
    std::cout   << "Checking of arguments amount is successfully done."
                << std::endl;
}

int main(int argc, char **argv)
{
    check_amount(argc);
    const std::string from = argv[1];
    const std::string to = from + ".replace";
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];
    check_content(from, s1, s2);
    std::ifstream   input(from.c_str());
    check_input(from, input);
    std::ofstream   output(to.c_str());
    check_output(to, output);
    std::string str;
    show_content(from, 0);
    while (input >> str)
    {
        if (str.compare(0, s1.size(), s1) != 0)
            output << str << " ";
        else
        {
            output << s2;
            if (str.size() != s1.size())
            {
                str.erase(0, s1.size());
                output << str;
            }
            output << " ";
        }
    }
    output << std::endl;
    input.close();
    output.close();
    show_content(to, 1);
    return (0);
}