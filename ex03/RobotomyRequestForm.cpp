/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:41:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/13 22:41:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form
("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request", 72, 45),
_target("target") {}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) :
Form(rhs.getName(), 72, 45), _target(rhs.getTarget())
{
    *this = rhs;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
    Form::operator=(rhs);
    return *this;
}

const std::string &RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    Form::checkExecution(executor);
    srand(static_cast<unsigned int>(time(0)));
    std::cout << "Drill whiiiiiiiiiiiiiiirrrrrrrrsssssssss....." << std::endl;
    sleep(1);
    if (rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully 50%"
                  << " :of time." << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed." << std::endl;
    }
}