#include <cxxtest/TestSuite.h>

#include "heap_priority_queue.h"

template class HeapPriorityQueue<int>;

class HeapTests : public CxxTest::TestSuite
{
public:
   void testTODO1( void )
   {
	   HeapPriorityQueue<int> x;
	   x.add(5);
	   
	   x.add(2);
	   
	   x.add(7);
	   
	   x.add(3);
	   
	   x.add(1);
	   
	   x.add(4);
	   
	   x.add(6);
	   
	   x.add(11);
	   
	   x.add(12);
	   
	   x.add(14);
	   
	   x.add(13);
	   
	   x.add(15);
	   
	   x.add(16);
	   
	   x.add(17);
	   
	   x.remove();
	   
	   x.remove();
	   
	   x.remove();
	   
	   x.remove();
	   
	   x.remove();
	   

	   TS_ASSERT_EQUALS(x.peek(),12);
   }  
   void testTODO2(void) {
	   HeapPriorityQueue<int> x;
	   x.add(5);

	   x.add(2);

	   x.add(7);

	   x.remove();

	   x.remove();

	   x.remove();
	   TS_ASSERT_EQUALS(x.isEmpty(), true);
   }
   void testTODO3(void) {
	   HeapPriorityQueue<int> x;
	   x.add(5);

	   x.add(2);

	   x.add(7);

	   x.add(10);

	   x.add(22);

	   x.add(45);

	   TS_ASSERT_EQUALS(x.peek(), 45);
   }
   void testTODO4(void) {
	   HeapPriorityQueue<int> x;
	   x.add(5);

	   x.add(2);

	   x.add(7);

	   x.add(10);

	   x.add(22);

	   x.add(45);

	   x.remove();

	   x.remove();

	   TS_ASSERT_EQUALS(x.peek(), 10);
   }
   void testTODO5(void) {
	   HeapPriorityQueue<int> x;
	   x.add(123);

	   x.add(34);

	   x.add(536);

	   x.add(234);

	   x.add(658);

	   x.add(44);

	   x.add(22);

	   x.add(45);

	   x.remove();

	   x.remove();

	   TS_ASSERT_EQUALS(x.peek(), 234);
   }
};
