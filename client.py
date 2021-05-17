import socket, select, string, sys

if __name__ == "__main__":
	#ник клиента
    	name=input("Enter username: ")
    	#создание сокета
    	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    	#подключение к серверу
    	s.connect(('localhost', 5050))
    	#отправить ник подключившегося клиента
    	s.send(name.encode())
    
    	while 1:
        	socket_list = [sys.stdin, s]
        	#список доступных для чтения сокетов
        	rList, wList, error_list = select.select(socket_list , [], [])
        	for sock in rList:
            		if sock == s:
            			#получение сообщение с сервера
                		data = sock.recv(4096).decode()
                		if not data :
                    			print("DISCONNECTED!\n")
                    			sys.exit()
                		else :
                    			print(data)

      
            		else :
            		# клиент вводит и отправляет сообщение
                		msg=sys.stdin.readline()
                		s.send(msg.encode())
	
