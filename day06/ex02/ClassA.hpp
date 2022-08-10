/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:10:00 by senglish          #+#    #+#             */
/*   Updated: 2022/06/23 18:10:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSA_HPP
# define CLASSA_HPP

#include "ClassBase.hpp"

class A : public Base
{
    public:
        A();
        virtual ~A();
        const char &getType() const;
    private:
        const char _type;
};

#endif