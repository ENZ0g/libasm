# libasm *in progress...*

Проект выполнялся на Mac OS X 10.14.6 \
Узнать вашу версию можно командой

```
$ sw_vers
```

Или нажмите на яблоко в верхнем левом углу экрана и выберете `About This Mac`.

## Установка NASM

Для компиляции я использовал NASM. Установка:

```
brew install nasm
```

Если нет brew, выполните:

```
curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
```

Еще необходим gcc, подразумевается, что он есть. Чтобы проверить, что у вас все работает, склонируйте репозиторий, перейдите в него и выполните:

```
./check.sh
```

Если вы увидели поздравление, значит всё работает.

### Hello world

Разберем код поздравления и познакомимся с ассемблером.

```
global  _main                   ; точка входа в программу, будет вызвана процедура _main

section .text                   ; в секции text пишется код программы
_main:                          ; объявляем процедуру _main
    mov     rax, 0x02000004     ; помещаем в регистр rax код действия - write
	mov     rdi, 1              ; помещаем в регистр rdi файловый дескриптор - stdout
    lea     rsi, [message]      ; помещаем в регистр rsi сообщение для вывода
    mov     rdx, len            ; помещаем в регистр rdx длину сообщения
    syscall                     ; просим ОС выполнить то, что мы закодировали выше
	call    _exit               ; вызываем процедуру _exit

_exit:                          ; объявляем процедуру _exit
    mov       rax, 0x02000001   ; помещаем в регистр  rax код действия - exit
    xor       rdi, rdi          ; помещаем в регистр rdi код ошибки - 0
    syscall                     ; просим ОС выполнить то, что мы закодировали выше

section   .data                 ; в секции data объявляются "переменные"
message default rel             ; объявляем message и помещаем туда сообщение
		db		"Congrats! Everything is working OK!", 10, 0
len 	equ 	$-message       ; объявляем len и помещаем туда длину сообщения 
```


### Полезные ссылки

- [NASM tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
- [NASM docs (на русском)](http://www.opennet.ru/docs/RUS/nasm/contents.html)
- [Видео уроки по FASM ассемблеру (на русском)](https://www.youtube.com/playlist?list=PLd-kTafWJCJN6OpkPAKzmqVnyCFUrDLTh)