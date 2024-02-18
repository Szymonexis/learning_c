all: main.exe

main.exe: src/main.c
	mkdir target
	gcc ./src/main.c -o ./target/main.exe
	./target/main.exe

clean:
	rm -f ./target/main.exe
