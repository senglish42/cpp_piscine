/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:26:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/26 09:26:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <stdexcept>
#include "Form.hpp"

class Form;
class Bureaucrat
{
    public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat(const Bureaucrat &copy, const std::string &name);
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);
        Bureaucrat &operator++();
        Bureaucrat &operator--();
        const Bureaucrat operator++(int);
        const Bureaucrat operator--(int);
        ~Bureaucrat();
        const std::string   &getName() const;
        int                 getValue() const;
        void signForm(Form &form);
        class GradeTooHighException : public std::exception
        {
            public:
                explicit GradeTooHighException(const char* err);
                virtual const char* what() const throw();
            private:
                const char* _err;
        };
        class GradeTooLowException : public std::exception
        {
            public:
                explicit GradeTooLowException(const char* err);
                virtual const char* what() const throw();
            private:
                const char* _err;
        };
        void checkException() throw (GradeTooLowException,
                                    GradeTooHighException);
        void executeForm(Form &form) const;
    private:
        const std::string   _name;
        int                 _grade;
        std::string         _err;
        Bureaucrat() : _grade(150) {}
};

static std::string exc;
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif