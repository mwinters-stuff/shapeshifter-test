
#include "worker.h"
#include <gmock/gmock.h>

using namespace ShapeShifterTest;
using testing::Eq;
namespace{

TEST(WorkerTest, factors) {
  Worker worker;


  ASSERT_THAT(worker.factors(8), Eq(4));
  ASSERT_THAT(worker.factors(9), Eq(3));
  ASSERT_THAT(worker.factors(60), Eq(12));
 
}

}
