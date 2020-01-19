/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:12:16 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/18 21:26:40 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

bool usage(void)
{
	std::cout << "./ft_retro [name]" << std::endl;
	return (1);
}

int main(int argc, const char *argv[])
{
	Windows	win;
	Player	player("Louise");

	(void)argv;
	if (argc != 2)
		return (usage());
	win.printBorder();
	win.setCursor(20, 20);
	win.printGameEntity(player);
	win.updateEvent();
	if (win.buttonsPressed(BUTTON_UP))
		std::cout << "lol" << std::endl;
	endwin();
	return 0;
}
