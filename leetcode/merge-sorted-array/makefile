all: main.exe run

main.exe: src/main.c src/main.h
	if not exist "target" mkdir target
	gcc ./src/main.c -o ./target/main.exe

run: main.exe
	./target/main.exe

# its fucky - dont know why :'(
# debug: main.exe
# 	gdb ./target/main.exe

clean:
	if exist "./target/main.exe" del /Q ./target/main.exe
	if exist "./target" rmdir /Q /S ./target
