cmake_minimum_required(VERSION 3.14)

catapult_library_target(tests.catapult.test.mongo mocks)
catapult_add_mongo_dependencies(tests.catapult.test.mongo)
target_link_libraries(tests.catapult.test.mongo tests.catapult.test.core ${GTEST_LIBRARIES})
