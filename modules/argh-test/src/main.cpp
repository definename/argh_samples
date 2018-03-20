#include "pch.h"

/*
Usage:
    --timeout=1000 or -t=1000
*/

int main(int argc, char* argv[])
{
    try
    {
        auto cmdl = argh::parser(argc, argv);

        unsigned int timeout;
        cmdl({ "t", "timeout" }, 100) >> timeout;

        std::cout << timeout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }
	catch (...)
	{
		std::cerr << "Unhandled error occurred" << std::endl;
	}

    return 0;
}