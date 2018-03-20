#include "pch.h"

/*
    Usage:
        --call --file=out_offers_14_15_new.log --timeout=500 --index=24533 --delay=500 --thread=1
        --call --file out_offers_14_15_new.log --timeout 500 --index 24533 --delay 500 --thread 1
*/

int main(int argc, char* argv[])
{
    try
    {

        // To parse: --call --file=out_offers_14_15_new.log --timeout=500 --index=24533 --delay=500 --thread=1
        auto cmdl = argh::parser(argc, argv);

        // To parse: --call --file out_offers_14_15_new.log --timeout 500 --index 24533 --delay 500 --thread 1
        //auto cmdl = argh::parser(argc, argv, argh::parser::PREFER_PARAM_FOR_UNREG_OPTION);

        if (cmdl[{"-c", "--call"}]) {

            std::string file(cmdl({ "-f", "--file" }).str());

            unsigned int threadCount;
            cmdl({ "-t", "--thread" }, 1) >> threadCount;
            unsigned int startIndex;
            cmdl({ "-i", "--index" }, 1) >> startIndex;
            unsigned int delay;
            cmdl({ "-d", "--delay" }, 0) >> delay;

            unsigned int timeout;
            if (!(cmdl({ "-t", "--timeout" }) >> timeout))
                throw std::runtime_error("Invalid timeout was given");

            std::cout
                << "file: " << file << "\n"
                << "thread:" << threadCount << "\n"
                << "startIndex: " << startIndex << "\n"
                << "delay:" << delay << "\n"
                << "timeout:" << timeout << "\n";
        }

        std::cout << "Positional args:\n";
        for (auto& pos_arg : cmdl.pos_args())
            std::cout << '\t' << pos_arg << '\n';

        std::cout << "\nFlags:\n";
        for (auto& flag : cmdl.flags())
            std::cout << '\t' << flag << '\n';

        std::cout << "\nParameters:\n";
        for (auto& param : cmdl.params())
            std::cout << '\t' << param.first << " : " << param.second << '\n';
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