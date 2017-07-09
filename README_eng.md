# ft_printf - sjang@student.42.us.org

Recreation of Standard C Library functions `printf`.

### TOC
* [What is ft_printf?](#what-is-ft_printf)
* [How do I use it?](#how-do-i-use-it)
* [How do I test it?](#how-do-i-test-it)

### What is ft_printf?

[ft_printf][1] is a individual project at [42][2] that recreate Standard C Library functions `printf`.

### How do I use it?

As a result of this project, I make a library called `libftprintf.a`.
Let's make this library together to use ft_printf.

First of all, download/clone this repo:

	git clone https://github.com/sjang42/42Project_Printf.git

Get into it and build the library:
	
	cd 42Project_Printf.git
	make

Alright, the last command created a `libftprint.a` library in your directory. Now you can use it in your other functions.
If you use gcc compiler, just include -L and -l options during compile.

### How do I test it?

I made a folder called `test` that has main.c, main.h and Makefile.
This Makefile will complile main.c with libftprintf.a library you just created.

	cd test
	make

You can edit main.c file to test other situation.
Enjoy!

[1]: https://github.com/sjang42/42Project_Printf/blob/master/ft_printf.en.pdf
[2]: http://42.us.org "42 USA"
