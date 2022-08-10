/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:34:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/29 16:34:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    public:
        explicit Span(unsigned int N);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &span);
        void addNumber(int num);
        void fillArray();
        class SpanError : public std::exception
        {
        public:
            explicit SpanError(const char* err);
            virtual const char* what() const throw();
        private:
            const char* _err;
        };
        int shortestSpan() throw(SpanError);
        int longestSpan() throw (SpanError);
    private:
        unsigned int _amount;
        std::vector<int> _arr;
};

#endif