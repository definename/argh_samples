#include "pch.h"

/*
Usage:
    --call out_offers_14_15_new.log --timeout=500 --index=24533 --delay=500
*/

int main(int argc, char* argv[])
{
    try
    {
        auto cmdl = argh::parser(argc, argv);

        if (cmdl[{"-c", "--call"}]) {
            unsigned int threadCount;
            cmdl({ "-t", "--thread" }, 1) >> threadCount;
            unsigned int delay;
            cmdl({ "-d", "--delay" }, 0) >> delay;
            unsigned int startIndex;
            cmdl({ "-i", "--index" }, 1) >> startIndex;

            std::cout << "call: "<< cmdl[1] 
                << " thread:" << threadCount
                << " delay:" << delay
                << " startIndex: " << startIndex << std::endl;
        }
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