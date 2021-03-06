#include "gtest.h"
#include "..\..\VS17\Queue\Queue\Queue.h"

TEST(TQueue, can_create_queue_with_positive_max_size)
{
	EXPECT_NO_THROW(TQueue <int> queue(10));
}
TEST(TQueue, throw_when_create_queue_with_negative_max_size)
{
	EXPECT_ANY_THROW(TQueue <int> queue(-10));
}
TEST(TQueue, copied_queue_is_equal_itself)
{
	TQueue <int> q1(5);
	for (int i = 1; i < 3; i++)
		q1.PushLast(i);
	TQueue <int> q2(q1);
	EXPECT_EQ(q1, q2);
}
TEST(TQueue, can_assign_queues_of_equal_size)
{
	TQueue <int> q1(5), q2(5);
	for (int i = 1; i < 3; i++)
		q1.PushLast(i);
	q2 = q1;
	EXPECT_EQ(q1, q2);
}
TEST(TQueue, can_assign_queues_of_different_size) 
{
	TQueue <int> q1(3), q2(5);
	for (int i = 1; i < 3; i++)
		q1.PushLast(i);
	q2 = q1;
	EXPECT_EQ(q1, q2);
}
TEST(TQueue, compare_queues_return_true) 
{
	TQueue <int> q1(5), q2(5);
	for (int i = 1; i < 3; i++)
		q1.PushLast(i);
	q2 = q1;
	EXPECT_EQ(true, q1==q2);
}
TEST(TQueue, compare_queues_return_false)
{
	TQueue <int> q1(3), q2(5);
	for (int i = 1; i < 3; i++)
	{
		q1.PushLast(i);
		q2.PushLast(i);
	}
	q1.PushLast(2);

	EXPECT_EQ(false, q1==q2);
}
TEST(TQueue, no_compare_queues_return_true)
{
	TQueue <int> q1(3), q2(5);
	for (int i = 1; i < 3; i++)
	{
		q1.PushLast(i);
		q2.PushLast(i);
	}
	q1.PushLast(2);

	EXPECT_EQ(true, q1 != q2);
}
TEST(TQueue, no_compare_queues_return_false) 
{
	TQueue <int> q1(5), q2(5);
	for (int i = 1; i < 3; i++)
		q1.PushLast(i);
	q2 = q1;
	EXPECT_EQ(false, q1 != q2);
}
TEST(TQueue,queue_is_full)
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++)
		q.PushLast(i);
	EXPECT_EQ(true, q.IsFull());

}
TEST(TQueue,queue_is_not_full) 
{
	TQueue<int> q(3);
	for (int i = 0; i < 2; i++)
		q.PushLast(i);
	EXPECT_EQ(false, q.IsFull());
}
TEST(TQueue,queue_is_empty) 
{
	TQueue<int> q(3);
	EXPECT_EQ(true, q.IsEmpty());
}
TEST(TQueue,queue_is_not_empty)
{
	TQueue<int> q(3);
	q.PushLast(5);
	EXPECT_EQ(false, q.IsEmpty());
}
TEST(TQueue, can_push_in_queue) 
{
	TQueue <int> q(3);
	ASSERT_NO_THROW(q.PushLast(5));
}
TEST(TQueue, cant_push_in_queue)
{
	TQueue <int> q(3);
	for (int i = 0; i < 3; i++)
		q.PushLast(i);
	ASSERT_ANY_THROW(q.PushLast(5));
}
TEST(TQueue, can_pop_in_queue) 
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++)
		q.PushLast(i);
	ASSERT_NO_THROW(q.PopFirst());
}
TEST(TQueue, cant_pop_in_queue)
{
	TQueue<int> q(3);
	ASSERT_ANY_THROW(q.PopFirst());
}
TEST(TQueue, who_is_first) 
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++)
		q.PushLast(i);
	EXPECT_EQ(0, q.WhoIsFirst());
	q.PopFirst();
	EXPECT_EQ(1, q.WhoIsFirst());
}
TEST(TQueue, throw_WhoIsFirst_if_queue_is_empty) 
{
	TQueue<int> q(3);
	EXPECT_ANY_THROW(q.WhoIsFirst());
}
TEST(TQueue, who_is_last) 
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++)
		q.PushLast(i);
	EXPECT_EQ(2, q.WhoIsLast());
	system("pause");
}