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

Contact::Contact() {
    return ;
}

Contact::~Contact() {
    return ;
}

void Contact::SetInfo(std::string name[5]) {
    for(int count = 0; count < 5; count++)
        _info[count] = name[count];
}

void Contact::GetInfo(void) {
    for(int count = 0; count < 3; count++)
    {
        std::cout << std::setw(10);
        std::cout << Contact::_info[count] << "|";
    }
    std::cout << std::endl;
}