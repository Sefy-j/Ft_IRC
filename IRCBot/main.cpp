/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlopez-f <jlopez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:33:16 by jlopez-f          #+#    #+#             */
/*   Updated: 2023/02/17 19:49:29 by jlopez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bot.hpp"

bool *execptr;

static bool	checkpass(std::string pass)
{
	if (pass.size() > PASSLEN)
	{
			std::cerr << RED << "Error. Invalid password" << NOCOLOR << std::endl;
			return (false);
	}
	for (std::string::const_iterator it = pass.begin(); it != pass.end(); it++)
	{
		if (!isprint(*it) || isspace(*it))
		{
			std::cerr << RED << "Error. Invalid password" << NOCOLOR << std::endl;
			return (false);
		}
	}
	return (true);
}

static bool	checkport(std::string port)
{
	if (port.empty() || port.size() > 5)
	{
		std::cerr << RED << "Error. Invalid port" << NOCOLOR << std::endl;
		return (false);
	}
	for (std::string::const_iterator it = port.begin(); it != port.end(); it++)
	{
		if (!isdigit(*it))
		{
			std::cerr << RED << "Error. Invalid port" << NOCOLOR << std::endl;
			return (false);
		}
	}
	int	portnum = atoi(port.c_str());
	if (portnum <= MIN_PORT || portnum >= MAX_PORT)
	{
			std::cerr << RED << "Error. Invalid port" << NOCOLOR << std::endl;
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << RED << "Error. Introduce port and password" << NOCOLOR << std::endl;
		return (1);
	}
	std::string	port = argv[1];
	std::string	pass = argv[2];

	if (!checkport(port) || !checkpass(pass))
		return (1);
	Bot	bot(port, pass);
	bot.start();
	return (0);
}
