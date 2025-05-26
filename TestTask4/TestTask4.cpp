#include "CppUnitTest.h"
#include "../decisionTask4/PriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityQueueTests
{
    TEST_CLASS(PriorityQueueTests)
    {
    public:

        TEST_METHOD(DefaultConstructor_CreatesEmptyQueue)
        {
            PriorityQueue queue;

            Assert::IsTrue(queue.isEmpty());
            Assert::AreEqual(size_t(0), queue.getSize());
        }

        TEST_METHOD(InitializerListConstructor_CreatesQueueWithElements)
        {
            PriorityQueue queue = { {88, 3}, {8, 1}, {8888, 5} };

            Assert::AreEqual(size_t(3), queue.getSize());
            Assert::AreEqual(8888, queue.findMax());
        }

        TEST_METHOD(Insert_AddsElementWithPriority)
        {
            PriorityQueue queue;

            queue.insert(8888, 2);
            queue.insert(8, 1);
            queue.insert(88, 3);

            Assert::AreEqual(size_t(3), queue.getSize());
            Assert::AreEqual(88, queue.findMax());
        }

        TEST_METHOD(FindMax_ReturnsHighestPriorityElement)
        {
            PriorityQueue queue = { {88, 3}, {8888, 5}, {8, 1} };

            Assert::AreEqual(8888, queue.findMax());
        }

        TEST_METHOD(ExtractMax_RemovesAndReturnsHighestPriorityElement)
        {
            PriorityQueue queue = { {88, 3}, {8888, 5}, {8, 1} };

            Assert::AreEqual(8888, queue.extractMax());
            Assert::AreEqual(size_t(2), queue.getSize());
            Assert::AreEqual(88, queue.findMax());
        }

        TEST_METHOD(IsEmpty_ReturnsTrueForEmptyQueue)
        {
            PriorityQueue queue;

            Assert::IsTrue(queue.isEmpty());
        }

        TEST_METHOD(IsEmpty_ReturnsFalseForNonEmptyQueue)
        {
            PriorityQueue queue = { {8, 1} };

            Assert::IsFalse(queue.isEmpty());
        }

        TEST_METHOD(CopyConstructor_CreatesIndependentCopy)
        {
            PriorityQueue original = { {88, 3}, {8, 1} };

            PriorityQueue copy(original);
            original.extractMax();

            Assert::AreEqual(size_t(1), original.getSize());
            Assert::AreEqual(size_t(2), copy.getSize());
            Assert::AreEqual(88, copy.findMax());
        }

        TEST_METHOD(MoveConstructor_TransfersOwnership)
        {
            PriorityQueue original = { {88, 3}, {8, 1} };

            PriorityQueue moved(std::move(original));

            Assert::AreEqual(size_t(2), moved.getSize());
            Assert::AreEqual(size_t(0), original.getSize());
            Assert::IsTrue(original.isEmpty());
        }

        TEST_METHOD(ShiftLeftOperator_InsertsElement)
        {
            PriorityQueue queue;

            queue << std::make_pair(88, 2) << std::make_pair(888, 3);

            Assert::AreEqual(size_t(2), queue.getSize());
            Assert::AreEqual(888, queue.findMax());
        }

        TEST_METHOD(ShiftRightOperator_ExtractsElement)
        {
            PriorityQueue queue = { {888, 3}, {8, 1} };
            int value = 0;

            queue >> value;

            Assert::AreEqual(888, value);
            Assert::AreEqual(size_t(1), queue.getSize());
        }

        TEST_METHOD(Clear_RemovesAllElements)
        {
            PriorityQueue queue = { {88, 3}, {8, 1} };

            queue.clear();

            Assert::AreEqual(size_t(0), queue.getSize());
            Assert::IsTrue(queue.isEmpty());
        }
    };
}