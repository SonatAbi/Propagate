#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "heap_priority_queue.h"
#include "image.h"

using namespace std;
struct pixel
{
	int s;
	int x;
	int y;

	bool operator<(const pixel& rhs) const
	{
		if (s < rhs.s)
		{
			return true;
		}
		else {
			return false;
		}
	}
	bool operator==(const pixel& rhs) const
	{
		if (s == rhs.s)
		{
			return true;
		}
		else {
			return false;
		}
	}
	bool operator>(const pixel& rhs) const
	{
		if (s > rhs.s)
		{
			return true;
		}
		else {
			return false;
		}
	}
};

void fillheap(Image<Pixel> &input, Image<Pixel> &speed, Image<Pixel> &output, HeapPriorityQueue<pixel> &heap);
void paint(Image<Pixel> &input, Image<Pixel> &speed, Image<Pixel> &output, HeapPriorityQueue<pixel> &heap);

int main(int argc, char *argv[])
{
	HeapPriorityQueue<pixel> heap;//HEAP
	unsigned long int T = atoi(argv[4]);
	if (argc != 5 || T < 0) {//COMMAND LINE
		std::cerr << "Error1" << std::endl;
		return EXIT_FAILURE;
	}
	////////////IMAGE LIBRARY//////////////////////////////////////////////////////
	Image<Pixel> input = readFromFile(argv[1]);
	Image<Pixel> speed = readFromFile(argv[2]);
	Image<Pixel> output = input;
	///////////////CHECKING ERRORS/////////////////////////////////////////////////
	if ((input.width() != speed.width()) || (input.height() != speed.height())) {
		std::cerr << "Error2" << std::endl;
		return EXIT_FAILURE;
	}
	for (unsigned int i = 0; i < input.width(); ++i) {
		for (unsigned int j = 0; j < input.height(); ++j) {

			int red = input(i, j).red;
			int green = input(i, j).green;
			int blue = input(i, j).blue;
			if ((red != 0 && red != 255) || (green != 0 && green != 255) || (blue != 0 && blue != 255)) {
				std::cerr << "Error3" << std::endl;
				return EXIT_FAILURE;
			}
			else {

			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	fillheap(input, speed, output, heap);
	for (int i = 0; i < T; i++) {
		paint(input, speed, output, heap);
	}
	for (unsigned int i = 0; i < input.width(); ++i)
	{
		for (unsigned int j = 0; j < input.height(); ++j)
		{
			int b = output(i, j).red;
			if (b == 100) {
				output(i, j).red = 255;
			}
		}
	}
	writeToFile(output, argv[3]);
	std::cout << "done" << std::endl;
	return EXIT_SUCCESS;
}

void paint(Image<Pixel> &input, Image<Pixel> &speed, Image<Pixel> &output, HeapPriorityQueue<pixel> &heap) {
	if (!heap.isEmpty())
	{
		//paint peeked pixel
		pixel p = heap.peek();
		int i = p.x;
		int j = p.y;

		output(i, j).red = 0;
		output(i, j).green = 0;
		output(i, j).blue = 0;
		heap.remove();
		//right pixel
		if (i != input.width() - 1) {
			int right = output(i + 1, j).red;
			if (right == 255) {
				int s = speed(i + 1, j).red;
				output(i+1, j).red = 100;
				pixel inforight;
				inforight.s = s;
				inforight.x = i + 1;
				inforight.y = j;
				heap.add(inforight);
			}
		}
		//top pixel
		if (j != 0) {
			int top = output(i, j - 1).red;
			if (top == 255) {
				int s = speed(i, j - 1).red;
				output(i, j-1).red = 100;
				pixel infotop;
				infotop.s = s;
				infotop.x = i;
				infotop.y = j - 1;
				heap.add(infotop);
			}
		}
		//left pixel
		if (i != 0) {
			int left = output(i - 1, j).red;
			if (left == 255) {
				int s = speed(i - 1, j).red;
				output(i-1, j).red = 100;
				pixel infoleft;
				infoleft.s = s;
				infoleft.x = i - 1;
				infoleft.y = j;
				heap.add(infoleft);
			}
		}
		//bot pixel
		if (j != input.height() - 1) {
			int bot = output(i, j + 1).red;
			if (bot == 255) {
				int s = speed(i, j + 1).red;
				output(i, j+1).red = 100;
				pixel infobot;
				infobot.s = s;
				infobot.x = i;
				infobot.y = j + 1;
				heap.add(infobot);
			}
		}
	}
}


void fillheap(Image<Pixel> &input, Image<Pixel> &speed, Image<Pixel> &output, HeapPriorityQueue<pixel> &heap) {
	for (unsigned int i = 0; i < input.width(); ++i)
	{
		for (unsigned int j = 0; j < input.height(); ++j)
		{
			int c = input(i, j).red;
			if (c == 0)
			{
				//right pixel
				if (i != input.width() - 1) {
					int right = input(i + 1, j).red;
					if (right == 255) {
						int s = speed(i + 1, j).red;
						output(i+1, j).red = 100;
						pixel inforight;
						inforight.s = s;
						inforight.x = i + 1;
						inforight.y = j;
						heap.add(inforight);
					}
				}
				//top pixel
				if (j != 0) {
					int top = input(i, j - 1).red;
					if (top == 255) {
						int s = speed(i, j - 1).red;
						output(i, j-1).red = 100;
						pixel infotop;
						infotop.s = s;
						infotop.x = i;
						infotop.y = j - 1;
						heap.add(infotop);
					}
				}
				//left pixel
				if (i != 0) {
					int left = input(i - 1, j).red;
					if (left == 255) {
						int s = speed(i - 1, j).red;
						output(i-1, j).red = 100;
						pixel infoleft;
						infoleft.s = s;
						infoleft.x = i - 1;
						infoleft.y = j;
						heap.add(infoleft);
					}
				}
				//bot pixel
				if (j != input.height() - 1) {
					int bot = input(i, j + 1).red;
					if (bot == 255) {
						int s = speed(i, j + 1).red;
						output(i, j+1).red = 100;
						pixel infobot;
						infobot.s = s;
						infobot.x = i;
						infobot.y = j + 1;
						heap.add(infobot);
					}
				}
			}
		}
	}
}