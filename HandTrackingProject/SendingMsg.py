import socket

server_ip = '192.168.137.147'
server_port = 3000
soc = socket.socket()
soc.connect((server_ip, server_port))
soc.send("mydata")