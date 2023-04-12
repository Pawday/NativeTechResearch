#include <iostream>
#include <string>


int main()
{
    std::string source = "#include <iostream>\n#include <string>\n\n\nint main()\n{\n	std::string source = \"?\";\n	\n	for (char c : source)\n	{\n		if (c != 63) std::cout << c;\n\n		else\n		{\n			for (char ic : source)\n			{\n				if (ic == \'\\\\\')\n				{\n					std::cout << \"\\\\\\\\\";\n					continue;\n				}\n				\n				if (ic == \'\\n\') \n				{\n					std::cout << \"\\\\n\";\n					continue;\n				}\n				\n				if (ic == \'\"\') \n				{\n					std::cout << \"\\\\\\\"\";\n					continue;\n				}\n				\n				if (ic == \'\\\'\') \n				{\n					std::cout << \"\\\\\\\'\";\n					continue;\n				}\n				\n				std::cout << ic;\n			}\n		}\n		\n	} \n}";

    for (char c : source)
    {
        if (c != 63) std::cout << c;

        else
        {
            for (char ic : source)
            {
                if (ic == '\\')
                {
                    std::cout << "\\\\";
                    continue;
                }

                if (ic == '\n')
                {
                    std::cout << "\\n";
                    continue;
                }

                if (ic == '"')
                {
                    std::cout << "\\\"";
                    continue;
                }

                if (ic == '\'')
                {
                    std::cout << "\\\'";
                    continue;
                }

                std::cout << ic;
            }
        }

    }
}