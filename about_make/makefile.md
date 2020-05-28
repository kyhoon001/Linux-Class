# makefile 형식

## makefile 형태
1. 원래 형태
    ```
    a.out : bbq.o kfc.o bhc.o   // 타겟 : 의존성
        gcc -o a.out bbq.o kfc.o bhc.o // 명령어

    bbq.o : bbq.c 
        gcc -c -o bbq.o bbq.c

    kfc.o : kfc.c
        gcc -c -o kfc.o kfc.c
    
    bhc.o : bhc.c
        gcc -c -o bhc.o bhc.c

    clean : // 삭제하는 명령어 여기서는 -c 를 이용해서 목적파일을 만들었으므로
        rm *.o a.out        // 이와 같으 *.o 파일이 존재함.

    // make clean을 입력해서 실행 가능.
    ```


2. 메크로를 사용한 형태.

```
// 여기는 마치 변수를 할당하는 것과 같은 역할을 함.
CC=gcc
CFLAGS = -W Wall   == gcc 옵션   // Wall의 경우 오류를 출력해줌(?) -W -Wall로도 사용
OBJS = main.c foo.c bar.c    == 오브젝트 // 목적파일을 의미
TARGET = app.out        //만들어지는 타겟.

/////////////////////////////////////////

all : $(TARGET)

$(TARGET) : $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^   
    //$@는 타겟의 이름을 의미하고, $^는 타겟의 종속 항목 리스트를 의미함.

clean :
    rm app.out

이런 식으로 사용하면 몹시 간단해짐.
```


3. 최종 모습
```
CC=gcc
CFLAGS = -g Wall  
OBJS = main.o foo.o bar.o   
TARGET = app.out      


all : $(TARGET)

$(TARGET) : $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^   

clean :
    rm *.o app.out

```