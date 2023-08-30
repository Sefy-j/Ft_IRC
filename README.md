# Ft_IRC

This project presents a real time chat server based on IRC protocol, with a simple bot and file transfer via IRC client.

## Description

Using the IRC protocol as reference, this project serves as a simple real time chat server, fully compatible with a standard client. It uses TCP/IP sockets to create a network between the server and each of the connected clients, allowing direct communication between peers, as well as the creation of multiple clients channels.
It also provides several possible settings, such us server or channel moderators, fully private channels, passwords, or a ban system among others. It also provides a ping/pong system in order to keep tracking of any possible disconnection.

Every message is received as a string through a TCP/IP socket, and after being parsed following the IRC protocol, the server completes the given task if it is a suitable command. Otherwise, the command is silently ignored, warning the command sender if needed. Every message sent, as well as any warning or server response is privately sent to each of the required client, so no information is received by any other than the right user.

It also implements a simple bot, allowing the maintenance of a channel active even if all the original users disconnect, as well as retrieving their permissions in case of their comeback.

The server also permits sending files using the standard DCC protocol present on IRC clients.

Everything was implemented in C/C++ programming language.

## Classes

The server itself uses the next classes:

* [Server](https://github.com/Sefy-j/Ft_IRC/blob/master/Server.hpp) : Main server class. It implements the socket creation, as well as every connection, command, or message sending needed.
* [User](https://github.com/Sefy-j/Ft_IRC/blob/master/User.hpp) : Allows the storage of every piece of data the server needs about an user.
* [Channel](https://github.com/Sefy-j/Ft_IRC/blob/master/Channel.hpp) : It provides the necessary structure for every channel.
* [Parser](https://github.com/Sefy-j/Ft_IRC/blob/master/Parser.hpp) : Parser for every received command.

In case of the bot, the same parser is used again, as well as this new class:

* [Bot](https://github.com/Sefy-j/Ft_IRC/blob/master/IRCBot/Bot.hpp) : Implements the bot capacities for channel maintenance.

## Build and Run the project

This project uses a Makefile in order to create the needed executable. Simply run "make" to generate only the basic server, or "make bonus" to create the bot as well.

To run the programs, start running the server with the desired password, and a suitable port to bind:

```
./ircserv PORT PASSWORD
```

Once the server launches, connect the bot to the server in the same way you did before:

```
./ircbot PORT PASSWORD
```
Both PORT and PASSWORD must correspond to the ones used in the server launch.

After that, you can connect to the server using your preferred IRC client.

Remember that the bot itself can be used in any other similar server, given the right PORT and PASSWORD.

## Authors

This project was develop in collaboration with [SichuanVilly](https://github.com/SichuanVilly)

## License

MIT
