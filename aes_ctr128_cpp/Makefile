aes128: aesctr.o bytestringspp.o
	g++ -o aes128 aesctr.o bytestringspp.o -lcryptopp
bytestringspp.o: ../hexreader_c/bytestringspp.cpp
	g++ -c ../hexreader_c/bytestringspp.cpp
aesctr.o: aesctr.cpp
	g++ -c aesctr.cpp
clean:
	rm aes128 *.o



