/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:33:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/29 16:33:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _amount(N)
{
    std::cout << "Span constructor is called." << std::endl;
    _arr.reserve(_amount);
}

Span::~Span()
{
    std::cout << "Span destructor is called." << std::endl;
}

Span::Span(const Span &copy) : _amount(copy._amount)
{
    *this = copy;
}

Span &Span::operator=(const Span &span)
{
    if (this == &span)
        return *this;
    if (!_arr.empty())
        _arr.clear();
    _arr.reserve(span._amount);
    _arr = span._arr;
    return *this;
}

void Span::addNumber(int num)
{
    if (_arr.size() == _amount)
        throw SpanError("array is already fully filled.");
    _arr.push_back(num);
}

void Span::fillArray()
{
    srand(static_cast<unsigned int>(time(0)));
    for (int count = 0; count < 10000; ++count)
        addNumber(rand());
}

int Span::shortestSpan() throw (SpanError)
{
    if (_arr.size() < 2)
        throw SpanError("array should contain at least two integers.");
    std::vector<int> sort = _arr;
    std::sort(sort.begin(), sort.end());
    std::vector<int> dist;
    int size = static_cast<int>(sort.size()) - 1;
    dist.reserve(size);
    for (int count = 0; count < size; ++count)
        dist.push_back(abs(_arr[count] - _arr[count + 1]));
    return *std::min_element(dist.begin(),dist.end());
}

int Span::longestSpan() throw (SpanError)
{
    if (_arr.size() < 2)
        throw SpanError("array should contain at least two integers.");
    return *std::max_element(_arr.begin(), _arr.end()) - *std::min_element(_arr
    .begin(), _arr.end());
}

Span::SpanError::SpanError(const char *err) : _err(err) {}

const char* Span::SpanError::what() const throw()
{
    return (_err);
}