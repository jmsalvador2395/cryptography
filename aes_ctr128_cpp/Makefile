aesdecrypt: aesctrdecrypt.o bytestringspp.o
	g++ -o aesdecrypt aesctrdecrypt.o bytestringspp.o -lcryptopp
bytestringspp.o: ../hexreader_c/bytestringspp.cpp
	g++ -c ../hexreader_c/bytestringspp.cpp
aesctrdecrypt.o: aesctrdecrypt.cpp
	g++ -c aesctrdecrypt.cpp
clean:
	rm aesdecrypt *.o



