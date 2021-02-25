FROM centos
COPY ./var11.sh /home/sav.sh
COPY ./file.txt /home/file.txt
COPY ./hello.txt /home/helo.txt
ENTRYPOINT /bin/bash
