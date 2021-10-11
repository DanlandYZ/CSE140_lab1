#include <fstream>

int main(int argc, char *argv[])
{
	std::ofstream ofs ("hello.txt", std::ofstream::out);
	ofs << "Hello hozhao@ucsd.edu!\n";
	ofs.close();
	return 0;  
}
