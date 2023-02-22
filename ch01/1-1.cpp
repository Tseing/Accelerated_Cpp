#include <string>

int main()
{
    // "+" can be used to connect 2 string objs or a string obj and a string literal
    const std::string hello = "Hello";
    const std::string message1 = hello + ", world" + "!";

    // Error: "+" should not be used to connect 2 string literal
    const std::string exclam = "!";
    const std::string message2 = "Hello" + ", world" + exclam;

    return 0;
}