/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:58:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/29 18:58:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator
        reverse_iterator;
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack<T>& copy);
        MutantStack<T> &operator=(const MutantStack<T>& mutantStack);
        iterator begin();
        iterator end();
        reverse_iterator rbegin();
        reverse_iterator rend();
};

#endif