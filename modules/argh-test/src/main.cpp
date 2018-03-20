#include "pch.h"

int main(int argc, char* argv[])
{
    try
    {

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