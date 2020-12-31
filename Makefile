build:
	(mkdir Linux&&g++ "XMas Administrator".cpp -o ./Linux/"XMas Administrator")||g++ "XMas Administrator".cpp -o ./Linux/"XMas Administrator"
	(mkdir Windows-32&&i686-w64-mingw32-g++ -o ./Windows-32/"XMas Administrator".exe "XMas Administrator".cpp)||i686-w64-mingw32-g++ -o ./Windows-32/"XMas Administrator".exe "XMas Administrator".cpp
	(mkdir Windows-64&&x86_64-w64-mingw32-g++ -o ./Windows-64/"XMas Administrator".exe "XMas Administrator".cpp)||x86_64-w64-mingw32-g++ -o ./Windows-64/"XMas Administrator".exe "XMas Administrator".cpp
linux-run:
	./Linux/"XMas Administrator"