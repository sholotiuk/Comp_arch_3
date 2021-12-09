#include <iostream>
#include <getopt.h>
#include <vector>
#include <algorithm>


int main (int argc, char *argv[]) {
	const char* short_options = "hvas:";

	const struct option long_options[] = {
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'v'},
	        {"chars", no_argument, NULL, 'c'},
		{"echo value", required_argument, NULL, 'e'},
		{NULL,0,NULL,0}
	};

	int result;
	int option_index;

	std::vector<int> parsed_args;

	while ((result=getopt_long(argc,argv,short_options,long_options,&option_index)) != -1) {

		if (std::count(parsed_args.begin(), parsed_args.end(), result)) {
			continue;
		} else {
			parsed_args.push_back(result);
		}

		switch (result) {
			case 'h':
				std::cout << "Arg: Help\n";
				break;
			case 'v':
				std::cout << "Arg: Version\n";
				break;
			case 'c':
			        std::cout << "Arg: Chars\n";
                                break;
			case 'e':
				std::cout << "Arg: Value: " << optarg << std::endl;
				break;
			default:
				break;
		}
	}

	return 0;
}
