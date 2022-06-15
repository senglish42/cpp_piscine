/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:27:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/15 12:27:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

enum string_code
{
    PRESIDENTAL,
    ROBOTOMY,
    SHRUBBERY,
    OTHERS
};

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &form);
        class UnknownForm : public std::exception
        {
            public:
                explicit UnknownForm(const char *err);
                virtual const char *what() const throw();
            private:
                const char *_err;
        };
        Form *keep_form;
        Form *makeForm(const std::string &form, const std::string &target)
        const throw (UnknownForm);
    private:
        static string_code checkit(const std::string& form);
};

#endif