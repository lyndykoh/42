/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:29:31 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/18 21:01:18 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name ) {
    Zombie zomzom(name);
    zomzom.announce();
}