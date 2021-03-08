FROM ubuntu
RUN apt-get -y update
RUN apt-get -y install gcc
RUN apt-get -y install g++
RUN apt-get -y install gcc-multilib
RUN apt-get -y install g++-multilib
COPY ./1.c /home/1.c
COPY ./1.cpp /home/1.cpp
COPY ./1.s /home/1.s
COPY ./startAll.sh /home/startAll.sh
COPY ./start.sh /home/start.sh
COPY ./startOut.sh /home/startOut.sh
COPY ./startAsm.sh /home/startAsm.sh
WORKDIR /home
ENTRYPOINT ["sh","./startAll.sh"]
