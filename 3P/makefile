CXX=g++

all: image

pepper: image.cpp
	$(CXX) image.cpp -o image
	./image pepper.pgm n_pepper.pgm r_pepper.pgm
	convert n_pepper.pgm a.png
	convert r_pepper.pgm b.png

mammoth: image.cpp
	$(CXX) image.cpp -o image
	./image mammoth.pgm n_mammoth.pgm r_mammoth.pgm
	convert n_mammoth.pgm a.png
	convert r_mammoth.pgm b.png


imagestack: imagestack.cpp
	$(CXX) imagestack.cpp -o images


clean:
	rm -f image imagestack
