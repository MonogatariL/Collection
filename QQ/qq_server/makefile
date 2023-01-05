all:server client
server:server.cpp
	g++ server.cpp -o server  -Iinclude cpp/qq_database.cpp -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
client:client.cpp
	g++ client.cpp -o client