// CppFeaturesSandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct DesignatedInitializerTest
{
    float x;
    int y;
    uint32_t z;
};

void CPP20Test_DesignatedInitializers()
{
    DesignatedInitializerTest testStruct{ .x = 1.0, .y = -2, .z = 3 };


    std::cout << "C++20 DesignatedInitializers Test\n"
        << "testStruct= {"
        << testStruct.x << ","
        << testStruct.y << ","
        << testStruct.z << "}";

    std::cout << "\n" << "--------------------" << "\n";
}

float Add(float a, float b)
{
    return a + b;
}

std::string Add(const std::string& a, const std::string& b)
{
    return a + b;
}

void CPP20Test_TemplatedLambdas()
{
    auto f = []<class T>(T a, T b, T c)
    {
        return Add(Add(a, b), c);
    };

    float sumFloat = f(1.0f, 2.0f, 3.0f);

    //std::string sumString = f(std::string("Bonjour"), std::string(" Hi"), std::string(" Montreal"));
    
    std::string sumString = f("Bonjour", " Hi", " Montreal");

    std::cout << "C++20 TemplatedLambdas Test\n"
        << "sumFloat=" << sumFloat << "\n"
        << "sumString=" << sumString;

    std::cout << "\n" << "--------------------" << "\n";
}

void CPP20Test_LikelyUnlikelyAttributes()
{
    
    std::cout << "C++20 [[likely]] and [[unlikely]] attributes Test\n";

    int sw = 0;
    switch (sw)
    {
    [[likely]]   case 0: std::cout << "A"; break;
                 case 1: std::cout << "B"; break;
    [[unlikely]] case 2: std::cout << "C"; break;
    }

    if (sw == 0) [[likely]]
    {
        std::cout << "likely if";
    }
    else [[unlikely]]
    {
        std::cout << "unlikely if";
    }

    std::cout << "\n" << "--------------------" << "\n";

}

void CPP20Test_RangeBasedLoopWithInitializer()
{

    std::cout << "C++20 RangeBasedLoopWithInitializer Test\n{";

    //Below: Both work
    //for (auto& v : { 1,2,3,4 })
    for (auto testArray = { 1,2,3,4 }; auto& v : testArray)
    {
        std::cout << v << "; ";
    }

    std::cout << "}";

    std::cout << "\n" << "--------------------" << "\n";
}


int main()
{
    CPP20Test_DesignatedInitializers();

    CPP20Test_TemplatedLambdas();

    CPP20Test_RangeBasedLoopWithInitializer();

    CPP20Test_LikelyUnlikelyAttributes();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
