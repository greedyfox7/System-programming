import socket, select

#отправить сообщение всем клиентам, кроме сервера и самого отправителя
def send_to_all (sock, message):
	for socket in connected_list:
		if socket != server_socket and socket != sock:
			socket.send(message.encode())

if __name__ == "__main__":
	name=""
	#словарь пара адрес - имя клиента
	record={}
	#подключенные сокеты
	connected_list = []
	#создание сокета
	server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	#связываем сокет с хостом и портом
	server_socket.bind(("localhost", 5050))
	#прослушивать могут не больше 5 клиентов
	server_socket.listen(5)
	#добавили сервер сокета в список доступных для чтения
	connected_list.append(server_socket)

	print("\tSERVER WORKING")

	while 1:
		#Получили список сокетов, которые готовы к чтению
		rList,wList,error_sockets = select.select(connected_list,[],[])
		for sock in rList:
			#Новый клиент подключается
			if sock == server_socket:
				#принимаем подключение, получаем два элемента: новый сокет и адрес клиента
				sockfd, addr = server_socket.accept()
				#принимаем сообщение о имени клиента
				name=sockfd.recv(4096).decode()
				#добавили новый сокет клиента в список доступных для чтения
				connected_list.append(sockfd)
				#добавили в словарь пару адрес - ник клиента
				record[addr]=name
				#вывод в консоли сервера - клиент подлючился
				print("Client (%s, %s) connected" % addr," [",record[addr],"]\n")
				#вывод в консоли клиента - приветсвия
				sockfd.send("Welcome to chat room. Enter 'tata' anytime to exit\n".encode())
				#отправка всем клиентам - о подключении нового клиента
				send_to_all(sockfd, " "+name+" joined the conversation\n")

			else:
				#иначе получаем какое либо сообщение от клиента
				data1 = sock.recv(4096).decode()
				data=data1[:data1.index("\n")]
				#получаем адрес клиента, который отправил сообщение
				i,p=sock.getpeername()
				#если стоп слово - выходим из чата, удаляем данные
				if data == "tata":
					msg=" "+record[(i,p)]+" left the conversation\n"
					send_to_all(sock,msg)
					print("Client (%s, %s) is offline" % (i,p)," [",record[(i,p)],"]\n")
					del record[(i,p)]
					connected_list.remove(sock)
					sock.close()
					continue

				else:
				#иначе отправляем всем сообщение
					msg=" "+record[(i,p)]+": "+" "+data+"\n"
					send_to_all(sock,msg)
            
	server_socket.close()
