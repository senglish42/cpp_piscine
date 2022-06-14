/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:19:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/13 22:19:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const
std::string &target) : Form(name, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm() :
Form("form", 145, 137) , _target("target") {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &
rhs) : Form(rhs.getName(), 145, 137), _target(rhs.getTarget())
{
    *this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
    Form::operator=(rhs);
    return *this;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    Form::checkExecution(executor);
    create_shrubbery();
}

void ShrubberyCreationForm::create_shrubbery() const
{
    std::cout << "Creating ASCII tree file....." << std::endl;
    std::string name = _target + "_shrubbery";
    std::fstream f (name.c_str(), std::ios::in | std::ios::out | std::ios::app);
    if (!f)
        throw std::runtime_error("File couldn't be created");
    std::cout << "ASCII tree file '" << name << "' is created." << std::endl;
    f << "         * \n"
         "        /|\\                  \n"
         "       /*|O\\\n"
         "      /*/|\\*\\\n"
         "     /X/O|*\\X\\\n"
         "    /*/X/|\\X\\*\\\n"
         "   /O/*/X|*\\O\\X\\             \n"
         "  /*/O/X/|\\X\\O\\*\\\n"
         " /X/O/*/X|O\\X\\*\\O\\\n"
         "/O/X/*/O/|\\X\\*\\O\\X\\\n"
         "        |X|      \n"
         "        |X|    \n";
    f.close();
}
