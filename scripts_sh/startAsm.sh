#/bin/bash
echo "\t\tУдаляем отладочную информацию, смотрим размер, дизассемблируем, удаляем ненужные секции, смотрим размер"
strip a.out && du -sb a.out
sleep 4
echo "\t\tДизассемблируем"
objdump -D a.out
sleep 1
echo "\t\tУдаляем ненужные секции"
strip -R .note.gnu.build-id a.out && strip -R .comment a.out && strip -R .note.ABI-tag a.out && strip -R .bss a.out && strip -R .got  a.out && strip -R .gnu.version a.out && strip -R .eh_frame a.out && strip -R .eh_frame_hdr a.out
sleep 2
echo "\t\t Итоговый размер"
du -sb a.out
