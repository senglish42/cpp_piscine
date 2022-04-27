/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:56:00 by senglish          #+#    #+#             */
/*   Updated: 2022/04/12 19:56:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_CONTACT_HPP
#define CLASS_CONTACT_HPP

#include <string>

class Contact {
public:
    Contact( void );
    ~Contact( void );
    void SetInfo(std::string name[5]);
    void GetInfo(void);
private:
    std::string _info[5];
};

#endif