/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:55:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/12 19:55:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "ClassContact.hpp"

Contact::Contact() : _name("name"),
                     _surname("surname"), _nickname("nickname"), _phone("phone"),
                     _secret("secret") {}

Contact::Contact(const std::string &name, const std::string &surname,
                 const std::string &nickname, const std::string &phone,
                 const std::string &secret) : _name(name),
                 _surname(surname), _nickname(nickname), _phone(phone),
                 _secret(secret) {}

Contact::~Contact() {}

void Contact::GetInfo() const
{
    std::cout << std::setw(10) << GetName() << "|";
    std::cout << std::setw(10) << GetSurname() << "|";
    std::cout << std::setw(10) << GetNickname() << "|";
    std::cout << std::setw(10) << GetPhone() << "|";
    std::cout << std::setw(10) << GetSecret() << "|";
    std::cout << std::endl;
}

const std::string& Contact::GetName() const
{
    return this->_name;
}

const std::string& Contact::GetSurname() const
{
    return this->_surname;
}

const std::string& Contact::GetNickname() const
{
    return this->_nickname;
}

const std::string& Contact::GetPhone() const
{
    return this->_phone;
}

const std::string& Contact::GetSecret() const
{
    return this->_secret;
}