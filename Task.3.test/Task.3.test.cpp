#include "CppUnitTest.h"
#include "../Task.3.decision/Point.h"
#include "../Task.3.decision/Oval.h"
#include "../Task.3.decision/Shape.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OvalTests
{
    TEST_CLASS(PointTests)
    {
    public:
        TEST_METHOD(DefaultConstructor_CreatesZeroPoint)
        {
            Point p;
            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        TEST_METHOD(ValueConstructor_CreatesPointWithValues)
        {
            const double x = 10.5;
            const double y = 20.3;

            Point p(x, y);

            Assert::AreEqual(x, p.getX());
            Assert::AreEqual(y, p.getY());
        }

    };

    TEST_CLASS(ShapeTests)
    {
    public:
        TEST_METHOD(Draw_CallsToString)
        {
            class MockShape : public Shape {
            public:
                std::string toString() const override {
                    return "MockShape";
                }
                void readFromInput() override {}
            };

            MockShape shape;
            std::stringstream buffer;
            std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

            shape.draw();

            std::cout.rdbuf(old);

            Assert::AreEqual(std::string("MockShape\n"), buffer.str());
        }
    };

    TEST_CLASS(OvalTests)
    {
    public:
        TEST_METHOD(OvalConstructor_ValidParameters_CreatesOval)
        {
            const double maxCoord = 100.0;
            Point center(50.0, 50.0);
            double radiusX = 30;
            double radiusY = 20;

            Oval oval(center, radiusX, radiusY, maxCoord);
            std::string result = oval.toString();

            Assert::IsTrue(result.find("Овал с центром в (50, 50)") != std::string::npos);
            Assert::IsTrue(result.find("горизонтальным радиусом 30") != std::string::npos);
            Assert::IsTrue(result.find("вертикальным радиусом 20") != std::string::npos);
        }

        TEST_METHOD(OvalConstructor_ZeroRadius_ThrowsException)
        {
            const double maxCoord = 100.0;
            Point center(50.0, 50.0);

            bool exceptionThrown = false;
            try {
                Oval oval(center, 0, 20, maxCoord);
            }
            catch (...) {
                exceptionThrown = true;
            }

            Assert::IsTrue(exceptionThrown);
        }

        TEST_METHOD(OvalConstructor_ExceedsMaxCoord_ThrowsException)
        {
            const double maxCoord = 100.0;
            Point center(95.0, 95.0);

            bool exceptionThrown = false;
            try {
                Oval oval(center, 10, 10, maxCoord);
            }
            catch (...) {
                exceptionThrown = true;
            }

            Assert::IsTrue(exceptionThrown);
        }

        TEST_METHOD(ToString_ReturnsCorrectFormat)
        {
            const double maxCoord = 100.0;
            Point center(30.5, 40.5);
            double radiusX = 15;
            double radiusY = 25;

            Oval oval(center, radiusX, radiusY, maxCoord);
            std::string result = oval.toString();

            Assert::IsTrue(result.find("Овал с центром в (30.5, 40.5)") != std::string::npos);
            Assert::IsTrue(result.find("горизонтальным радиусом 15") != std::string::npos);
            Assert::IsTrue(result.find("вертикальным радиусом 25") != std::string::npos);
        }

        TEST_METHOD(ReadFromInput_CreatesValidOval)
        {
            std::stringstream input;
            input << "(30.5,40.5)\n15\n25\n";

            std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

            const double maxCoord = 100.0;
            bool exceptionThrown = false;
            try {
                Oval oval = Oval::ReadFromInput(maxCoord);
                std::string result = oval.toString();

                Assert::IsTrue(result.find("(30.5, 40.5)") != std::string::npos);
                Assert::IsTrue(result.find("15") != std::string::npos);
                Assert::IsTrue(result.find("25") != std::string::npos);
            }
            catch (...) {
                exceptionThrown = true;
            }

            std::cin.rdbuf(origCin);
            Assert::IsFalse(exceptionThrown);
        }

        TEST_METHOD(ReadFromInput_InvalidRadius_ThrowsException)
        {
            std::stringstream input;
            input << "(30.5,40.5)\n0\n25\n";

            std::streambuf* origCin = std::cin.rdbuf(input.rdbuf());

            const double maxCoord = 100.0;
            bool exceptionThrown = false;
            try {
                Oval oval = Oval::ReadFromInput(maxCoord);
            }
            catch (...) {
                exceptionThrown = true;
            }

            std::cin.rdbuf(origCin);
            Assert::IsTrue(exceptionThrown);
        }
    };
}