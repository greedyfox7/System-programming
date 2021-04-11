FROM centos
RUN yum -y update
RUN yum -y install gcc-c++
COPY ./pac.cpp /home/pac.cpp
COPY ./1.cpp /home/1.cpp
COPY ./2.cpp /home/2.cpp
COPY ./start.sh /home/start.sh
WORKDIR /home
ENTRYPOINT ["sh","./start.sh"]
