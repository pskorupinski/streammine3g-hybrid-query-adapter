cmake_minimum_required(VERSION 2.8)

link_directories( ../build/ )

# Create the unit tests executable
add_executable(
	my_project_tests
	# Key includes for setting up Boost.Test
	TestRunner.cpp
	# Just for handy reference
	# DataSourceAdapter/MongoFilesGen.cpp
	 DataSourceAdapter/MongoDbDataSourceAdapterTest.cpp
	#  DataSourceAdapter/RealTimeDataSourceAdapterTest.cpp
)

# Link the libraries
target_link_libraries(
	my_project_tests

	# "mt" designates that multi-threaded is supported with this Boost library
	boost_unit_test_framework-mt
	boost_system-mt
	 MongoDbDataSourceAdapter SMByteArrayHeader MyGridFS
	# RealTimeDataSourceAdapter ClientSocket Socket
	protobuf SMOperatorInitParam
)
