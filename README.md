## ft_printf - sjang@student.42.us.org

## 목차
* [개요](#개요)
* [개발 환경](#개발-환경)
* [사용된 함수](#사용된-함수)
* [빌드 방법](#빌드-방법)
* [라이브러리 사용 방법](#라이브러리-사용-방법)
* [사용 예제](#사용-예제)
* [참고](#참고)

## 개요

[ft_printf][1] 는 C언어의 printf 함수를 재구현하는 [42 Silicon Valley][2]의 개인 프로젝트입니다.
해당 소스코드를 빌드하여 결과물인 `libftprintf.a`를 얻게 됩니다.
이 라이브러리는 목표 함수인 printf에 관한 목적파일을 담고있는 라이브러리로
이를 이용하여 다른 프로젝트에서 ft_printf 함수를 사용할 수 있습니다.

## 개발 환경
* OS
	* Ubuntu 16.04
* Language
	* C
* Compiler
	* gcc
* builder
	* MAKE

## 사용된 함수
* 출력 관련 함수
	* write
* 메모리 관련 함수
	* malloc
	* realloc
	* free
* 가변인자 관련 함수
	* va_start
	* va_arg
	* va_end
* 나머지 ft_memset, ft_strdup 등의 함수는 write, malloc, free, realloc 함수를 이용해 직접 구현한 함수입니다.
	* [42Project_Libft][4] 참고

## 빌드 방법

먼저 우분투(16.04v) 터미널 환경을 사용한다고 가정하겠습니다.
make 프로그램이 설치되어있어야 합니다.

먼저 터미널에서 라이브러리를 저장할 폴더로 이동합니다.
먼저 해당 깃을 클론합니다.

	git clone https://github.com/sjang42/42Project_Printf.git

`Makefile` 이 포함되어있으므로 해당 파일을 이용해 빌드할 수 있습니다.

	cd 42Project_printf
	make

`libftprintf.a`가 만들어졌습니다.

## 라이브러리 사용 방법

앞서 빌드한 libftprintf.a 정적 라이브러리를 사용하여 다른 프로젝트에서 ft_printf함수를 사용하는 방법입니다.
리눅스 터미널에서 gcc 컴파일러를 이용해 컴파일 하는 경우입니다.

1. `42Project_Printf.git/include` 디렉터리에 있는 "ft_printf.h" 헤더파일을 포함합니다.
2. 앞서 빌드한 `libftprintf.a` 라이브러리 파일을 프로젝트 디렉터리로 옮깁니다.
3. 컴파일시 `-lftprintf` 옵션을 추가합니다.

## 사용 예제

샘플제공을 위하여 `test` 디렉터리를 추가하였습니다.
`test` 디렉터리는 `main.c`, `main.h`와 `Makefile`로 구성되어있습니다.
해당 디렉터리로 이동하여 MAKE를 이용해 빌드하면 테스트 결과를 볼 수 있습니다.

	cd test
	make

`main.c` 파일을 수정하여 사용할 수 있습니다.

## 참고

* ft_printf는 [linux printf(3) 맨페이지][3]를 참고하여 만들어졌습니다.
* 해당 페이지에 정의 되지 않은 사용은 linux gcc * version의 결과를 참고하였습니다.

[1]: https://github.com/sjang42/42Project_Printf/blob/master/ft_printf.en.pdf
[2]: http://42.us.org "42 USA"
[3]: https://linux.die.net/man/3/printf
[4]: https://github.com/sjang42/42Project_Libft
