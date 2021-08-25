# Minitalk
___

## Table of contents
- [Minitalk](#minitalk)
	- [Table of contents](#table-of-contents)
	- [About](#about)
	- [Server](#server)
	- [Client](#client)
	- [Sigaction](#sigaction)
	- [Kill](#kill)
	- [Bitwise Operators](#bitwise-operators)



## About

The purpose of this project is to code a small data exchange program using UNIX signals. 
We must create a communication program in the form of a client and server. 
The server must be launched first, and after being launched it must display its PID.
The client will take as parameters: (Server PID, string that should be sent).
The client must communicate the string passed as a parameter to the server.
Once the string has been received, the server must display it.
The server should be able to receive strings from several clients in a row, without needing to be restarted.
We can only use the two signals SIGUSR1 and SIGUSR2.
We must also add a a small reception acknowledgment system and both client et server should support Unicode (UTF-8)

## Server

## Client

## Sigaction

## Kill

## Bitwise Operators
