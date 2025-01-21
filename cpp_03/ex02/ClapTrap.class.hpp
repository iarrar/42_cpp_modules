/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:52:13 by iarrar            #+#    #+#             */
/*   Updated: 2024/01/30 14:52:14 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>
#include <string>

class ClapTrap
{
public:
    ClapTrap();
    ClapTrap(std::string Name);
    ClapTrap(ClapTrap const & src);
    ~ClapTrap();
   ClapTrap& operator=(ClapTrap const & src);
   void attack(const std::string & target);
   void takeDamage(unsigned int amount);
   void beRepaired(unsigned int amount);


protected:
    std::string _Name;
    int         _Hit_points;
    int         _Energy_points;
    int         _Attack_damage;

};

#endif