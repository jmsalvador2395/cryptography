all:: aesdecrypt aesencrypt

aesdecrypt: aesctrdecrypt.o bytestringspp.o
	g++ -o aesdecrypt aesctrdecrypt.o bytestringspp.o -lcryptopp
aesencrypt: aesctrencrypt.o bytestringspp.o
	g++ -o aesencrypt aesctrencrypt.o bytestringspp.o -lcryptopp
bytestringspp.o: ../hexreader_c/bytestringspp.cpp
	g++ -c ../hexreader_c/bytestringspp.cpp
aesctrdecrypt.o: aesctrdecrypt.cpp
	g++ -c aesctrdecrypt.cpp
aesctrencrypt.o: aesctrencrypt.cpp
	g++ -c aesctrencrypt.cpp
clean:
	rm aesdecrypt aesencrypt *.o



