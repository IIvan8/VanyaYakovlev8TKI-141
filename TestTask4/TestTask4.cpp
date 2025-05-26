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
            PriorityQueue queue = { {10, 3}, {20, 1}, {30, 5} };

            Assert::AreEqual(size_t(3), queue.getSize());
            Assert::AreEqual(30, queue.findMax());
        }

        TEST_METHOD(Insert_AddsElementWithPriority)
        {
            PriorityQueue queue;

            queue.insert(10, 2);
            queue.insert(20, 1);
            queue.insert(30, 3);

            Assert::AreEqual(size_t(3), queue.getSize());
            Assert::AreEqual(30, queue.findMax());
        }

        TEST_METHOD(FindMax_ReturnsHighestPriorityElement)
        {
            PriorityQueue queue = { {10, 3}, {20, 5}, {30, 1} };

            Assert::AreEqual(20, queue.findMax());
        }

        TEST_METHOD(FindMax_OnEmptyQueue_ThrowsException)
        {
            PriorityQueue queue;

            Assert::ExpectException<std::runtime_error>([&]() { queue.findMax(); });
        }

        TEST_METHOD(ExtractMax_RemovesAndReturnsHighestPriorityElement)
        {
            PriorityQueue queue = { {10, 3}, {20, 5}, {30, 1} };

            Assert::AreEqual(20, queue.extractMax());
            Assert::AreEqual(size_t(2), queue.getSize());
            Assert::AreEqual(10, queue.findMax());
        }

        TEST_METHOD(ExtractMax_OnEmptyQueue_ThrowsException)
        {
            PriorityQueue queue;

            Assert::ExpectException<std::runtime_error>([&]() { queue.extractMax(); });
        }

        TEST_METHOD(IsEmpty_ReturnsTrueForEmptyQueue)
        {
            PriorityQueue queue;

            Assert::IsTrue(queue.isEmpty());
        }

        TEST_METHOD(IsEmpty_ReturnsFalseForNonEmptyQueue)
        {
            PriorityQueue queue = { {10, 1} };

            Assert::IsFalse(queue.isEmpty());
        }

        TEST_METHOD(CopyConstructor_CreatesIndependentCopy)
        {
            PriorityQueue original = { {10, 3}, {20, 1} };

            PriorityQueue copy(original);
            original.extractMax();

            Assert::AreEqual(size_t(1), original.getSize());
            Assert::AreEqual(size_t(2), copy.getSize());
            Assert::AreEqual(10, copy.findMax());
        }

        TEST_METHOD(MoveConstructor_TransfersOwnership)
        {
            PriorityQueue original = { {10, 3}, {20, 1} };

            PriorityQueue moved(std::move(original));

            Assert::AreEqual(size_t(2), moved.getSize());
            Assert::AreEqual(size_t(0), original.getSize());
            Assert::IsTrue(original.isEmpty());
        }

        TEST_METHOD(ShiftLeftOperator_InsertsElement)
        {
            PriorityQueue queue;

            queue << std::make_pair(10, 2) << std::make_pair(20, 3);

            Assert::AreEqual(size_t(2), queue.getSize());
            Assert::AreEqual(20, queue.findMax());
        }

        TEST_METHOD(ShiftRightOperator_ExtractsElement)
        {
            PriorityQueue queue = { {10, 3}, {20, 1} };
            int value = 0;

            queue >> value;

            Assert::AreEqual(10, value);
            Assert::AreEqual(size_t(1), queue.getSize());
        }
    };
}
