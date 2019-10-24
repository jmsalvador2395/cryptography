all: aesdecrypt aesencrypt

aesdecrypt: aescbcdecrypt.o bytestringspp.o
	g++ -o aesdecrypt aescbcdecrypt.o bytestringspp.o -lcryptopp
aesencrypt: aescbcencrypt.o bytestringspp.o
	g++ -o aesencrypt aescbcencrypt.o bytestringspp.o -lcryptopp
bytestringspp.o: ../hexreader_c/bytestringspp.cpp
	g++ -c ../hexreader_c/bytestringspp.cpp
aescbcencrypt.o: aescbcencrypt.cpp
	g++ -c aescbcencrypt.cpp
aescbcdecrypt.o: aescbcdecrypt.cpp
	g++ -c aescbcdecrypt.cpp
clean:
	rm aesdecrypt aesencrypt *.o



