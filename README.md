# libasm

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

Еще необходим gcc, подразумевается, что он есть. Чтобы проверить, что у вас все работает выполните:

```
curl -LO https://raw.github.com/ENZ0g/libasm/master/srcs/check.sh && bash check.sh
```

### Hello world

Разберем код на примере.

### Полезные ссылки

- [NASM tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
- [NASM docs (на русском)](http://www.opennet.ru/docs/RUS/nasm/contents.html)