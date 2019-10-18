aes128: aescbc.o bytestringspp.o
	g++ -o aes128 aescbc.o bytestringspp.o -lcryptopp
bytestringspp.o: ../hexreader_c/bytestringspp.cpp
	g++ -c ../hexreader_c/bytestringspp.cpp
aescbc.o: aescbc.cpp
	g++ -c aescbc.cpp
clean:
	rm aes128 *.o



