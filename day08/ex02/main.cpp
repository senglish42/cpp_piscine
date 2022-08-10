/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:57:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/29 18:57:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>
#include <iterator>

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        std::cout << "MutantStack class content checking:" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "Compatibility of MutantStack and stack container "
                     "checking:" << std::endl;
        std::stack<int> s(mstack);
        std::cout << s.top() << std::endl;
        s.pop();
        std::cout << s.size() << std::endl;
        MutantStack<int> st = mstack;
        std::cout << "Copy MutantStack class content checking:" << std::endl;
        MutantStack<int>::iterator itc = st.begin();
        MutantStack<int>::iterator itec = st.end();
        ++itc;
        --itc;
        while (itc != itec)
        {

            std::cout << *itc << std::endl;
            ++itc;
        }
    }
    std::cout << "............................" << std::endl;
    {
        std::list<int> list;
        list.push_back(5);
        list.push_back(17);
        std::cout << *--list.end() << std::endl;
        std::list<int>::iterator iter = list.end();
        list.erase(--iter);
        std::cout << list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        std::cout << "Int list content checking:" << std::endl;
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << "............................" << std::endl;
    {
        MutantStack<std::string> str;
        str.push("one");
        str.push("two");
        str.push("three");
        std::cout << str.top() << std::endl;
        str.pop();
        std::cout << str.size() << std::endl;
        str.push("three");
        str.push("four");
        str.push("five");
        std::cout << "MutantStack class reverse content checking:" << std::endl;
        MutantStack<std::string>::reverse_iterator from = str.rbegin();
        MutantStack<std::string>::reverse_iterator to = str.rend();
        ++from;
        --from;
        while (from != to) {
            std::cout << *from << std::endl;
            ++from;
        }
    }
    return 0;
}
