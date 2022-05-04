/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:59:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/02 20:59:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    _message[0] = &Harl::debug;
    _message[1] = &Harl::info;
    _message[2] = &Harl::warning;
    _message[3] = &Harl::error;
};

Harl::~Harl() {};

void Harl::complain(std::string level) {
    std::string message[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int msg = 0; msg < 4; msg++)
    {
        if (level.compare(0, level.size(), message[msg]) == 0)
        {
            (this->*_message[msg])();
            return;
        }
    }
}

void Harl::debug() {
    std::cout   << "I love having extra bacon for my "
                   "7XL-double-cheese-triple-pickle-special-"
                   "ketchup burger. I really do!"
                << std::endl;
};

void Harl::error() {
    std::cout   << "I cannot believe adding extra bacon costs more money. "
                   "You didn’t put enough bacon in my burger! If you did, I "
                   "wouldn’t be asking for more!"
                << std::endl;
};

void Harl::info() {
    std::cout   << "This is unacceptable! I want to speak to the manager now."
                << std::endl;
};

void Harl::warning() {
    std::cout   << "I think I deserve to have some extra bacon for free. "
                   "I’ve been coming for years whereas you started working "
                   "here since last month."
                << std::endl;
};