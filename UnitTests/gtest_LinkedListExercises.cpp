#include "gtest/gtest.h"
#include "LinkedListExercises.h"
#include <math.h>

//*******************************************
// LinkedListExcercisesTestSuite
//*******************************************

/* =========== CompareLists ================*/
TEST(LinkedListExcercisesTestSuite, CompareLists)
{
    int data1[5] = { 2, 4, 6, 7, 8 };
    LinkedList<int> list1(data1, 5);

    //test identical list
    LinkedList<int> list2(data1, 5);
    EXPECT_TRUE(LinkedListExercises::CompareLists(list1, list2));
    //test identical but shorter list
    LinkedList<int> list3(data1, 4);
    EXPECT_FALSE(LinkedListExercises::CompareLists(list1, list3));
    //test diffrent list
    int data2[4] = { 1, 3, 6, 7 };
    LinkedList<int> list4(data2, 4);
    EXPECT_FALSE(LinkedListExercises::CompareLists(list1, list4));
    //test empty
    LinkedList<int> empty_list1;
    LinkedList<int> empty_list2;
    EXPECT_TRUE(LinkedListExercises::CompareLists(empty_list1, empty_list2));
}

/* =========== RemoveDuplicates ================*/
TEST(LinkedListExcercisesTestSuite, RemoveDuplicates_01)
{
    int test_data[5] = { 2, 4, 2, 7, 8 };
    LinkedList<int> test_list(test_data, 5);
    int expected_data[4] = { 2, 4, 7, 8 };
    LinkedList<int> expected_list(expected_data, 4);
    LinkedListExercises::PrintList(test_list, "test_list before");
    LinkedListExercises::RemoveDuplicates(test_list);
    LinkedListExercises::PrintList(test_list, "test_list after");
    LinkedListExercises::PrintList(expected_list, "expected_list");
    EXPECT_TRUE(LinkedListExercises::CompareLists(expected_list, test_list));

    //test empty list:
    LinkedList<int> empty_list;
    LinkedListExercises::RemoveDuplicates(empty_list);
}

TEST(LinkedListExcercisesTestSuite, RemoveDuplicates_02)
{
    int test_data[4] = { 2,2,2,2 };
    LinkedList<int> test_list(test_data, 4);
    int expected_data[1] = { 2 };
    LinkedList<int> expected_list(expected_data, 1);
    LinkedListExercises::RemoveDuplicates(test_list);
    EXPECT_TRUE(LinkedListExercises::CompareLists(expected_list, test_list));
}

TEST(LinkedListExcercisesTestSuite, RemoveDuplicates_03)
{
    LinkedList<int> test_list;
    LinkedList<int> expected_list;
    LinkedListExercises::RemoveDuplicates(test_list);
    EXPECT_TRUE(LinkedListExercises::CompareLists(expected_list, test_list));
}

TEST(LinkedListExcercisesTestSuite, RemoveDuplicates_std)
{
    std::forward_list<int> test_list1 = { 2, 5, 6, 7, 2 };
    std::forward_list<int> expected_list1 = { 2, 5, 6, 7 };
    LinkedListExercises::RemoveDuplicates2(test_list1);
    EXPECT_TRUE(test_list1==expected_list1);

    //test multiple duplicates
    std::forward_list<int> test_list2 = { 2, 2, 2, 2, 2 };
    std::forward_list<int> expected_list2 = {2};
    LinkedListExercises::RemoveDuplicates2(test_list2);
    EXPECT_TRUE(test_list2 == expected_list2);

    //empty list
    std::forward_list<int> test_list3;
    std::forward_list<int> expected_list3;
    LinkedListExercises::RemoveDuplicates2(test_list3);
    EXPECT_TRUE(test_list3 == expected_list3);
}

/* =========== AddTwoNumbers ================*/
TEST(LinkedListExcercisesTestSuite, AddTwoNumbers)
{
    //sum two numbers with same lengths
    {
        int test_data1[] = { 1, 2, 3 };
        LinkedList<int> test_list1(test_data1, 3);
        int test_data2[] = { 0, 9, 5 };
        LinkedList<int> test_list2(test_data2, 3);
        int expected[] = { 1, 1, 9 };
        LinkedList<int> expected_list(expected, 3);
        ListNode* sum1_head = LinkedListExercises::AddTwoNumbers(test_list1.mHead, test_list2.mHead);
        LinkedList<int>sum1_list(sum1_head);
        LinkedListExercises::PrintList(sum1_list, "Sum1");
        EXPECT_TRUE(LinkedListExercises::CompareLists(expected_list, sum1_list));
    }

    //sum two numbers with different lengths
    {
        int test_data1[] = { 5, 2, 9 };
        LinkedList<int> test_list1(test_data1, 3);
        int test_data2[] = { 0, 9 };
        LinkedList<int> test_list2(test_data2, 2);
        int expected[] = { 5, 1, 0, 1 };
        LinkedList<int> expected_list(expected, 4);
        ListNode* sum1_head = LinkedListExercises::AddTwoNumbers(test_list1.mHead, test_list2.mHead);
        LinkedList<int>sum1_list(sum1_head);
        LinkedListExercises::PrintList(sum1_list, "Sum1");
        EXPECT_TRUE(LinkedListExercises::CompareLists(expected_list, sum1_list));
    }
    //sum two empty;
    {
        ListNode* head1 = nullptr;
        LinkedList<int> expected_list;
        ListNode* sum1_head = LinkedListExercises::AddTwoNumbers(head1, head1);
        LinkedList<int>sum1_list(sum1_head);
        LinkedListExercises::PrintList(sum1_list, "Sum1");
        EXPECT_TRUE(LinkedListExercises::CompareLists(expected_list, sum1_list));
    }
}