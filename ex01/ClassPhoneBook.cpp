/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.cpp                                          :+:      :+:    :+:   */
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

PhoneBook::PhoneBook() {
    return ;
}

PhoneBook::~PhoneBook() {
    return ;
}

void PhoneBook::to_send(Contact contact, int num) {
    contact_[(num - 1) % 8] = contact;
}

void PhoneBook::to_search(int num) {
    if (num >= 8)
        num = 8;
    for (int count = 0; count < num; count++) {
        std::cout << std::setw(10) << count << "|";
        contact_[count].GetInfo();
    }
}