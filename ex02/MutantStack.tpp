/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:45:00 by senglish          #+#    #+#             */
/*   Updated: 2022/07/02 11:45:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    std::cout << "MutantStack constructor is called." << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "MutantStack destructor is called." << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy) : std::stack<T>(copy)
{
    std::cout << "MutantStack copy constructor is called." << std::endl;
    *this = copy;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T>& mutantStack)
{
    if (this == &mutantStack)
        return *this;
    this->c = mutantStack.c;
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return this->c.rend();
}

#endif