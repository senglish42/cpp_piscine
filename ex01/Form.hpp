/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:43:00 by senglish          #+#    #+#             */
/*   Updated: 2022/05/28 15:43:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    public:
        Form(const std::string &name, const int &sign, const int &execute);
        Form(const Form &copy);
        Form &operator=(const Form &form);
        ~Form();
        const std::string   &getName() const;
        bool                getStatus() const;
        int                 getExecValue() const;
        int                 getSignValue() const;
        void                beSigned(Bureaucrat& bureaucrat);
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
    private:
        const std::string   _name;
        bool                _status;
        const int           _sign;
        const int           _execute;
        Form();
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif