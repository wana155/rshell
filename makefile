rshell: main.cpp Command.cpp CommandExecute.cpp GetInput.cpp BaseExecute.cpp Redirection.cpp
	g++ -o rshell main.cpp Command.cpp CommandExecute.cpp GetInput.cpp BaseExecute.cpp Redirection.cpp -I.
	mkdir bin
	cp rshell bin

