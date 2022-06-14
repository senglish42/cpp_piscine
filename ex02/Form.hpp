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
    protected:
        Form();
        Form(const std::string &name, const int &sign, const int &execute);
        Form(const Form &copy);
        Form &operator=(const Form &form);
        ~Form();
    public:
        int         getExecValue() const;
        int         getSignValue() const;
        const std::string   &getName() const;
        void                beSigned(const Bureaucrat &name);
        void                signForm(const Bureaucrat &name) const;
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
        class UnableToBeExecuted : public std::exception
        {
            public:
                explicit UnableToBeExecuted(const char *err);

                virtual const char *what() const throw();

            private:
                const char *_err;
        };
        void checkExecution(const Bureaucrat &executor) const throw
        (UnableToBeExecuted);
        virtual void    execute(Bureaucrat const &executor) const = 0;
        bool            beExecuted(Bureaucrat const &executor) const;
    private:
        const std::string   _name;
        bool                _status;
        const int           _sign;
        const int           _execute;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif