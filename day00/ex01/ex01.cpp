/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:29:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/12 19:29:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "ClassPhoneBook.hpp"
#include "ClassContact.hpp"

void    questions_answers(int count, std::string &gnl)
{
    std::cout << std::setw(16) << std::setfill('.');
    if (count == 0)
        std::cout << "FIRST NAME: ";
    else if (count == 1)
        std::cout << "LAST NAME: ";
    else if (count == 2)
        std::cout << "NICKNAME: ";
    else if (count == 3)
        std::cout << "PHONE NUMBER: ";
    else if (count == 4)
        std::cout << "DARKEST SECRET: ";
    getline(std::cin, gnl);
}

void    to_add(std::string &gnl, int &num, PhoneBook &phonebook)
{
    std::string info[5];
    std::string &name = info[0];
    std::string &surname = info[1];
    std::string &nickname = info[2];
    std::string &phone = info[3];
    std::string &secret = info[4];

    for (int count = 0; count < 5; count++)
    {
        questions_answers(count, gnl);
        if (gnl.size() > 10)
            gnl.resize(10);
        if (gnl != "ADD" && gnl != "SEARCH" && gnl != "EXIT") {
            info[count] = gnl;
        }
        else
        {
            while (count != 0)
                info[count--] = "";
            break ;
        }
        if (count == 4)
        {
            num++;
            phonebook.to_send(Contact(name, surname, nickname, phone,
                                      secret), num);
            break ;
        }
    }
}

int main()
{
    PhoneBook   phonebook;
    std::string gnl;
    int         num;

    num = 0;
    while (1)
    {
        getline(std::cin, gnl);
        while (gnl == "ADD")
            to_add(gnl, num, phonebook);
        if (gnl == "SEARCH")
            phonebook.to_search(num);
        if (gnl == "EXIT")
            break ;
    }
    return 0;
}

