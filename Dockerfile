FROM ubuntu
RUN apt-get update && apt-get install g++ -y
RUN apt-get install g++-multilib -y
COPY ./1.cpp /home/1.cpp
COPY ./start.sh /home/start.sh
WORKDIR /home
ENTRYPOINT ["sh","./start.sh"]
