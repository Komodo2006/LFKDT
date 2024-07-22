.PHONY: all clean test

all: ./build/datagen ./build/lfkdt

clean:
	rm ./build/datagen ./build/lfkdt

./build/datagen:
	$(MAKE) -C ./datagen all
	cp ./datagen/build/datagen ./build/datagen
./build/lfkdt:
	$(MAKE) -C ./lfkdt all
	cp ./lfkdt/build/lfkdt ./build/lfkdt

test: ./build/datagen ./build/lfkdt
	echo "100" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "200" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "300" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "500" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "700" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "1000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "2000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "3000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "5000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "7000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "10000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "20000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "30000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "50000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "70000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "100000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "200000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "300000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "500000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "700000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "1000000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "2000000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "3000000" | ./build/datagen | ./build/lfkdt | tail -n 1
	echo "5000000" | ./build/datagen | ./build/lfkdt | tail -n 1
	