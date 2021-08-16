# gdb-samples
sample code for learning gdb

bugged.c
from [Linux: The Textbook, Second Edition By Sarwar, Koretsky](https://books.google.co.jp/books?id=XjkPEAAAQBAJ&pg=PA425&lpg=PA425&dq=bugging.c+gdb&source=bl&ots=epYt9OM7nn&sig=ACfU3U33D7tA-6gox1yrJtwKInjyqoxvCg&hl=en&sa=X&ved=2ahUKEwivnJbYvLTyAhXyxosBHbFwAXgQ6AF6BAgoEAM#v=onepage&q&f=false)

```bash
$ gcc bugged.c -o bugged
$ ./bugged
Enter a string: Hello!
Segmentation fault (core dumped)
$
