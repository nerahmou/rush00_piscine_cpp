/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:36:34 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/19 13:01:27 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

//# include "Person.hpp"
# include "Enemy.hpp"

# define PLAYER_LIMIT_MIN_X 	20
# define PLAYER_LIMIT_MAX_X 	70
# define PLAYER_LIMIT_MAX_Y 	100
# define PLAYER_LIMIT_MIN_Y 	0
# define PLAYER_DEFAULT_POS_X 	PLAYER_LIMIT_MIN_X
# define PLAYER_DEFAULT_POS_Y 	PLAYER_LIMIT_MAX_Y / 2
# define PLAYER_LIFE 			10
# define PLAYER_XP 				0
# define PLAYER_CHAR			'*'

class Player: public Person
{
	public:
		Player(std::string name);
		virtual ~Player(void);
		Enemy* shot(Enemy*);

	private:
		Player(void);
		Player(Player const &);
		Player & operator=(Player const &);
		std::string _name;
};

#endif
