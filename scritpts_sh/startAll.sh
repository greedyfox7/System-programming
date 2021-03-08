#/bin/bash
echo "\tЗапуск 1"
sh ./start.sh
sleep 2
read intput
echo "\n\n\n\tЗапуск 2"
sleep 2
sh ./startOut.sh
sleep 2
read intput
echo "\n\n\n\tЗапуск 3"
sh ./startAsm.sh
sleep 2
/bin/bash
